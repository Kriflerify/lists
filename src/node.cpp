#include <iostream>
#include "node.h"

template <class T>
Node<T>::Node(T val)
{
    value = val;
    next = NULL;
}

template <class T>
Node<T>::Node(T val, Node<T>* chl)
{
    value = val;
    next = chl;
    chl->prev = this;
}

template <class T>
Node<T>::Node(T val, Node<T>* chl, Node<T>* pred)
{
    value = val;
    next = chl;
//    chl->prev = this;
    prev = pred;
//    pred->next = this;
}


template <class T>
Node<T>::~Node()
{
}

template class Node<int>;
