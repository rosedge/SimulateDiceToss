/*
	class dice
*/

#pragma once;

#include <vector>
#include <array>
#include <random>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <chrono>

class CDice
{
private:
	enum tagPointValue
	{
		POINT_VALUE_INVALID,
		POINT_VALUE_1,
		POINT_VALUE_2,
		POINT_VALUE_3,
		POINT_VALUE_4,
		POINT_VALUE_5,
		POINT_VALUE_6,
	};
	size_t _currentPointValue;
	const size_t _diceFaces;
	std::vector<size_t> _vec;
	std::array<size_t, 6> _arr;
public:
	CDice::CDice() :_currentPointValue(POINT_VALUE_INVALID), _diceFaces(POINT_VALUE_6),
		_vec({ POINT_VALUE_1, POINT_VALUE_2, POINT_VALUE_3, POINT_VALUE_4, POINT_VALUE_5, POINT_VALUE_6 })
	{
		for (size_t i = POINT_VALUE_1; i <= POINT_VALUE_6; ++i)
		{
			_arr.at(i - 1) = i;
		}
	}
	CDice::~CDice(){}
	size_t Toss()
	{
		auto now = std::chrono::system_clock::now();
		std::srand(now.time_since_epoch().count());
		std::random_shuffle(_vec.begin(), _vec.end());
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(_arr.begin(), _arr.end(), g);
		std::cout << "_arr contents:";
		std::copy(_arr.begin(), _arr.end(), std::ostream_iterator<size_t>(std::cout, " "));
		std::cout << "\n";
		std::cout << "_vec contents:";
		std::copy(_vec.begin(), _vec.end(), std::ostream_iterator<size_t>(std::cout, " "));
		std::cout << "\n";
		_currentPointValue = *_arr.begin();
		return *_vec.begin();
	}
	size_t GetCurrentValue() const
	{
		return _currentPointValue;
	}
};

