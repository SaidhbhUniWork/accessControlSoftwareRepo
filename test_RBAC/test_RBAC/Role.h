#pragma once

#include <iostream>
#include "authLevelEnum.h"

class Role
{
public:
	Role() {}
	~Role() {}
	virtual AuthLevelEnum getRole(std::string) = 0;
};

