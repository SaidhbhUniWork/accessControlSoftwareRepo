#pragma once
#include "CompositeRole.h"
class ExecuteAccessBuilder : public CompositeRole
{
public:
	ExecuteAccessBuilder()
	{
		this->accessName = "Execute Access";
		this->accessLevel = AccessTypeEnum::E;
	}
};

