#include <vector>
#include <iostream>

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

bool solution(vector<vector<int>> edges) {
	int maxNode = 0;
	for (size_t i = 0; i < edges.size(); ++i) {
		if (edges[i][0] > maxNode) maxNode = edges[i][0];
		if (edges[i][1] > maxNode) maxNode = edges[i][1];
	}
	DisjointSet dsu(maxNode);

	for (size_t i = 0; i < edges.size(); ++i) {
		int u = edges[i][0];
		int v = edges[i][1];

		if (!dsu.unite(u, v)) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<vector<int>> case1;
	int edges1[3][2] = {{0,1}, {1,2}, {2,0}};
	for (size_t i = 0; i < 3; ++i) {
		vector<int> edge(edges1[i], edges1[i] + 2);
		case1.push_back(edge);
	}
	vector<vector<int>> case2;
	int edges2[3][2] = {{0, 1}, {1, 2}, {3, 4}};
	for (size_t i = 0; i < 3; ++i) {
		vector<int> edge(edges2[i], edges2[i] + 2);
		case2.push_back(edge);
	}
	cout << "case 1: " << (solution(case1) ? "cycle detected!" : "No cycle") << endl;
	cout << "case 2: " << (solution(case2) ? "cycle detected!" : "No cycle") << endl;	

	return 0;
}