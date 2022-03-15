#pragma once
#include "CompositeRole.h"
class NoAccessBuilder : public CompositeRole
{
protected:
	std::string accessNamePart = "No Access";
	AccessTypeEnum accessLevelPart = AccessTypeEnum::E;
public:
	NoAccessBuilder() {}
	AccessTypeEnum returnCompositeRole();
};

