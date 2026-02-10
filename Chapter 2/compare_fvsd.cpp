/* float vs double 실험*/

#include <iomanip> // 출력 정밀도 조절을 위한 헤더
#include <iostream>

int main() {
    using namespace std;

    // 1. 동일한 값을 소수점 아래 길게 정의
    float  floatNum  = 1.1234567890123456789f;
    double doubleNum = 1.1234567890123456789;

    // 소수점 20자리까지 출력 설정
    cout << setprecision(20);

    cout << "Original:   1.1234567890123456789" << endl;
    cout << "float:      " << floatNum << " (약 7자리 이후 오차 발생)" << endl;
    cout << "double:     " << doubleNum << " (약 15자리 이후 오차 발생)" << endl;

    // 2. 누적 오차 테스트
    float sum = 0.0f;
    for (int i = 0; i < 100; ++i) {
        sum += 0.1f;
    }
    cout << "\n0.1을 100번 더한 결과 (float): " << sum << " (정확히 10.0이 아님)" << endl;

    return 0;
}