#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Write : public RoleBuilder
{
private:
	int _authLevel;
public:
	Write(shared_ptr<Role> auth = nullptr);
	~Write(void);
	int getRole(int role) override;
};

