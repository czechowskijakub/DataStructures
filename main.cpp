#include <iostream>
#include "utilities.h"

int main() {
    
    LinkedList list = LinkedList();
    list.insertRight(10);
    list.insertRight(20);
    list.insertLeft(-10);
    list.display();
    list.eraseLeft();
    list.eraseRight();
    list.display();
    std::cout << std::endl << list.getSize();
    return 0;
}