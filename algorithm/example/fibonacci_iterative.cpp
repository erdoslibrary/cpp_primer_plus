#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
	vector<int> dp(n + 1, 0);

	// 초기 조건 F(0), F(1)
	dp[0] = 0;
	if (n > 0) {
		dp[1] = 1;
	}

	for (int i = 2; i <= n; ++i ) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main() {
	int n = 5;
	cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

	n = 10;
	cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
	// return 0;
}