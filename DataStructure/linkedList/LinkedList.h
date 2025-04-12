#include "Node.h"
#include <iostream>
#include <sstream>

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
        Node<T>* p = head;
        while (p != nullptr) {
            if (p->getData() == target) {
                return true;
            }
            p = p->getAddr();
        }
        return false;
    }

    void display() {
        std::ostringstream out;
        
        out << "|| Linked List: (size: ";

        std::string outData;
        int size = 0;
        Node<T>* p = head;
        while (p != nullptr) {
            size ++;
            outData += std::to_string(p->getData()) + " -> ";
            p = p->getAddr();
        }
        out << size << ") | " << outData;

        std::string out_str = out.str();
        out_str = out_str.substr(0, out_str.length()-4) + " ||";

        for (int i = 0; i < out_str.length(); i++) {
            std::cout << "=";
        }
        std::cout << std::endl;

        std::cout << out_str << std::endl;
        
        for (int i = 0; i < out_str.length(); i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
    }
};

#endif