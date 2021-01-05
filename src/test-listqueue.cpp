#include <iostream>
#include "listqueue.h"

using namespace std;

int main() {

    //Testing Konstruktors
    Listqueue l = *(new Listqueue());

    l.append(3);

    Node<int>* a = new Node<int>(3);
    cout << "jojojo?" << endl;
    cout << l << endl;
    cout << "jojojo?" << endl;
    delete &l;
    
    cout << "jajaja?" << endl;
    cout << a->value << endl;
    return 0;
}
