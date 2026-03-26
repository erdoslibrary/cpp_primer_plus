#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ROW = 3;
const int COL = 4;

int countSqures();

// int main() {
// 	int result = countSqures();
// 	cout << "만들 수 있는 정사각형의 총 개수: " << result << endl;
// 	return 0;
// }

/* 나는 매크로처럼 정의하지 않고 실행파일 인자로 받고 싶다. */
int main(int argc, char **argv) {
	if (argc < 3) {
		cout << "사용법: " << argv[0] << " [ROW][COL]" << endl;
		cout << "예시: " << argv[0] << " 3 4" << endl;
		return 1;
	}
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);

	int result = countSqures();
	cout << "입력: " << row << " x " << col << endl;
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