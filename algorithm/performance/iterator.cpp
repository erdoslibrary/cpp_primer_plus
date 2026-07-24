#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    list<int> lst = {1, 2, 3, 4, 5};

    cout << "Vector elements: ";
    std::string sep = "";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << sep << *it;
        sep = " ";
    }
    cout << endl;

    // 리스트 순회
    cout << "List elements: ";
    std::string sep2 = "";
    for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << sep2 << *it;
        sep2 = " ";
    }
    cout << endl;

    cout << "Vector elements in reverse(--it): ";
    std::string sep3 = "";
    for (vector<int>::iterator it = vec.end(); it != vec.begin();) {
        --it;
        cout << sep3 << *it;
        sep3 = " ";
    }
    cout << endl;
    
    cout << "Vector elements in reverse(rbegin/rend): ";
    std::string sep4 = "";
    for (vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << sep4 << *rit;
        sep4 = " ";
    }
    cout << endl;

    cout << "List elements in reverse: ";
    std::string sep5 = "";
    for (list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        cout << sep5 << *rit;
        sep5 = " ";
    }
    cout << endl;

    return 0;
}

/* 
반복자 목적:
- 컨테이너의 요소를 순차적으로 접근하고 조작하는 데 사용
- 반복자는 포인터처럼 보이지만 실제로는 객체이며, 컨테이너마다 다름

반복자의 장점:
1. 유연성: 다양한 컨테이너에 대해 동일한 방식으로 요소 순회
2. 추상화: 컨테이너의 내부 구조를 몰라도 요 소 접근
3. 범용성: 알고리즘 함수와 함께 사용하여 코드의 재사용성 높임

반복자 사용방법:
1. 반복자 선언: 컨테이너 타입에 따라 반복자 선언
2. 반복자 초기화
3. 반복자 사용: 반복자를 사용하여 요소에 접근하고 조작
*it, *rit 사용해서 요소를 접근할 수 있음
++it, --it 사용해서 반복자를 이동할 수 있음
*/






*/