// fltadd.cpp -- precision problems with float
#include <iostream>
#include <iomanip>

// int main()
// {
//     using namespace std;
//     float a = 2.34E+22f;
//     float b = a + 1.0f;

//     cout << "a = " << a << endl;
//     cout << "b - a = " << b - a << endl;
//     // cin.get();
//     return 0; 
// }

int main()
{
	using namespace std;

	double a = 2.34E+22;
	double b = a + 1.0;
	
	cout << fixed << setprecision(1);
	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;
}
/* 결국 double도 0이 나오는데, 이는 a 가 2.34 * 10 ^ 22로 엄청 거대한 수이기 때문이다.
float은 32비트에 숫자를 저장한다.(부호 1, 지수 8비트, 가수부 23비트 )
double은 64비트(부호 1, 지수 11비트, 가수부 52비트)


*/