#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;

    std::cout << "=== 연결 리스트 테스트 시작 ===\n\n";

    // 요소 추가 테스트
    std::cout << "[추가 테스트] 10, 20, 30 추가\n";
    list.add(10);
    list.add(20);
    list.add(30);
    list.display();

    // 탐색 테스트
    std::cout << "\n[탐색 테스트] 20 찾기 → ";
    std::cout << (list.search(20) ? "찾았습니다!" : "없습니다.") << "\n";

    std::cout << "[탐색 테스트] 40 찾기 → ";
    std::cout << (list.search(40) ? "찾았습니다!" : "없습니다.") << "\n";

    // 삭제 테스트
    std::cout << "\n[삭제 테스트] 마지막 노드 제거\n";
    list.remove(); // 30 제거
    list.display();

    std::cout << "\n[삭제 테스트] 또 제거\n";
    list.remove(); // 20 제거
    list.display();

    std::cout << "\n[삭제 테스트] 또 제거\n";
    list.remove(); // 10 제거
    list.display();

    // 빈 리스트에서 삭제 시도 (보완 필요 여부 테스트)
    std::cout << "\n[삭제 테스트] 빈 리스트에서 제거 시도\n";
    list.remove(); // 아무것도 없을 때

    // 다시 추가
    std::cout << "\n[추가 테스트] 99 추가\n";
    list.add(99);
    list.display();

    std::cout << "\n=== 연결 리스트 테스트 종료 ===\n";

    return 0;
}
