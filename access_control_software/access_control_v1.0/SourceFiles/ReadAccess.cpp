#include "ReadAccess.h"

ReadAccess::ReadAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	_authLevel = (int)(AuthEnum::R);	
	authorizationVector.push_back(AuthEnum::E);
}

ReadAccess::~ReadAccess(void) {
}

int ReadAccess::getRole(int role) {
	//cout << "Read : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}