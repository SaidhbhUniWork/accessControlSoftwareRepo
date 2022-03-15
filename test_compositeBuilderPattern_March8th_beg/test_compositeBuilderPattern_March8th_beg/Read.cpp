#include "Read.h"

Read::Read(shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Read permission added" << endl;
	_authLevel = (int)(AuthEnum::R);
}

//Read::Read() {
//	cout << "Read permission added" << endl;
//	_authLevel = (int)(AuthEnum::R);
//
//}

Read::~Read(void) {
	cout << "Read destroyed" << endl;
}

int Read::getRole(int role) {
	cout << "Read : " << _authLevel << endl;
	_authLevel += role;
	return RoleBuilder::getRole(_authLevel);
}