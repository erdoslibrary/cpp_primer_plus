#include <vector>
#include <iostream>

using namespace std;

// 필요시 노드 구조체 정의
struct Node {
    int id;
    Node* left;
    Node* right;
    Node(int val) : id(val), left(nullptr), right(nullptr) {}
};

// 전위 순회 
void preorder(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    result.push_back(node->id);
    preorder(node->left, result);
    preorder(node->right, result);
}

vector<int> solution(vector<vector<int>> links) {
    int n = links.size();
    vector<int> answer;
    // 1. 트리 구성 (Node 객체 생성 및 연결)
    vector<Node*> nodeMap(n + 1, nullptr);
    for (size_t i = 1; i <= n; ++i) {
        nodeMap[i] = new Node(i);
    }
    // 2. 전위 순회 수행
    for (size_t i = 0; i < n; ++i) {
		int leftIdx = links[i][0];
		int rightIdx = links[i][1];
		if (leftIdx != -1) nodeMap[i + 1]->left = nodeMap[leftIdx];
		if (rightIdx != -1) nodeMap[i + 1]->right = nodeMap[rightIdx];
	}
    preorder(nodeMap[1], answer);

    for (size_t i= 1; i <= n; ++i) {
        delete nodeMap[i];
    }
   
    return answer;
}

int main() {
	// [[2,3], [4,5], [-1-1], [-1,-1], [-1,-1]] 
	// 1번 자식: 2,3 / 2번 자식: 4,5 그림대로 
	vector<vector<int>> links = {
		{2,3}, {4,5}, {-1, -1}, {-1, -1}, {-1, -1}
	};
	vector<int> result = solution(links);
	cout << "results" << endl;
	for (size_t i = 0; i < result.size(); ++i) {
		cout << result[i] << (i == result.size() -1 ? "": " ");
	}
	return 0;

}