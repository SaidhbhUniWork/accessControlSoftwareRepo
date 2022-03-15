#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "Role.h"
#include "accessTypeEnum.h"
#include "CompositeRoleBuilder.h"

class CompositeRole : public Role //npc
{
private:
	std::shared_ptr<Role> ptr_compositeRole;
	CompositeRoleBuilder compBuilder;

protected:
	std::string accessName = "";
	AccessTypeEnum accessLevel = AccessTypeEnum::NA;


	//std::shared_ptr<CompositeRole> accessPart = std::make_shared<CompositeRole>();

public:
	CompositeRole(std::shared_ptr<Role> p_compositeRole) : ptr_compositeRole{ move(p_compositeRole) } {}
	CompositeRole() {}

	AuthLevelEnum getRole(std::string);

	AccessTypeEnum getAccessLevelValue(void); // cost()
	virtual AccessTypeEnum returnCompositeRole(void) { return this->getAccessLevelValue(); } // costAll()
};

