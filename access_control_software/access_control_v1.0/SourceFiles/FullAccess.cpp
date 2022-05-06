#include "FullAccess.h"

FullAccess::FullAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	_authLevel = (int)(AuthEnum::FA);
}

FullAccess::~FullAccess(void) {
}

int FullAccess::getRole(int role) {
	//cout << "Full Access : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}