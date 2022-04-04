#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class WriteAccess : public RoleBuilder
{
private:
	int _authLevel;
public:
	WriteAccess(shared_ptr<Role> auth = nullptr);
	~WriteAccess(void);
	int getRole(int role) override;
};

