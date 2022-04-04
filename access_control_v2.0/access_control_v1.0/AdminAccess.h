#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class AdminAccess : public RoleBuilder
{
private:
	int _authLevel;
public:
	AdminAccess(shared_ptr<Role> auth = nullptr);
	~AdminAccess(void);
	int getRole(int role) override;

};

