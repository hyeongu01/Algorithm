#include <iostream>
#include <stdexcept>
#include <sstream>

template <typename T>
class Stack {
private:
    int top;
    T *data;
    int capacity;
    
    void _upsampling() {
        T *newData = new T[capacity*2];
        for (int i = 0; i < top+1; i++) {
            newData[i] = data[i];
        }
        delete[] data;

        data = newData;
        capacity *= 2;
    }

public:
    Stack(): top(-1), capacity(1) {
        data = new T[1];
    }

    ~Stack() {
        delete[] data;
    }

    bool isEmpty() const {
        return top == -1;
    }

    int size() const {
        return top + 1;
    }

    void push(T item) {
        if (top == capacity-1) {
            this->_upsampling();
        }
        data[++top] = item;
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow.");
        } else {
            top --;
        }
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow.");
        } else {
            return data[top];
        }
    }

    void display() {
        std::ostringstream out;
        out << "|| Stack: (size: " << size() << ") || ";
        for (int i = 0; i < top+1; i++) {
            out << data[i] << " | ";
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
    Stack<std::string> s;
    for (int i = 0; i < 15; i++) {
        s.push("s" + std::to_string(i));
        if (s.size() % 5 == 0)
            s.display();
    }
    
    return 0;
}

