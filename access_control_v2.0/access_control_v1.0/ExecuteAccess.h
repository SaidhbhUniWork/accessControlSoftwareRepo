#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class ExecuteAccess : public RoleBuilder
{
private:
	int _authLevel;
	vector<AuthEnum> authorizationVector;
public:
	ExecuteAccess(shared_ptr<Role> auth = nullptr);
	~ExecuteAccess(void);
	int getRole(int role) override;
};

