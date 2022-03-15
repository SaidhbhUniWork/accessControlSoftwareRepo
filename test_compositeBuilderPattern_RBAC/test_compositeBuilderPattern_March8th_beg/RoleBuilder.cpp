#include "RoleBuilder.h"

RoleBuilder::RoleBuilder(shared_ptr<Role> auth) : _auth(move(auth)) {
	cout << "Role Builder created" << endl;
}

RoleBuilder::~RoleBuilder(void) {
	cout << "Role Builder destroyed" << endl;
}

int RoleBuilder::getRole(int role) {
	cout << "Adding role builder Authorisation" << endl;
	_authLevel += role;
	return _auth->getRole(_authLevel);
}

