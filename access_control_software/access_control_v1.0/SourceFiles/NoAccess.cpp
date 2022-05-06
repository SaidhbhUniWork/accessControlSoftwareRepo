#include "NoAccess.h"

NoAccess::NoAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	_authLevel = (int)(AuthEnum::NA);	
	authorizationVector.push_back(AuthEnum::NA);
}

NoAccess::~NoAccess(void) {
}

int NoAccess::getRole(int role) {
	//cout << "Read : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}