/*
    binary_search 의사코드

    현재범위[2] = {0, 리스트 사이즈-1}
    while(true)
        if 현재범위[0] == 현재범위[1]:                            // 원소 없음
            if list[현재범위[0]] == 타겟넘버:
                return 현재범위[0]
            else: 
                return -1
        if 현재범위[0] > 현재범위[1]:
            return -1
        중간인덱스 = (현재범위[1] - 현재범위[0]) / 2 + 현재범위[0]     // 중간 인덱스 연산
        if list[중간인덱스] == 타겟넘버:                           // 중간 요소 비교
            return 중간인덱스
        else if list[중간인덱스] > 타겟 넘버:
            현재범위 = {현재범위[0], 중간인덱스-1}
        else:
            현재범위 = {중간인덱스+1, 현재범위[1]}
*/

#include <iostream>
#include <vector>

using namespace std;

int binary_search_vector(vector<int> list, int target);

int main() {
    vector<int> list1 = {3, 7, 12, 15, 18, 21, 25, 29, 33, 37, 41, 45, 49, 52, 57, 61, 66, 72, 88, 95};
    vector<int> list2 = {4, 6, 9, 13, 19, 22, 26, 30, 35, 38, 44, 47, 53, 58, 63, 67, 73, 81, 91, 99};
    vector<int> list3 = {1, 5, 8, 11, 16, 20, 24, 28, 32, 36, 40, 43, 50, 55, 60, 65, 71, 79, 85, 98};

    int target1 = 3;
    int target2 = 33;
    int target3 = 95;
    cout << "list1: " << endl;
    cout << target1 << ": " << binary_search_vector(list1, target1) << endl;
    cout << target2 << ": " << binary_search_vector(list1, target2) << endl;
    cout << target3 << ": " << binary_search_vector(list1, target3) << endl;

    cout << "list2: " << endl;
    cout << target1 << ": " << binary_search_vector(list2, target1) << endl;
    cout << target2 << ": " << binary_search_vector(list2, target2) << endl;
    cout << target3 << ": " << binary_search_vector(list2, target3) << endl;

    cout << "list3: " << endl;
    cout << target1 << ": " << binary_search_vector(list3, target1) << endl;
    cout << target2 << ": " << binary_search_vector(list3, target2) << endl;
    cout << target3 << ": " << binary_search_vector(list3, target3) << endl;







    return 0;
}

int binary_search_vector(vector<int> list, int target) {
    int current_range[2] = {0, (int)(list.size()) - 1};

    while (true) {
        if (current_range[0] == current_range[1]) {
            if (list[current_range[0]] == target)
                return current_range[0];
            else
                return -1;
        }

        if (current_range[0] > current_range[1])
            return -1;
        int mid_idx = (current_range[1] - current_range[0]) / 2 + current_range[0];

        if (list[mid_idx] == target)
            return mid_idx;
        else if (list[mid_idx] > target)
            current_range[1] = mid_idx-1;
        else
            current_range[0] = mid_idx+1;
    }
}