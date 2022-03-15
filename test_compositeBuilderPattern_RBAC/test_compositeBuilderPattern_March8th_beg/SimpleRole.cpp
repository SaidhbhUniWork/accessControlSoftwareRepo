#include "SimpleRole.h"

SimpleRole::SimpleRole(int roleAuth, shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Simple Role aassigned" << endl;
	if(roleAuth == (int)(AuthEnum::ADMIN))
		_authLevel = roleAuth;
	if (roleAuth == (int)(AuthEnum::USER))
		_authLevel = roleAuth;
}

SimpleRole::~SimpleRole(void) {
	cout << "Simple Role destroyed" << endl;
}

int SimpleRole::getRole(int role) {
	cout << "Simple Role : " << _authLevel << endl;
	_authLevel += role;
	return RoleBuilder::getRole(_authLevel);
}