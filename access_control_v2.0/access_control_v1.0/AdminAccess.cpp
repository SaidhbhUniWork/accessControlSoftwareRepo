#include "AdminAccess.h"

AdminAccess::AdminAccess(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Execute permission added" << endl;
	_authLevel = (int)(AuthEnum::AD);
}

AdminAccess::~AdminAccess(void) {
	cout << "Execute destroyed" << endl;
}

int AdminAccess::getRole(int role) {
	cout << "Admin Access : " << _authLevel << endl;
	_authLevel += role;
	return RoleBuilder::getRole(_authLevel);
}