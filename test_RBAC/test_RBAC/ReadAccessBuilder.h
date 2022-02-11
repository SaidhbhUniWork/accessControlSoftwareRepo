#pragma once

#include <iostream>
#include "CompositeRole.h"

class ReadAccessBuilder : public CompositeRole
{
public:
	ReadAccessBuilder()
	{
		this->accessName = "Read Access";
		this->accessLevel = AccessTypeEnum::R;
	}
};

