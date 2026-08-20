#include <iostream>

int main() {
    // 기본 데이터 타입의 크기 출력
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "Size of long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "Size of long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;

    // 포인터 타입의 크기 출력
    int* ptr = nullptr;
    std::cout << "Size of pointer: " << sizeof(ptr) << " bytes" << std::endl;

    // 사용자 정의 데이터 타입(구조체)의 크기 출력
    struct MyStruct {
        int i; // 4
        double d; // 8
        char c; // 1
    };
    // 13byte가 아니라, 24byte로 나오는건 padding때문이다.
    // 4 (int) + 4 (패딩) + 8 (double) + 1 (char) + 7 (패딩) = 24 bytes
    // 진짜 크기 최적화가 되나?

    // 방법 1: 큰 크기부터 배치
    struct OptimizedStruct1 {
        double d;   // 8 bytes (offset 0~7)
        int i;      // 4 bytes (offset 8~11)
        char c;     // 1 byte  (offset 12)
        // [Padding 3 bytes]   (offset 13~15) -> 전체 8의 배수 맞춤
    };
    // 방법 2: 작은 것들을 묶어서 배치
    struct OptimizedStruct2 {
        char c;     // 1 byte  (offset 0)
        int i;      // 4 bytes (offset 1~4)
        // [Padding 3 bytes]   (offset 5~7)
        double d;   // 8 bytes (offset 8~15) -> 16바이트 맞춰짐
    };
    std::cout << "Size of MyStruct: " << sizeof(MyStruct) << " bytes" << std::endl;
    std::cout << "Size of OptimizedStruct1: " << sizeof(OptimizedStruct1) << " bytes" << std::endl;
    std::cout << "Size of OptimizedStruct2: " << sizeof(OptimizedStruct2) << " bytes" << std::endl;
    
    // 주석으로 변수 타입과 크기를 테이블 형식으로 정리
    /*
    | Variable Type | Size in 32-bit (bytes) | Size in 64-bit (bytes) |
    |---------------|------------------------|------------------------|
    | int           | 4                      | 4                      |
    | short         | 2                      | 2                      |
    | long          | 4                      | 8                      |
    | long long     | 8                      | 8                      |
    | float         | 4                      | 4                      |
    | double        | 8                      | 8                      |
    | char          | 1                      | 1                      |
    | bool          | 1                      | 1                      |
    | pointer       | 4                      | 8                      |
    | MyStruct      | 12                     | 16                     |
    * Mystruct가 12, 16 바이트가 나오는 건 멤버가 최적화되어 배치되었을 때의 크기다.
    */
    return 0;
}