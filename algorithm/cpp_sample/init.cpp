#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1;
	string str2 = "hello, world!";
	string str3(str2);
	string str4(str2, 0, 5);
	string str5(10, '*');

	string strings[] = {str1, str2, str3, str4, str5};
	for (int i = 0; i < 5; ++i) {
		cout << "str" << i + 1 << ": " << strings[i] << endl;
	}
	return 0;
}