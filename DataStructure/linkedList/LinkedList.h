#include "Node.h"
#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList(): head(nullptr) { }

    ~LinkedList() {
        Node<T>* p = head;
        while (p != nullptr) {
            Node<T>* next = p->getAddr();
            std::cout << p->getData() << " is deleted\n";
            delete p;
            p = next;
        }
    }

    void add(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->setData(data);
        newNode->setAddr(nullptr);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* p = head;
            while (p->getAddr() != nullptr) {
                p = p->getAddr();
            }
            p->setAddr(newNode);
        }
    }

    void remove() {
        Node<T>* tail = head;
        while (tail->getAddr()->getAddr() != nullptr) {
            tail = tail->getAddr();
        }
        std::cout << tail->getAddr()->getData() << " is removed\n";
        delete tail->getAddr();
        tail->setAddr(nullptr);
    }

    bool search(T target) const {

    }

    void display() {
        
    }
};

#endif