#include "Execute.h"

Execute::Execute(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Execute permission added" << endl;
	_authLevel = (int)(AuthEnum::E);
}

Execute::~Execute(void) {
	cout << "Execute destroyed" << endl;
}

int Execute::getRole(int role) {
	cout << "Execute : " << _authLevel << endl;
	_authLevel += role;
	return RoleBuilder::getRole(_authLevel);
}