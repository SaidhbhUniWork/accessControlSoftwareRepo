#include "ExecuteAccess.h"

ExecuteAccess::ExecuteAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Execute permission added" << endl;
	_authLevel = (int)(AuthEnum::E);
}

ExecuteAccess::~ExecuteAccess(void) {
	cout << "Execute destroyed" << endl;
}

int ExecuteAccess::getRole(int role) {
	cout << "Execute : " << _authLevel << endl;
	_authLevel += role;
	return RoleBuilder::getRole(_authLevel);
}