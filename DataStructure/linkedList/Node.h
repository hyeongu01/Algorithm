#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node<T>* addr;

public:
    T getData() const {
        return data;
    }

    Node<T>* getAddr() const {
        return addr;
    }

    void setData(T data) {
        this->data = data;
    }

    void setAddr(Node<T>* addr) {
        this->addr = addr;
    }
};

#endif