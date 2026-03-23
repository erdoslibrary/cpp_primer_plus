#include <iostream>
#include <bitset>
#include <climits>

union 
{
	float single;
	int output;
} data;


int main()
{
	data.single = 12.375;

	std::bitset<32> bits(data.output);

	std::cout << "bits: " << bits << std::endl;
	std::cout << "int: " << data.output << std::endl;
	std::cout << "float: " << data.single << std::endl;
}
