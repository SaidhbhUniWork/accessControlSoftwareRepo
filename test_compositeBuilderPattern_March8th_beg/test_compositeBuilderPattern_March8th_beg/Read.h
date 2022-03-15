#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Read : public RoleBuilder
{
private:
	int _authLevel;
public:
	Read(shared_ptr<Role> auth = nullptr);
	//Read(AuthEnum);
	~Read(void);
	int getRole(int role) override;
};

