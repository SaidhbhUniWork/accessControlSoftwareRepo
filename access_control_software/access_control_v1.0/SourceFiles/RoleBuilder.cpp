#include "RoleBuilder.h"

RoleBuilder::RoleBuilder(shared_ptr<Role> auth) : _auth(move(auth)) {
}

RoleBuilder::~RoleBuilder(void) {
}

int RoleBuilder::getRole(int role) {
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return _auth->getRole(_authLevel);
}

