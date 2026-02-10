/* 오랜만에 출력해볼까 */

#include <iostream>
#include <cstdint> // 고정 크기 타입 사용을 위한 헤더

int main() {
    using namespace std;

    cout << "--- 내 시스템의 타입별 용량 (Bytes) ---" << endl;
    cout << "char      : " << sizeof(char) << endl;
    cout << "int       : " << sizeof(int) << endl;
    cout << "long      : " << sizeof(long) << " (OS에 따라 다를 수 있음)" << endl;
    cout << "long long : " << sizeof(long long) << endl;
    cout << "float     : " << sizeof(float) << endl;
    cout << "double    : " << sizeof(double) << endl;
    cout << "pointer   : " << sizeof(void*) << " (4=32bit, 8=64bit)" << endl;

    // 실무 팁: 크기가 명확해야 할 때는 고정 크기 타입을 사용하세요.
    int32_t fixedInt = 10; // 어떤 환경에서도 4바이트 보장
    int64_t fixedLong = 10; // 어떤 환경에서도 8바이트 보장

   return 0;
}