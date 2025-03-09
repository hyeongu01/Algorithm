#include <vector>
#include <iostream>

using namespace std;

// finding x in array, return index of x (if x is not in the array, return -1)
int linearSearch(vector<int> array, int target);

int main() {
    vector<int> array = {2, 5, 3, 7, 9, 1, 6, 4, 0, 8};
    int target;

    for (auto element: array)
        cout << element << ' ';
    cout << endl << "----------------------------------\n";

    target = 3;
    cout << target << " is in the array[" << linearSearch(array, target) << "]" << endl;

    target = 6;
    cout << target << " is in the array[" << linearSearch(array, target) << "]" << endl;

    target = 8;
    cout << target << " is in the array[" << linearSearch(array, target) << "]" << endl;

    target = 10;
    cout << target << " is in the array[" << linearSearch(array, target) << "]" << endl;

    return 0;
}

int linearSearch(vector<int> array, int target) {
    for (int i = 0; i < array.size(); i ++) {
        if (array[i] == target)
            return i;
    }
    return -1;
}