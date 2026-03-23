// init.cpp -- type changes on initialization
#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;     // int converted to float
    int guess(3.9832);  // double converted to int
    int debt = 7.2E12;  // result not defined in C++
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    // cin.get();
    return 0;
}

/* 출력 결과 

tree = 3.000000 (성공: 정수는 실수로 안전하게 변환됨)

guess = 3 (데이터 손실 발생)

debt = (알 수 없는 숫자) (시스템마다 다른 쓰레기 값 출력)

*/