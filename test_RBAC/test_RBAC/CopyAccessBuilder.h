#pragma once
#include "CompositeRole.h"
class CopyAccessBuilder : public CompositeRole
{
public:
	CopyAccessBuilder()
	{
		this->accessName = "Copy Access";
		this->accessLevel = AccessTypeEnum::CO;
	}
};

