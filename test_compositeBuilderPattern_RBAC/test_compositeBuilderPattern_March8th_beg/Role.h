#pragma once
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Role
{
public:
	int _authLevel = 0;
	//int getAuth();
	virtual ~Role() {};
	virtual int getRole(int role) = 0;
};

