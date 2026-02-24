// stone1.cpp -- user-defined conversion functions
// compile with stonewt1.cpp
#include <iostream>
#include "stonewt1.h"

int main()
{
    using std::cout;
    Stonewt poppins(9,2.8);     // 9 stone, 2.8 pounds
    double p_wt = poppins;      // implicit conversion(암시적 변환)
	// 암시적 변환 함수는 신중하게 사용해야 함. 명시적으로만 호출할 수 있는 함수를 사용하는 것이 가장 바람직.
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";
	// std::cin.get();
    return 0; 
}
