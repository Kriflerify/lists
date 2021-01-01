#include "queue.h"
#include <cstddef>
#include <iostream>

template <typename T>
Queue<T>::Queue() {
    Node<T>* root = NULL;
    size = 0;
}


template <typename T>
Queue<T>::~Queue() {
    Node<T>* nextdel = root;
    Node<T>* curdel = root;
    for (int i=size; i>0; i--) {
        nextdel = nextdel->next;
        delete curdel;
        curdel = nextdel;
    }
}


template <typename T>
Node<T>* Queue<T>::find(T val) {
    return find(val, root);    
}


template <typename T>
Node<T>* Queue<T>::find(T val, Node<T>* start) {
    Node<T>* forp = start;
    Node<T>* backp = start;
    for (int i=0; i<(size+1)/2; i++) {
        if (forp->value == val) {
            return forp;
        } else if (backp->value == val) {
            return backp;
        }
        forp = forp->next;
        backp = backp->prev;
    }
    return NULL;
}

template <typename T>
Node<T>* Queue<T>::insert(T val) {
	return insert(val, root);
}


template <typename T>
Node<T>* Queue<T>::insert(T val, Node<T>* index) {
	Node<T>* ret;
    if (size==0) {
        root = new Node<T>(val, root, root);
        root->next = root;
        root->prev = root;
        size++;
        return root;
    } else {
        Node<T>* newnode = new Node<T>(val, index->next, index);
        index->next->prev = newnode;
        index->next = newnode;
        size++;
        return newnode;
    }
}


template <typename T>
Node<T>* Queue<T>::insert(T* val, int len) {
	return insert(val, len, root);
}


template <typename T>
Node<T>* Queue<T>::insert(T* val, int len,  Node<T>* index) {
    Node<T>* a = index;
    T* v = val;
    for (int i=0; i<len; i++) {
        a = insert(v[i], a);
    }

    return a;
}

template <typename T>
void Queue<T>::remove(Node<T>* index) {
    index->prev->next = index->next;
    index->next->prev = index->prev;
    if (index == root) {
        root = index->next;
    }
    delete index;
    size--;
}


template <typename T>
bool Queue<T>::pop(T val) {
	return pop(val, root);
}   


template <typename T>
bool Queue<T>::pop(T val, Node<T>* start) {
    Node<T>* targetnode = find(val, start);
    
    if (targetnode==NULL)
        return false;
    else
        remove(targetnode);
        return true;
}   

template <typename T>
int Queue<T>::getsize() const {
    return size;
}


template <typename T>
Node<T>* Queue<T>::getroot() const {
    return root;
}


template<typename T>
std::ostream& operator<<(std::ostream &os, Queue<T> const &q) { 
       
    Node<T>* cur = q.getroot();
    
    for (int i=0; i<q.getsize(); i++) {
        os  << cur->value;
        cur = cur->next;
    }

	return os;
}

template class Queue<int>;
template std::ostream& operator<<(std::ostream&, const Queue<int>&);
