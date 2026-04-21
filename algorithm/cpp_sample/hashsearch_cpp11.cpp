/* c++98에서는 unordered_map을 사용할 수 없음 */
/*
몇 가지 클린코드 포인트
1. reserve: vector, unordered_set에 reserve를 사용하면 불필요한 reallocate를 막을 수 있다.
2. const reference : 반복자 대신 const reference를 사용하여 불필요한 복사를 막는다. 

*/


/* c++11 이후 */
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<bool> solution(const vector<string>& id_list, const vector<string>& try_list ) {
	vector<bool> answer;

	/* unordered_map을 사용해도 되지만(탐색 속도는 동일) 불필요한 메모리가 사용된다.*/
	unordered_set<string> registered_ids;
	registered_ids.reserve(id_list.size());
	for (const string& id : id_list)
		registered_ids.insert(id);

	answer.reserve(try_list.size());
	for (const string& t : try_list) {
		if(registered_ids.find(t) != registered_ids.end()) {
			answer.push_back(true);
		} else {
			answer.push_back(false);
		}
	}	
	return answer;
}
