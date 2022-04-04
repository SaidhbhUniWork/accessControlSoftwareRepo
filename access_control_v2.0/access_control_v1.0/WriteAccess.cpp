#include "WriteAccess.h"

WriteAccess::WriteAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Write permission added" << endl;
	_authLevel = (int)(AuthEnum::W);
}

WriteAccess::~WriteAccess(void) {
	cout << "Write destroyed" << endl;
}

int WriteAccess::getRole(int role) {
	cout << "Write : " << _authLevel << endl;
	_authLevel += role;
	return RoleBuilder::getRole(_authLevel);
}