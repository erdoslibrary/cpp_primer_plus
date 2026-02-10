#include <iostream>
#include <string>

class SmartPhone 
{
private:
	std::string model_name;
	int battery_level;

public:
	SmartPhone(std::string name, int battery)
		: model_name(name), battery_level(battery) {}

	bool isSameModel(const SmartPhone& other) const
	{
		return this->model_name == other.model_name;
	}

	void charge()
	{
		battery_level = 100;
	}
};

int main()
{
	const SmartPhone myPhone("Galaxy S26", 80);
	SmartPhone yourPhone("Galaxy S26", 50);

	if (myPhone.isSameModel(yourPhone))
	{
		std::cout << "모델이 같습니다." << std::endl;
	}
	return 0;
}