#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class ExecuteAccess : public RoleBuilder
{
private:
	int _authLevel;
public:
	ExecuteAccess(shared_ptr<Role> auth = nullptr);
	~ExecuteAccess(void);
	int getRole(int role) override;
};

