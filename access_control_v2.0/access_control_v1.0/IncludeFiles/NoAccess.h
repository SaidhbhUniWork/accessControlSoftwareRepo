#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class NoAccess : public RoleBuilder
{
private:
	int _authLevel = 0;
	vector<AuthEnum> authorizationVector;
public:
	NoAccess(shared_ptr<Role> auth = nullptr);
	~NoAccess(void);
	int getRole(int role) override;

};

