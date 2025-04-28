#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data, Node* next=nullptr, Node* prev=nullptr) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    int getData() {
        return this->data;
    }

    Node *getNext () {
        return this->next;
    }

    Node *getPrev() {
        return this->prev;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    int size;
public:
    // Constructor
    LinkedList() {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
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
        } else {
            std::cout << 0 << std::endl;
        }
    }

    void insertRight(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
        } else {
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
        } else {
            newNode->next = this->head;
            this->head = newNode;
            this->head->prev = nullptr;
        }
        size++;
    }

    void eraseRight() {
        if (isEmpty()) {
            std::cout << "Nothing to erase...";

        } else if (size == 1) {
            this->tail = nullptr;
            this->head = nullptr;
        } else {
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
        }
        size--;
    }
    void eraseLeft() {
        if (isEmpty()) {
            std::cout << "Nothing to erase...";

        } else if (size == 1) {
            this->tail = nullptr;
            this->head = nullptr;
        } else {
            this->head = this->head->next;
            this->head->prev = nullptr;
        }
        size--;
    }
};