#include "CompositeRole.h"

CompositeRole::CompositeRole(void) {
	cout << "Composite Role created" << endl;
}

CompositeRole::~CompositeRole(void) {
	cout << "Composite Role Destroyed" << endl;
}

int CompositeRole::getRole(int role) {
	cout << "final Role from Composite Role" << endl;
	return role;
}