#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

// nm으로 확인하기 위해 전역 변수로 선언합니다.
inflatable guests[2] = {
    {"Bambi", 0.5, 21.99},
    {"Godzilla", 2000, 565.99}
};

int main() {
    using namespace std;
    cout << "The guests " << guests[0].name << " and " << guests[1].name << endl;
    return 0; 
}