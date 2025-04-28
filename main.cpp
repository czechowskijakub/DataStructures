<<<<<<< HEAD
#include <iostream>
#include "utilities.h"
#include <chrono>

int main() {
    int add;
    auto start = std::chrono::high_resolution_clock::now();

    // LinkedList list = LinkedList();
    
    // Initializing a stack
    Stack stacky;

    // pushing i-number of ints to test the stacksize
    for (int i = 1; i <= 10; i++) {
        stacky.push(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Stack's top element: " << stacky.top() << std::endl;
    std::cout << "Time duration of pushing " << stacky.stackSize << " integers onto the stack: " 
              << elapsed.count() << " seconds. " << std::endl;

    std::cout << "Try to push an int: " << std::endl;
    std::cin >> add;

    stacky.push(add);
    stacky.display();
    std::cout << "Checking if the stack is full: " << stacky.isFull() << std::endl;

    return 0;
=======
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
>>>>>>> d2e3841134cb1defd9e103e029e7f87d96285655
}