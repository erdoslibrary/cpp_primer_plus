#include <iostream>
#include <vector>

int countWays(int n);

int main() {
	int n;
	std::cout << "계단의 수를 입력하세요: ";
	std::cin >> n;

	int result = countWays(n);
	std::cout << "계단을 오르는 방법의 총 수: " << result << std::endl;
	return 0;
}

int countWays(int n) {
	std::vector<int> dp(n + 1);

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}