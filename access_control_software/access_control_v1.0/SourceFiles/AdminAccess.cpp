#include "AdminAccess.h"

AdminAccess::AdminAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	_authLevel = (int)(AuthEnum::AD);
}

AdminAccess::~AdminAccess(void) {
}

int AdminAccess::getRole(int role) {
	//cout << "Admin Access : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}