#include <vector>
#include <string>
#include <iostream>

using namespace std;

string preorder(vector<int> nodes, int idx) {
	if (idx < nodes.size()) {
		string ret = to_string(nodes[idx]) + " ";
		ret += preorder(nodes, idx * 2 + 1);
		ret += preorder(nodes, idx * 2 + 2);
		return ret;
	}
	return "";
}

string inorder(const vector<int>& nodes, int idx) {
	if (idx < nodes.size()) {
		string ret = inorder(nodes, idx * 2 + 1);
		ret += to_string(nodes[idx]) + " ";
		ret += inorder(nodes, idx * 2 + 2);
		return ret;
	}
	return "";
}

string postorder(const vector<int>& nodes, int idx) {
	if (idx < nodes.size()) {
		string ret = postorder(nodes, idx * 2 + 1);
		ret += postorder(nodes, idx * 2 + 2);
		ret += to_string(nodes[idx]) + " ";
		return ret;
	}
	return "";
}

vector<string> solution(vector<int> nodes) {
	vector<string> result;
	string pre = preorder(nodes, 0);
	string in = inorder(nodes, 0);
	string post = postorder(nodes, 0);

	pre.pop_back();
	in.pop_back();
	post.pop_back();

	result.push_back(pre);
	result.push_back(in);
	result.push_back(post);

	return result;
} 

int main() {
	vector<int> nodes = {1,2,3,4,5,6,7};
	vector<string> results = solution(nodes);
	const string labels[] = {"Preorder: ", "Inorder: ", "Postorder: "};

	cout << "results" << endl;
	for (vector<string>::size_type i = 0; i < results.size(); ++i) {
		cout << labels[i] << "[" << results[i] << "]" << endl;
	}
	return 0;
}