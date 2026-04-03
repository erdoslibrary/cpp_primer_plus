#include <iostream>

using namespace std;

int main()
{
	long double ld = 3.14L;
	double d = 3.14;
	float f = 3.14;

	cout << "long double size: " << sizeof(ld) << "\n";
	cout << "double size: " << sizeof(d) << "\n";
	cout << "float size: " << sizeof(f) << endl;
	return 0;
}

/* 출력 결과
long double size: 16 오호
double size: 8
float size: 4
*/