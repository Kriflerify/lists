#ifndef HEADER_LISTQUEUE
    #define HEADER_LISTQUEUE


#include <vector>
#include "node.h"

class Listqueue {
public:
    std::vector<Node<int>*> nodes;

    Node<int>* root;
    Node<int>* tail;

    Listqueue();
    Listqueue(std::vector<int>& vals);
    ~Listqueue();

    Node<int>*& operator[](int val);

    void rotate();

    Node<int>* append(int val);
    Node<int>* insert(std::vector<int>& vals);
    
};

std::ostream& operator<<(std::ostream&, const Listqueue&);

#endif
