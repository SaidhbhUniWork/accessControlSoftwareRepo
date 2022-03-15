#pragma once
#include "Role.h"
#include <iostream>

using namespace std;

class CompositeRole : public Role
{
public:
	CompositeRole(void);
	~CompositeRole(void);
	int getRole(int role) override;
};

