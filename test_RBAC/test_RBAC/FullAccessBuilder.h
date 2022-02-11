#pragma once
#include "CompositeRole.h"
class FullAccessBuilder : public CompositeRole
{
public:
	FullAccessBuilder()
	{
		this->accessName = "Full Access";
		this->accessLevel = AccessTypeEnum::FA;
	}
};

