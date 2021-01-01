#include <iostream>
#include "queue.h"
#include "node.h"

using namespace std;

int main() {
    // TESTING INSERT AND POP
    cout << "TESTING QUEUE (insert and pop)" << endl;
    Queue<int> q;
    Queue<int>* qp = &q;
    

    Node<int>* a = q.insert(1);
    cout << q << endl;
    a = q.insert(1, a);
    a = q.insert(2, a);
	a = q.insert(3, a);
	q.insert(5, a);

    std::cout << "Queue: " << q << std::endl;
	q.pop(3, a);

    std::cout << "Queue: " << q << std::endl;
    std::cout << "size: " << q.getsize() << std::endl;

    
    // TESTING LIST INSERT
    cout << "TESTING QUEUE (inserting list)" << endl;
    q = Queue<int>();
    int list [5] = {1,2,3,4,5};

    Node<int>* b = q.insert(1);
    b = q.insert(list, 5);
    cout << "Queue: " << q << endl;
    std::cout << "size: " << q.getsize() << std::endl;

    // TESTING ROOT REMOVAL
    cout << "TESTING QUEUE (Removing the root)" << endl;
    q = Queue<int>();

    a = q.insert(list, 5);
    cout << q << endl;
    q.pop(1);

    
    cout << "Queue: " << q << endl;
    cout << "Root: " << q.getroot()->value << endl;
    std::cout << "size: " << q.getsize() << std::endl;

    
    
    return 0;
}
