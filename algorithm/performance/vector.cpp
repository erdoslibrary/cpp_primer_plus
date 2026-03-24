#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// chrono, auto는 c++11 부터 가능하다.!

//데이터가 이미 존재하는 vector와 set에서 원소를 찾는 시간 비교

// std::vector는 동적 배열을 기반으로 하며, 원소 검색에 O(n)의 시간이 소요된다.
// std::set은 레드-블랙 트리(Red-Black Tree)를 기반으로 하는 균형 이진 검색 트리로, 
// 검색에 O(log n)의 시간이 소요된다.

// 성능 차이의 주된 이유는 다음과 같다:
// - vector는 선형 검색을 수행하기 때문에 원소의 수에 비례하는 시간이 소요된다.
// - set은 이진 검색 트리를 사용하여 로그 시간 복잡도로 원소를 찾을 수 있기 때문에 검색이 빠르다.

int main() {
	const int NUM_ELEMENTS = 2000000;

	vector<int> myVector;
	set<int> mySet;

	for (int i = 0; i < NUM_ELEMENTS; i++) {
		myVector.push_back(i);
		mySet.insert(i);
	}
	// Vector 검색 시간 측정
	auto start = high_resolution_clock::now();
	sort(myVector.begin(), myVector.end());

	// 검색 테스트
	auto it = find(myVector.begin(), myVector.end(), NUM_ELEMENTS - 1);
	auto end = high_resolution_clock::now();
	auto durationVectorSearch = duration_cast<milliseconds>(end - start);
	cout << "Search in vector: " << durationVectorSearch.count() << " ms" << endl;

	start = high_resolution_clock::now();
	auto itSet = mySet.find(NUM_ELEMENTS - 1);
	end = high_resolution_clock::now();
	auto durationSetSearch = duration_cast<milliseconds>(end - start);
	cout << "Search in set: " << durationSetSearch.count() << " ms" << endl;
}