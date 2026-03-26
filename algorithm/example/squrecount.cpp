#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ROW = 3;
const int COL = 4;

int countSqures();

int main() {
	int result = countSqures();
	cout << "만들 수 있는 정사각형의 총 개수: " << result << endl;
	return 0;
}

int countSqures() {
	vector<vector<int>> dp(ROW, vector<int>(COL, 1));

	for (int i = 1; i < ROW; ++i) {
		for (int j = 1; j < COL; ++j) {
			dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
		}
	}
	int totalSquares = 0;
	for( int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			totalSquares += dp[i][j];
		}
	}
	return totalSquares;
}