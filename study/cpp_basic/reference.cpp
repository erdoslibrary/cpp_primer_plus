#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    // ref는 a를 참조 (초기 바인딩)
    int& ref = a;

    std::cout << "================ [1. 초기 상태] ================\n";
    std::cout << "a   의 값: " << a << " \t| 주소: " << &a << "\n";
    std::cout << "b   의 값: " << b << " \t| 주소: " << &b << "\n";
    std::cout << "ref 의 값: " << ref << " \t| 주소: " << &ref << std::endl;

    std::cout << "\n================ [2. ref = b 실행] ================\n";
    // 레퍼런스 재할당 시도(?) -> 사실은 a의 메모리에 b의 값을 덮어쓰는 Mutation
    ref = b;

    std::cout << "a   의 값: " << a << " \t| 주소: " << &a << "\n";
    std::cout << "b   의 값: " << b << " \t| 주소: " << &b << "\n";
    std::cout << "ref 의 값: " << ref << " \t| 주소: " << &ref << std::endl;

    std::cout << "\n================ [3. 검증 결과] ================\n";
    std::cout << "1. Re-binding 여부: &ref == &b 인가? " 
              << ((&ref == &b) ? "예 (재할당됨)" : "아니오 (&ref는 여전히 &a와 동일!)") << "\n";
    std::cout << "2. Mutation 여부  : a의 값이 바뀌었는가? " 
              << ((a == 20) ? "예 (a의 값 10 -> 20으로 덮어씌워짐)" : "아니오") << std::endl;

    return 0;
}
