#pragma once

#include <iostream>
#include "CompositeRole.h"

class ReadAccessBuilder : public CompositeRole
{
protected:
	std::string accessNamePart = "Read Access";
	AccessTypeEnum accessLevelPart = AccessTypeEnum::E;
public:
	ReadAccessBuilder() {}
	AccessTypeEnum returnCompositeRole();
};

