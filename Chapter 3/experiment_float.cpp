#include <iostream>
#include <iomanip>  // 소수점 출력 정밀도 조절을 위해 필요
#include <cmath>    // std::abs() 함수를 위해 필요

int main() {
    using namespace std;

    double x = 0.1;
    double y = 0.2;
    double sum = x + y;
    double target = 0.3;

    // 1. 일반적인 출력 (기본 설정으로는 0.3처럼 보입니다)
    cout << "일반 출력: " << sum << endl;

    // 2. 정밀도를 높여서 출력 (숨겨진 오차 발견)
    // setprecision(17)을 사용하는 이유는 double의 유효 숫자가 약 15~17자리이기 때문입니다.
    cout << fixed << setprecision(20); 
    cout << "0.1의 실체: " << x << endl;
    cout << "0.2의 실체: " << y << endl;
    cout << "합계(sum) : " << sum << endl;
    cout << "대상(target): " << target << endl;

    cout << "---------------------------------------" << endl;

    // 3. 직접 비교 테스트
    if (sum == target) {
        cout << "결과: sum과 0.3은 정확히 같습니다." << endl;
    } else {
        cout << "결과: sum과 0.3은 다릅니다!" << endl;
        cout << "두 값의 차이: " << sum - target << endl;
    }

    return 0;
}