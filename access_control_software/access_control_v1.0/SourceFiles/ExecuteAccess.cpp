#include "ExecuteAccess.h"

ExecuteAccess::ExecuteAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	_authLevel = (int)(AuthEnum::E);
	authorizationVector.push_back(AuthEnum::E);
}

ExecuteAccess::~ExecuteAccess(void) {
}

int ExecuteAccess::getRole(int role) {
	//cout << "Admin : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}