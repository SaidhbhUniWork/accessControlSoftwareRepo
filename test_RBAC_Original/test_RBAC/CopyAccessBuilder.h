#pragma once

#include "CompositeRole.h"

class CopyAccessBuilder : public CompositeRole
{
protected:
	std::string accessNamePart = "Copy Access";
	AccessTypeEnum accessLevelPart = AccessTypeEnum::CO;
public:
	CopyAccessBuilder() {}
	AccessTypeEnum returnCompositeRole();
};

