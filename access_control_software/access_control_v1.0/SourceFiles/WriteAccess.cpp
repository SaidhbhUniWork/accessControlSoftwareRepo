#include "WriteAccess.h"

WriteAccess::WriteAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	_authLevel = (int)(AuthEnum::W);	
	authorizationVector.push_back(AuthEnum::W);
}

WriteAccess::~WriteAccess(void) {
}

int WriteAccess::getRole(int role) {
	//cout << "Write : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}