#pragma once
#include "Role.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class RoleBuilder : public Role
{
private:
	shared_ptr<Role> _auth;
public:
	RoleBuilder(shared_ptr<Role> thisRole = nullptr);
	virtual ~RoleBuilder();
	virtual int getRole(int role) override;
};
