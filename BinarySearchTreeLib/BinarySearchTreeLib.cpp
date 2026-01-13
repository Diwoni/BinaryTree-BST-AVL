#include <iostream>
#include <string>

#include "BinarySearchTree.h"  // 작성하신 헤더 파일

// 테스트용 함수: 검색 결과 출력
void checkKey(BinarySearchTree<int, std::string>& bst, int key) {
    std::string* result = bst.find(key);
    if (result) {
        std::cout << "[Found] Key " << key << ": " << *result << std::endl;
    } else {
        std::cout << "[Not Found] Key " << key << " does not exist." << std::endl;
    }
}

int main() {
    std::cout << "=== Binary Search Tree Demo ===\n" << std::endl;

    // 1. 생성 및 삽입 (Insert)
    std::cout << "--- 1. Insert & Size Check ---" << std::endl;
    BinarySearchTree<int, std::string> bst;

    bst.insert(50, "Root");
    bst.insert(30, "Left");
    bst.insert(70, "Right");
    bst.insert(20, "Left-Left");
    bst.insert(40, "Left-Right");
    bst.insert(60, "Right-Left");
    bst.insert(80, "Right-Right");

    // 중복 키 삽입 (값 업데이트 확인)
    bst.insert(20, "Left-Left(Updated)");

    std::cout << "Tree Size (Expected 7): " << bst.size() << std::endl;
    std::cout << "Tree Structure:\n" << bst << std::endl;

    // 2. 검색 (Find)
    std::cout << "--- 2. Search (Find) ---" << std::endl;
    checkKey(bst, 50);  // Root 찾기
    checkKey(bst, 20);  // 업데이트된 값 확인
    checkKey(bst, 99);  // 없는 값 찾기

    // 3. 복사 생성자 및 대입 연산자 테스트 (Deep Copy)
    std::cout << "\n--- 3. Copy Constructor & Assignment ---" << std::endl;
    BinarySearchTree<int, std::string> bstCopy(bst);  // 복사 생성자 호출

    std::cout << "[Original Tree] Address of Key 50: " << bst.find(50) << std::endl;
    std::cout << "[Copied Tree]   Address of Key 50: " << bstCopy.find(50) << std::endl;

    if (bst.find(50) != bstCopy.find(50)) {
        std::cout << "-> Different addresses! Deep copy success." << std::endl;
    } else {
        std::cout << "-> Same addresses! Shallow copy warning!" << std::endl;
    }

    // 4. 삭제 (Remove) - 3가지 케이스 테스트
    std::cout << "\n--- 4. Remove Operations ---" << std::endl;

    // Case 1: 자식이 없는 노드 삭제 (Leaf Node: 80)
    std::cout << "[Delete 80] (Leaf Node)" << std::endl;
    bst.remove(80);
    std::cout << bst << std::endl;

    // Case 2: 자식이 하나인 노드 삭제 (예제를 위해 30 삭제 전 구조 조정 필요할 수 있으나, 현재 트리 구조상 30은 자식이 2개임)
    // 30의 자식을 하나만 남기기 위해 20 삭제
    std::cout << "[Delete 20] (Leaf Node to make 30 have fewer children later)" << std::endl;
    bst.remove(20);

    // Case 3: 자식이 둘인 노드 삭제 (30: Left=null(20삭제됨), Right=40 -> 어라 30은 자식이 이제 하나네요)
    // 좀 더 명확한 Case 3 테스트를 위해 Root(50) 삭제 시도
    std::cout << "[Delete 50] (Root Node with 2 children)" << std::endl;
    bst.remove(50);

    std::cout << "Tree after removals:\n" << bst << std::endl;
    std::cout << "Current Size: " << bst.size() << std::endl;

    // 5. toString 확인
    std::cout << "\n--- 5. toString() Output ---" << std::endl;
    std::cout << bst.toString() << std::endl;

    std::cout << "\n=== Demo Finished ===" << std::endl;

    return 0;
}