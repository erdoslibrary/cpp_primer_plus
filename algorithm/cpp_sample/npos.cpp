#include <iostream>
#include <string>

using namespace std;
int main() {
	string str = "hello, c++ world";
	size_t pos1 = str.find("hello");
	cout << pos1 << endl;

	size_t pos2 = str.find("c");
	cout << pos2 << endl;

	size_t start_index = 2;
	size_t pos3 = str.find("hello", start_index);
	cout << pos3 << endl;

	size_t pos4 = str.find("python");
	cout << pos4 << endl;

	return 0;
}

// 출력값
// 0
// 7
// 18446744073709551615
// 18446744073709551615   npos 값 size_t가 표현할 수 있는 최댓value