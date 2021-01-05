#include <iostream>
#include "listqueue.h"

Listqueue::Listqueue() {
    nodes = std::vector<Node<int>*>();
    root = NULL;
    tail = NULL;
}

Listqueue::~Listqueue() {
    Node<int>* cur = root;
    Node<int>* next = root;
    for (int i=1; i<nodes.size(); i++) {
        next = cur->next;
            delete cur;
        cur = next;
    }
    delete cur;
}


Node<int>*& Listqueue::operator[](int val) {
    return nodes[val];    
}


void Listqueue::rotate(){
    tail = root;
    root = root->next;
}

Node<int>* Listqueue::append(int val){
    if (val > nodes.size()) {
        nodes.resize(val);
    }

    if (root == nullptr) {
        root = new Node<int>*(val);
        root->next = root;
        tail = root;
    } else {
        tail
    return NULL;
}


std::ostream& operator<<(std::ostream& os, const Listqueue& l) {
    Node<int>* cur = l.root;
    for (int i=1; i<l.nodes.size(); i++) {
        std::cout << l.nodes.size() << std::endl;
        os << cur << ", ";
        cur = cur->next;
    }
    os << cur << ", ";
    return os;
}
