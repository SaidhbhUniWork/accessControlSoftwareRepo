#include "CompositeRole.h"

AuthLevelEnum CompositeRole::getRole(std::string role)
{
	return AuthLevelEnum::NONE;
}

AccessTypeEnum CompositeRole::getAccessLevelValue(void)
{
	return this->accessLevel;
}

