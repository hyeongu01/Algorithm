/*
    ## binary_search 의사코드

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
#include <algorithm>    // std::sort()
#include <random>

using namespace std;

class RandomList {
private:
    int *list;
    size_t list_size = 0;

public:
    RandomList(int size, int max_number);
    ~RandomList();

    int at(int index);
    size_t size();
    void print();

    // 존재하지 않으면 -1, 존재하면 해당 인덱스 반환
    int binary_search(const int& target);
};

int main() {
    RandomList list(50, 60);

    list.print();

    int target;

    target = 27;
    cout << target << ": " << list.binary_search(target) << endl;

    target = 15;
    cout << target << ": " << list.binary_search(target) << endl;

    target = 60;
    cout << target << ": " << list.binary_search(target) << endl;

    target = 5;
    cout << target << ": " << list.binary_search(target) << endl;

    
    return 0;
}

int RandomList::binary_search(const int& target) {
    int current_range[2] = {0, (int)(size() - 1)};
    while(true) {
        if (current_range[0] == current_range[1])
            return (list[current_range[0]] == target ? current_range[0] : -1);
        if (current_range[0] > current_range[1])
            return -1;
        int mid_idx = (current_range[1] - current_range[0]) / 2 + current_range[0];

        // cout << mid_idx << ": " << list[mid_idx] << endl;
        if (list[mid_idx] == target)
            return mid_idx;
        else if (list[mid_idx] > target)
            current_range[1] = mid_idx - 1;
        else
            current_range[0] = mid_idx+1;
    }
}

RandomList::RandomList(int size, int max_number) {
    this->list = new int[size];
    this->list_size += size;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, max_number);

    for (int i = 0; i < size; i ++) {
        list[i] = dist(gen);
    }
    sort(list, list+size);
}

RandomList::~RandomList() {
    this->list_size = 0;
    delete[] this->list;
}

int RandomList::at(int index) {
    return this->list[index];
}

size_t RandomList::size() {
    return this->list_size;
}

void RandomList::print() {
    cout << "list: { ";
    for (int i = 0; i < this->list_size; i ++) {
        cout << this->list[i] << ' ';
    }
    cout << "}" << endl;
}