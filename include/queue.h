#ifndef HEADER_HEAP
	#define HEADER_HEAP
#include "node.h"
#include <ostream>


template <typename T>
class Queue
{
private:
    Node<T>* root;
    int size;

public:
	Queue();
	~Queue();

    int getsize() const;
    Node<T>* getroot() const;
	Node<T>* insert(T val);
	Node<T>* insert(T val, Node<T>* index);
	void remove(Node<T>* index);
    Node<T>* find(T val);
    Node<T>* find(T val, Node<T>* start);
    bool pop(T val);
    bool pop(T val, Node<T>* start);
};


template<typename T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);



#endif
