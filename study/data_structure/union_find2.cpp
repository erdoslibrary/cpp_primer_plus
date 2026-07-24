#include <vector>
#include <iostream>
#include <ranges>

using namespace std;

struct DisjointSet {
	vector<int> parent;

	DisjointSet(int n) {
		parent.resize(n + 1);
		for (size_t i = 0; i < parent.size(); ++i) {
			parent[i] = static_cast<int>(i);
		}
	}

	int find(int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}
	bool unite(int a, int b) {
		int rootA = find(a);
		int rootB = find(b);

		if (rootA == rootB) {
			return false;
		}
		parent[rootA] = rootB;
		return true;
	}
};


vector<bool> solution(int n, vector<vector<int>> operations) {
	vector<bool> answer;
	DisjointSet dsu(n);

	for (size_t i = 0; i < operations.size(); ++i) {
		int cmd = operations[i][0];
		int u = operations[i][1];
		int v = operations[i][2];

		if (cmd == 0) {
			dsu.unite(u, v);
	
		} else {
			answer.push_back(dsu.find(u) == dsu.find(v));
		}
	}
	return answer;
}

int main() {
	int n = 4;
	vector<vector<int>> operations = {
		{0, 1, 2},
		{0, 3, 4},
		{1, 1, 2},
		{1, 1, 4}
	};

	const auto results = solution(n, operations);

	for (size_t i = 0; i < results.size(); ++i) {
		cout << "Operation " << i + 1 << ": " << (results[i] ? "true" : "false") << endl;
	}
	return 0;
}