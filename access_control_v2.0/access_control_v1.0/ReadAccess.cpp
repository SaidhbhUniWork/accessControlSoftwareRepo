#include "ReadAccess.h"

ReadAccess::ReadAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Read permission added" << endl;
	_authLevel = (int)(AuthEnum::R);
}

ReadAccess::~ReadAccess(void) {
	cout << "Read destroyed" << endl;
}

int ReadAccess::getRole(int role) {
	cout << "Read : " << _authLevel << endl;
	_authLevel += role;
	return RoleBuilder::getRole(_authLevel);
}