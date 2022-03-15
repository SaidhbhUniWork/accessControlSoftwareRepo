#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class SimpleRole : public RoleBuilder
{
private:
	int _authLevel;
public:
	SimpleRole(int role, shared_ptr<Role> auth = nullptr);
	~SimpleRole(void);
	int getRole(int role) override;
};

