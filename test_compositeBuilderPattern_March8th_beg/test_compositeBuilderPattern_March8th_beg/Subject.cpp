#include "Subject.h"


void Subject::authorizeSubject() {

	int aggregateRole = 0;
	cout << "Enter Role : ";
	cin >> aggregateRole;
	int defaultRole = (int)(AuthEnum::NONE);
	//shared_ptr<Role> buildRole = make_shared<CompositeRole>();
	//shared_ptr<Role> rolePtr = buildRole;
	buildRole = make_shared<CompositeRole>();
	rolePtr = buildRole;

	//if (aggregateRole & 1) {
	//	buildRole = make_shared<SimpleRole>(1, rolePtr);
	//	rolePtr = buildRole;
	//}
	//if (aggregateRole & 2) {
	//	buildRole = make_shared<SimpleRole>(2, rolePtr);
	//	rolePtr = buildRole;
	//}
	simpleAuthorisation(aggregateRole);

	if (aggregateRole & 32) {
		buildRole = make_shared<FullAccess>(rolePtr);
		rolePtr = buildRole;
	}
	else
	{
		if (aggregateRole & 4) {
			buildRole = make_shared<Read>(rolePtr);
			rolePtr = buildRole;
		}
		if (aggregateRole & 8) {
			buildRole = make_shared<Write>(rolePtr);
			rolePtr = buildRole;
		}
		if (aggregateRole & 16) {
			buildRole = make_shared<Execute>(rolePtr);
			rolePtr = buildRole;
		}
	}
	setAuthorisation(rolePtr->getRole(defaultRole));
	cout << getAuthorisation() << endl;
}

void Subject::simpleAuthorisation(int aggregateRole) {
	if (aggregateRole & 1) {
		buildRole = make_shared<SimpleRole>(1, rolePtr);
		rolePtr = buildRole;
	}
	if (aggregateRole & 2) {
		buildRole = make_shared<SimpleRole>(2, rolePtr);
		rolePtr = buildRole;
	}
}

void Subject::privilegeAuthorisation(int aggregateRole) {

}

void Subject::setAuthorisation(int subjectAuth) {
	this->subjectAuth = subjectAuth;
}

int Subject::getAuthorisation() {
	return this->subjectAuth;
}