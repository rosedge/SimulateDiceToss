#include "dice.h"

int main()
{
	CDice dice1, dice2;
	auto vecVal = dice1.Toss();
	auto arrVal = dice1.GetCurrentValue();
	std::cout << "vecVal:" << vecVal << std::endl;
	std::cout << "arrVal:" << arrVal << std::endl;
	auto vec2Val = dice2.Toss();
	auto arr2Val = dice2.GetCurrentValue();
	auto sum = arr2Val + arrVal;
	std::cout << "vec2Val:" << vec2Val << std::endl;
	std::cout << "arr2Val:" << arr2Val << std::endl;
	std::cout << "sum:" << sum << std::endl;
	std::system("pause");
	return 0;
}