#include <iostream>
#include <stdexcept>
#include <sstream>

class queue {
private:
    int *data;
    int capacity;
    int front;
    int rear;

public:
    queue(int data_size): front(0), rear(0) {
        data = new int[data_size];
        capacity = data_size;
    }

    ~queue() {
        delete[] data;
    }

    bool isFull() const {
        return rear == capacity;
    }

    bool isEmpty() const {
        return rear == front;
    }

    void push(int x) {
        if (isFull()) {
            std::cout << "queue is full!\n";
            return;
        } else {
            data[rear ++] = x;
        }
    }

    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        } else {
            return data[front ++];
        }
    }

    int size() {
        return rear-front;
    }

    void display() {
        std::ostringstream out;
        out << "|| Queue: (size: " << size() << ") || ";
        for (int i = 0; i < front; i++) {
            out << "-" << " | ";
        }
        for (int i = front; i < rear; i++) {
            out << data[i] << " | ";
        }
        for (int i = rear; i < capacity; i++) {
            out << "-" << " | ";
        }

        std::string str_data = out.str();
        str_data = str_data.substr(0, str_data.length()-1);
        str_data += "|";

        for (int i = 0; i < str_data.length(); i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        std::cout << str_data << std::endl;
        for (int i = 0; i < str_data.length(); i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
    }
};

int main() {
    queue q(10);
    for (int i = 0; i < 12; i ++) {
        q.push(i*10);
        q.display();
    }
    
    return 0;
}
