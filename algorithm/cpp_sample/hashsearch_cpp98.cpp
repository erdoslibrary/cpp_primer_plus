#include <set> // set으로 해결 가능*/
#include <string>
#include <vector>

using namespace std;

vector<bool> solution(const vector<string>& id_list, const vector<string>& try_list) {
	vector<bool> answer;

	set<string> registered_ids;

	for (size_t i = 0; i < id_list.size(); ++i) {
		registered_ids.insert(id_list[i]);
	}

	answer.reserve(try_list.size());
	for (size_t i = 0; i < try_list.size(); ++i) {
		if(registered_ids.find(try_list[i]) != registered_ids.end()) {
			answer.push_back(true);
		} else {
			answer.push_back(false);
		}
	}
	return answer;
}
