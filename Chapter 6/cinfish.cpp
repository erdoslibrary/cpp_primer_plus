// cinfish.cpp -- non-numeric input terminates loop
#include <iostream>
const int Max = 5;
int main()
{
    using namespace std;
// get data
    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
            << " fish <q to terminate>.\n";
    cout << "fish #1: ";
    int i = 0;
    while (i < Max && cin >> fish[i]) 
	// 숫자가 아닌게 들어와서 실패하면 while을 빠져나감.
	// q가 아니라 다른 숫자가 아닌 것을 입력해도 cin이 종료된다.
	// cin 은 while문 안에서 bool 타입으로 자동 변환된다.
	{
        if (++i < Max)
            cout << "fish #" << i+1 << ": ";
    }
// calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];
// report results
    if (i == 0)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of "
            << i << " fish\n";
    cout << "Done.\n";
// code to keep VC execution window open if q is entered
//	if (!cin)  // input terminated by non-numeric response
//	{
//	    cin.clear();  // reset input
//	    cin.get();    // read q
//	}
//	cin.get();    // read end of line after last input
//	cin.get();    // wait for user to press <Enter>
    return 0; 
}
