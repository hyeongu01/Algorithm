#include <iostream>
#include <stdexcept>
#include <sstream>


template <typename T>
class queue {
private:
    T *data;
    int capacity;
    int front;
    int back;

    void upscaling() {
        capacity *= 2;
        T *newData = new T[capacity];
        for (int i = 0; i < size(); i ++) {
            newData[i] = data[front + 1 + i];
        }
        back = size() - 1;
        front = -1;
        delete[] data;
        data = newData;
    }

public:
    queue(): capacity(1), front(-1), back(-1) {
        data = new T[capacity];
    }

    ~queue() {
        delete[] data;
    }

    int size() const {
        return back-front;
    }

    bool isFull() const {
        return (back == capacity - 1 ? true : false);
    }

    bool isEmpty() const {
        return (back == front ? true : false);
    }

    void enqueue(T x) {
        if (isFull()) {
            upscaling();
            data[++ back] = x;
        } else {
            data[++ back] = x;
        }
    } 

    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("queue underflow.");
        } else {
            front ++;
        }
    }

    T fonrt() const {
        return data[this->front + 1];
    }

    void display() const {
        std::ostringstream out;
        out << "|| Queue: (size: " << size() << ") || ";
        for (int i = 0; i < size(); i++) {
            out << data[front + i + 1] << " | ";
        }
        
        std::string str_data = out.str();
        str_data = str_data.substr(0, str_data.length()-3);
        str_data += " ||";

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
    queue<int> q;
    for (int i = 1; i < 10; i++) {
        q.enqueue(i);
        q.display();
    }
    for (int i = 1; i < 10; i++) {
        q.dequeue();
        q.display();
    }
    

    return 0;
}