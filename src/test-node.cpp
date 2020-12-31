#include <iostream>
#include "node.h"

using namespace std;

int main()
{
	cout << "hi";
    Node<int>* n1 = new Node<int>(7);
    Node<int>* n2 = new Node<int>(8);

    Node<int>* nb = new Node<int>(9, n1, n2);

    std::cout << n1->value << std::endl;
    std::cout << nb->left->value << std::endl;

	return 0;

}
