#include "FullAccess.h"

FullAccess::FullAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Execute permission added" << endl;
	_authLevel = (int)(AuthEnum::FA);
}

FullAccess::~FullAccess(void) {
	cout << "Execute destroyed" << endl;
}

int FullAccess::getRole(int role) {
	cout << "Full Access : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}