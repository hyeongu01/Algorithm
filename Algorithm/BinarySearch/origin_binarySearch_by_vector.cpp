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

    return 0;
}

int binary_search_vector(vector<int> list, int target) {


    return 0;
}