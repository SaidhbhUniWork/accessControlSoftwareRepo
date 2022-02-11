#pragma once
#include "CompositeRole.h"
class ExecuteAccessBuilder : public CompositeRole
{
protected:
	std::string accessNamePart = "Execute Access";
	AccessTypeEnum accessLevelPart = AccessTypeEnum::E;
public:
	ExecuteAccessBuilder() {}
	AccessTypeEnum returnCompositeRole();
};

