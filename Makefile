SRC_DIR = src
OBJ_DIR = obj
INCL_DIR = include
BIN_DIR = bin

TESTS = queue
EXE-TESTS = $(addprefix $(BIN_DIR)/test-,$(TESTS))

SUBDIRSCLEAN = $(addsuffix clean, $(SRC_DIR) $(OBJ_DIR) $(BIN_DIR))

all: test-all

test-all: $(EXE-TESTS)

$(BIN_DIR)/test-%: $(OBJ_DIR)/%.o $(OBJ_DIR)/test-%.o $(OBJ_DIR)/node.o
	$(CXX) -o $@ $?

$(OBJ_DIR)/test-%.o: $(SRC_DIR)/test-%.cpp
	$(CXX) $< -I $(INCL_DIR) -c -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $< -I $(INCL_DIR) -c -o $@

clean: $(SUBDIRSCLEAN)

clean_curdir:
	rm -rfv *.o *~ core .depend .*.cmd *.ko *.mod.c

%clean: %
	$(MAKE) -C $< -f $(PWD)/Makefile clean_curdir

.PHONY: all test-all clean_curdir %clean clean
