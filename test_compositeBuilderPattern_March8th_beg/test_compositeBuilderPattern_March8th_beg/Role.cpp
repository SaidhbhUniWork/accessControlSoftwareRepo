#include "Role.h"

//int Role::getAuth() {
//
//	int aggregateRole = 0;
//	cout << "Enter Role : ";
//	cin >> aggregateRole;
//	int defaultRole = (int)(AuthEnum::NONE);
//	shared_ptr<Role> buildRole = make_shared<CompositeRole>();
//	shared_ptr<Role> rolePtr = buildRole;
//
//	if (aggregateRole & 1) {
//		buildRole = make_shared<SimpleRole>(1, rolePtr);
//		rolePtr = buildRole;
//	}
//	if (aggregateRole & 2) {
//		buildRole = make_shared<SimpleRole>(2, rolePtr);
//		rolePtr = buildRole;
//	}
//	if (aggregateRole & 4) {
//		buildRole = make_shared<Read>(rolePtr);
//		rolePtr = buildRole;
//	}
//	if (aggregateRole & 8) {
//		buildRole = make_shared<Write>(rolePtr);
//		rolePtr = buildRole;
//	}
//	if (aggregateRole & 16) {
//		buildRole = make_shared<Execute>(rolePtr);
//		rolePtr = buildRole;
//	}
//
//	cout << rolePtr->getRole(defaultRole) << endl;
//
//
//	return 0;
//}