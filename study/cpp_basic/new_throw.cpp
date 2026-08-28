#include <iostream>
#include <new> // std::bad_alloc std::nothrow
#include <cstdlib>

int main() {
    // new 실패 시 std::bad_alloc 예외 던짐
    try {
        int *modern_ptr = new int [10000000000000ULL];
        std::cout << "메모리 할당 성공" << std::endl;
        delete[] modern_ptr;
    } catch (const std::bad_alloc& e) {
        std::cerr << "표준 New 실패 (예외): " << e.what() << std::endl;
    }

    // new 실패 시 NULL을 반환하도록 지정(비추천)
    int *legacy_ptr = new(std::nothrow) int[10000000000000ULL];

    if (legacy_ptr == NULL) {
        std::cerr << "nothrow new 실패 (널 포인터 반환)" << std::endl;
    } else {
        delete[] legacy_ptr;
    }
    return 0;
}