#pragma once
#include "CompositeRole.h"
class WriteAccessBuilder : public CompositeRole
{
protected:
	std::string accessNamePart = "Write Access";
	AccessTypeEnum accessLevelPart = AccessTypeEnum::E;
public:
	WriteAccessBuilder() {}
	AccessTypeEnum returnCompositeRole();
};

