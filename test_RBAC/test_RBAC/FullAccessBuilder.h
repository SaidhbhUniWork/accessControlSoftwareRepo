#pragma once
#include "CompositeRole.h"
class FullAccessBuilder : public CompositeRole
{
protected:
	std::string accessNamePart = "Full Access";
	AccessTypeEnum accessLevelPart = AccessTypeEnum::FA;
public:
	FullAccessBuilder() {}
	AccessTypeEnum returnCompositeRole();
};

