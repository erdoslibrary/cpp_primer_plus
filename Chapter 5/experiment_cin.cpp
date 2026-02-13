/**
 * InputHandlingDifference.cpp
 * cin >> 와 cin.get()의 공백 처리 차이 및 버퍼 관리
 * * 작성자: Senior Software Engineer
 */

#include <iostream>

int main() {
    using namespace std;

    char ch1, ch2;

    // ---------------------------------------------------------
    // 1. cin >> (공백 무시 확인)
    // ---------------------------------------------------------
    cout << "=== Test 1: cin >> behavior ===" << endl;
    cout << "Type [Space] then [A] then [Enter]: "; 
    // 입력 예시: " A"
    
    cin >> ch1; 
    
    cout << "Read char: [" << ch1 << "]" << endl; 
    // 결과: 공백을 건너뛰고 'A'가 출력됨
    cout << "Note: Leading whitespace was skipped." << endl << endl;


    // ---------------------------------------------------------
    // 2. 버퍼 비우기 (매우 중요!)
    // ---------------------------------------------------------
    // 위에서 입력한 'Enter'(\n)가 버퍼에 남아있으므로, 
    // 다음 cin.get()이 엉뚱한 값을 읽지 않도록 청소해야 합니다.
    cin.ignore(1000, '\n'); // 최대 1000자를 읽거나 '\n'을 만날 때까지 버림
    cout << "--- (Buffer Cleared) ---" << endl << endl;


    // ---------------------------------------------------------
    // 3. cin.get() (공백 포함 확인)
    // ---------------------------------------------------------
    cout << "=== Test 2: cin.get() behavior ===" << endl;
    cout << "Type [Space] then [B] then [Enter]: ";
    // 입력 예시: " B"

    cin.get(ch2);

    cout << "Read char: [" << ch2 << "]" << endl;
    
    // 결과: 'B'가 아니라 맨 앞의 ' '(공백)이 출력됨
    if (ch2 == ' ') {
        cout << "Note: Leading whitespace (Space) was read exactly!" << endl;
    } else if (ch2 == '\n') {
        cout << "Note: It read a Newline character!" << endl;
    }

    return 0;
}