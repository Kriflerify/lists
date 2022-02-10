SRC_DIR = src
OBJ_DIR = obj
INCL_DIR = include
BIN_DIR = bin

STD = c++17

TESTS = listqueue
EXE-TESTS = $(addprefix $(BIN_DIR)/test-,$(TESTS))

SUBDIRSCLEAN = $(addsuffix clean, $(SRC_DIR) $(OBJ_DIR) $(BIN_DIR))

all: crab

crab: $(OBJ_DIR)/crab.o $(OBJ_DIR)/queue.o $(OBJ_DIR)/node.o
	$(CXX) -std=$(STD) -o $@ $^

test-all: $(EXE-TESTS)
	$(BIN_DIR)/test-listqueue

$(BIN_DIR)/test-%: $(OBJ_DIR)/%.o $(OBJ_DIR)/test-%.o $(OBJ_DIR)/node.o
	$(CXX) -std=c++17 -o $@ $^

$(OBJ_DIR)/test-%.o: $(SRC_DIR)/test-%.cpp
	$(CXX) -std=c++17 $< -I $(INCL_DIR) -c -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -std=c++17 $< -I $(INCL_DIR) -c -o $@

clean: $(SUBDIRSCLEAN)

clean_curdir:
	rm -rfv *.o *~ core .depend .*.cmd *.ko *.mod.c

%clean: %
	$(MAKE) -C $< -f $(PWD)/Makefile clean_curdir

.PHONY: all test-all clean_curdir %clean clean
