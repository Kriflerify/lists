#ifndef HEADER_NODE
	#define HEADER_NODE

template <class T>
class Node
{
public:
	T value;
    Node<T>* next;
    Node<T>* prev;

    Node(T val = T());
    //Node();
    Node(T val, Node* chl);
    Node(T val, Node<T>* chl, Node<T>* pred);

    ~Node();
};

#endif
