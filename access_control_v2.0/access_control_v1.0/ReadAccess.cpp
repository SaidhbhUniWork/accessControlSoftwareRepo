#include "ReadAccess.h"

ReadAccess::ReadAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Read permission added" << endl;
	_authLevel = (int)(AuthEnum::R);	// TODO vector permissions
	authorizationVector.push_back(AuthEnum::E);
}

ReadAccess::~ReadAccess(void) {
	cout << "Read destroyed" << endl;
}

int ReadAccess::getRole(int role) {
	cout << "Read : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}