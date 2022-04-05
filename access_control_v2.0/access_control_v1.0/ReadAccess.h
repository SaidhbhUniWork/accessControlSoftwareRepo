#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class ReadAccess : public RoleBuilder
{
private:
	int _authLevel;
	vector<AuthEnum> authorizationVector;
public:
	ReadAccess(shared_ptr<Role> auth = nullptr);
	~ReadAccess(void);
	int getRole(int role) override;
};
