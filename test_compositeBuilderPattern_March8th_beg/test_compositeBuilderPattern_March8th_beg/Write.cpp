#include "Write.h"
Write::Write(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Write permission added" << endl;
	_authLevel = (int)(AuthEnum::W);
}

Write::~Write(void) {
	cout << "Write destroyed" << endl;
}

int Write::getRole(int role) {
	cout << "Write : " << _authLevel << endl;
	_authLevel += role;
	return RoleBuilder::getRole(_authLevel);
}