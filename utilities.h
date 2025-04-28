#pragma once
#include <iostream>
#include <iomanip>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data, Node* next = nullptr, Node* prev = nullptr) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    int getData() {
        return this->data;
    }

    Node* getNext() {
        return this->next;
    }

    Node* getPrev() {
        return this->prev;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    // Constructor
    LinkedList() {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    Node* getHead() {
        return this->head;
    }

    Node* getTail() {
        return this->tail;
    }

    int getHeadData() {
        return this->head->getData();
    }

    int getTailData() {
        return this->tail->getData();
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return this->size;
    }

    void display() {
        Node* current = this->head;
        if (!isEmpty()) {
            while (current != nullptr) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << std::endl;
        }
        else {
            std::cout << 0 << std::endl;
        }
    }

    void insertRight(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            newNode->prev = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        }
        size++;
    }

    void insertLeft(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            newNode->next = this->head;
            this->head = newNode;
            this->head->prev = nullptr;
        }
        size++;
    }

    void eraseRight() {
        if (isEmpty()) {
            std::cout << "Nothing to erase...";

        }
        else if (size == 1) {
            this->tail = nullptr;
            this->head = nullptr;
        }
        else {
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
        }
        size--;
    }
    void eraseLeft() {
        if (isEmpty()) {
            std::cout << "Nothing to erase...";

        }
        else if (size == 1) {
            this->tail = nullptr;
            this->head = nullptr;
        }
        else {
            this->head = this->head->next;
            this->head->prev = nullptr;
        }
        size--;
    }
};


class Stack {
public:
    LinkedList list;
    const int STACK_LIMIT = 10e6;
    int stackSize = 0;

    void push(int data) {
        if ((stackSize + 1) <= STACK_LIMIT) {
            list.insertRight(data);
            stackSize = list.getSize();
        } else {
            std::cout << "Stack limit exceeded. " << std::endl;
        }
    }

    int top() {
        if (!list.isEmpty())
            return list.getTailData();
        else
            return 0;
    }

    void pop() {
        list.eraseRight();
        stackSize = list.getSize();
    }

    bool isEmpty() {
        return stackSize == 0;
    }

    bool isFull() {
        return stackSize == STACK_LIMIT;
    }

    void display() {
        Node* current = list.getTail();
        const int WIDTH = 10;

        while (current != nullptr) {
            std::cout << "|" << std::setw(WIDTH) << current->data << std::setw(WIDTH-1) << "|" << std::endl;
            current = current->prev;
        }
    }
};

class Queue {
public:
    LinkedList list;
    const int QUEUE_LIMIT = 10e6;
    int queueSize = 0;

    void enqueue(int data) {
        if ((queueSize + 1) <= QUEUE_LIMIT) {
            list.insertRight(data);
            queueSize = list.getSize();
        }
        else {
            std::cout << "Queue limit exceeded. " << std::endl;
        }
    }

    void dequeue(int data) {
        list.eraseLeft();
        queueSize = list.getSize();
    }

    int getFront() {
        return list.getHeadData();
    }

    int getRear() {
        return list.getTailData();
    }

    bool isFull() {
        return queueSize == QUEUE_LIMIT;
    }

    bool isEmpty() {
        return queueSize == 0;
    }
};
