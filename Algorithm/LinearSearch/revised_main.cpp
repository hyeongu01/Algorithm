#include <vector>
#include <iostream>

using namespace std;

// finding x in array, return index of x (if x is not in the array, return -1)
int linearSearch(const vector<int>& array, int target);

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

int linearSearch(const vector<int>& array, int target) {
    for (int i = 0; i < array.size(); i ++) {
        if (array[i] == target)
            return i;
    }
    return -1;
}

/*
# 수정사항
     - line(7, 32). linearSearch()의 인수로 vector<int>를 복사하여 받는데, 
         - &(참조)를 활용해 메모리를 아낄 수 있다. 
        - 함수 내에서 변경을 하지 못하도록 하기 위해 const 형으로 바꾸기까지!
     - line(33). size() 한수의 반환값은 size_t 형태이다. int -> size_t로 변경하여 표준 라이브러리와의 일관성 획득!

     - std::find()와 std::distance()를 활용한 더 간결한 표현
*/
#include <algorithm>

int linearSearch_ver2(const vector<int>& array, int target) {
    auto it = find(array.begin(), array.end(), target);
    return (it != array.end() ? distance(array.begin(), it) : -1);
}