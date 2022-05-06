#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include "AuthEnum.h"

using namespace std;

class Role
{
protected:
	vector<AuthEnum> authorizationVector;
public:
	int _authLevel = 0;
	virtual ~Role() {};
	virtual int getRole(int role) = 0;
	virtual uint16_t returnAuthLevelFromRole() { return 0; };
};
