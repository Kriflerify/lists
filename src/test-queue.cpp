#include <iostream>
#include "queue.h"
#include "node.h"

using namespace std;

int main() {
    Queue<int> q = Queue<int>();

    Node<int>* a = q.insert(1);
    a = q.insert(1, a);
    a = q.insert(2, a);
	a = q.insert(3, a);
	a = q.insert(5, a);

    std::cout << "Queue: " << q << std::endl;
	q.pop(3, a);

    std::cout << "Queue: " << q << std::endl;
    std::cout << "size: " << q.getsize() << std::endl;
    return 0;
}
