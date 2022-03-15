#pragma once

#include <iostream>
#include <memory>

#include "CompositeRole.h"

class CompositeRoleBuilder : public CompositeRole
{
protected:
	std::shared_ptr<CompositeRole> accessPart;
	std::shared_ptr<CompositeRole> newRole;

public:
	~CompositeRoleBuilder() {}
	void buildRole(std::shared_ptr<CompositeRole> thisRole);
	AccessTypeEnum returnCompositeRole();
};