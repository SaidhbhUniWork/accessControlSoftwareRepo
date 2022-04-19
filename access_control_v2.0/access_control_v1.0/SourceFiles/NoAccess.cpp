#include "NoAccess.h"

NoAccess::NoAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Read permission added" << endl;
	_authLevel = (int)(AuthEnum::NA);	// TODO vector permissions
	authorizationVector.push_back(AuthEnum::NA);
}

NoAccess::~NoAccess(void) {
	cout << "Read destroyed" << endl;
}

int NoAccess::getRole(int role) {
	cout << "Read : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}