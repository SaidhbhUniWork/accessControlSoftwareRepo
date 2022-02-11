#pragma once
#include "CompositeRole.h"
class NoAccessBuilder : public CompositeRole
{
public:
	NoAccessBuilder()
	{
		this->accessName = "No Access";
		this->accessLevel = AccessTypeEnum::NA;
	}
};

