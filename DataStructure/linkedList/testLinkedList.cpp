#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> a;
    a.add(19);
    a.add(11);
    a.remove();
    a.add(1);
    a.add(2);
    std::cout << a.search(1) << std::endl;
    a.display();
    

    return 0;
}