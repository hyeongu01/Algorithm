#include <iostream>
#include <stdexcept>
#include <string>

class Stack {
private:
    int *data;
    int top;
    int capacity;

public:
    Stack(int capacity): capacity(capacity), top(-1) {
        data = new int[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    bool push(int item) {
        if (isFull()) {

            return false;
        } else {
            data[++top] = item;
            return true;
        }
    }

    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow");
        }
        return data[top--];
    }

    int peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack underflow");
        }
        return data[top];
    }

    void display() const {
        std::string out_str = "Stack (size=";
        out_str += std::to_string(top+1) + ") || ";

        for (int i = 0; i < top+1; i++) 
            out_str += std::to_string(data[i]) + " | ";
        out_str = out_str.substr(0, out_str.size() - 3);

        out_str.insert(0, 1, ' ');
        out_str.insert(0, 2, '|');
        out_str += " ||";

        for (int i = 0; i < out_str.size(); i++) {
            std::cout << "=";
        }

        std::cout << std::endl;
        std::cout << out_str << std::endl;

        for (int i = 0; i < out_str.size(); i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
    }

    int size() const {
        return this->top+1;
    }
};

int main() {
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(5);
    s.display();

    s.pop();
    s.display();
    s.pop();
    s.display();
    
    return 0;
}

