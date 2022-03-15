#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Execute : public RoleBuilder
{
private:
	int _authLevel;
public:
	Execute(shared_ptr<Role> auth = nullptr);
	~Execute(void);
	int getRole(int role) override;
};

