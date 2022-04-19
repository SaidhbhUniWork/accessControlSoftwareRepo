#include "ExecuteAccess.h"

ExecuteAccess::ExecuteAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Execute permission added" << endl;
	_authLevel = (int)(AuthEnum::E);	//TODO vector permissions
	authorizationVector.push_back(AuthEnum::E);
}

ExecuteAccess::~ExecuteAccess(void) {
	cout << "Execute destroyed" << endl;
}

int ExecuteAccess::getRole(int role) {
	cout << "Execute : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}