#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

/* stringstream 사용하기*/
string solution(const vector<string>& actions) {
	queue<string> waitingQueue;
	const string CMD_PUSH = "push";
	const string CMD_POP = "pop";
	for (size_t i = 0; i < actions.size(); ++i) {
		stringstream ss(actions[i]);
		string cmd;

		if(!(ss >> cmd)) continue; // >> 연산자가 공백을 인식해서 Push만 분리해냄
		if (cmd == CMD_PUSH) {
			string name;
			if(ss >> name) {
				waitingQueue.push(name);
			}
		}
		else if (cmd == CMD_POP) {
			if (!waitingQueue.empty()) {
				waitingQueue.pop();
			}
		}
	}
	if (waitingQueue.empty()) {
		return "None";
	}
	return waitingQueue.front();
}


int main(int argc, char** argv)
{
	vector<string> actions1;
	actions1.push_back("push IronMan");
	actions1.push_back("push Hulk");
	actions1.push_back("pop");
	cout << "Test Case 1: " << solution(actions1) << " (Expected: Hulk)" << endl;

	vector<string> actions2;
	actions2.push_back("push IronMan");
	actions2.push_back("pop");
	actions2.push_back("pop");
	cout << "Test Case 2: " << solution(actions2) << " (Expected: None)" << endl;
}


/* it 불편..*/

// string solution(vector<string> actions) {
// 	queue<string> waitingQueue;
// 	const string PUSH_PREFIX = "push ";
// 	const size_t PUSH_PREFIX_LEN = 5;

// 	for (vector<string>::const_iterator it = actions.begin(); it != actions.end(); ++it) {
// 		const string& action = *it;

// 		if (action.find(PUSH_PREFIX) == 0) {
// 			if (action.length() > PUSH_PREFIX_LEN) {
// 				string name = action.substr(PUSH_PREFIX_LEN);
// 				waitingQueue.push(name);
// 			}
// 		}
// 		else if(action == "pop") {
// 			if (!waitingQueue.empty()) {
// 				waitingQueue.pop();
// 			}
// 		}
// 	}

// 	if (waitingQueue.empty()) {
// 		return "None";
// 	}

// 	return waitingQueue.front();
// }

