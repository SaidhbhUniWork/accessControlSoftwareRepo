#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>
#include<vector>

using namespace std;

class FullAccess : public RoleBuilder
{
private:
	int _authLevel;
	vector<AuthEnum> authorizationVector;
public:
	FullAccess(shared_ptr<Role> auth = nullptr);
	~FullAccess(void);
	int getRole(int role) override;
};

