#pragma once
#include "CompositeRole.h"
class WriteAccessBuilder : public CompositeRole
{
public:
	WriteAccessBuilder()
	{
		this->accessName = "Write Access";
		this->accessLevel = AccessTypeEnum::W;
	}
};

