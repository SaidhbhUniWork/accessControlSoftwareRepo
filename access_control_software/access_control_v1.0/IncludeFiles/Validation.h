#pragma once
#include <iostream>
#include <cctype>
#include <regex>
#include "Types.h"

class Validation
{
public:
	inline void inputValidataion_integer(uint16_t minNum, uint16_t& input, uint16_t p_num) {//input < 1 || input > p_num || (input % 1 != 0) || !isdigit(input)
		bool valid = false;
		while (!valid) {
			if (input < minNum || input > p_num)
			{
				input = 0;
				std::cout << "Invalid Selection (" << minNum << "-" << p_num << ") : ";
				cin.clear();
				std::cin >> input;
			}
			else valid = true;
		}
	}
	inline bool passwordValidation(string p_passwordString) {
		// validates for a password
		// minimum 8 chars, contains symbol, 
		// uppercase, lowercase and number
		regex validate("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,20}$");
		if (regex_search(p_passwordString, validate)) return true;
		else return false;
	}
};
