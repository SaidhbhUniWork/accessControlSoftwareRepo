#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class AdminAccess : public RoleBuilder
{
private:
	int _authLevel;
	vector<AuthEnum> authorizationVector;
public:
	AdminAccess(shared_ptr<Role> auth = nullptr);
	~AdminAccess(void);
	int getRole(int role) override;

};

