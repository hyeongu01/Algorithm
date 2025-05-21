#include <iostream>

template <typename T>
struct Node {
    Node* left;
    Node* right;
    T data;
    Node(int value): data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class bst {
private:
    Node<T>* root;
    void delete_node(Node<T>* node) {
        if (node != nullptr) {
            delete_node(node->left);
            delete_node(node->right);
            delete node;
        }
    }

public:
    bst(): root(nullptr) {}
    
    ~bst() {
        delete_node(root);
    }

    void insert_node(T value) {
        if (root == nullptr) {
            Node<T>* newNode = new Node<T>(value);
        } else {
            
        }
    }
};

int main() {
    
    bst<int> tree;
    tree.insert_node(10);
    return 0;
}