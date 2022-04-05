#include "Subject.h"

string Subject::getPassword()
{
	return this->s_password;
}

string Subject::getUsername()
{
	return this->s_username;
}

void Subject::setPassword(string p_password)
{
	this->s_password = p_password;
}

void Subject::setUsername(string p_username)
{
	this->s_username = p_username;
}

void Subject::getLoginDetails()
{
	cout << "Enter Logins : " << endl;
	cout << "Username : ";
	getline(cin, this->s_username);
	cout << "Password : ";
	getline(cin, this->s_password);
}

void Subject::authenticateSubject()
{
	getLoginDetails();
}

void Subject::authorizeSubject() {

	//int aggregateRole = 0;
	//cout << "Enter Role : ";
	//cin >> aggregateRole;
	//cout << "Username : ";
	//cin >> uname;
	uint16_t defaultRole = (uint16_t)(AuthEnum::NONE);

	buildRole = make_shared<CompositeRole>();
	rolePtr = buildRole;

	simpleAuthorisation(s_username);
	loadPrivilegesFromFile();
	privilegeAuthorisation();
	setAuthorisation(rolePtr->getRole(defaultRole));
	cout << getAuthorisation() << endl;
}

void Subject::simpleAuthorisation(string uname) {

	buildRole = make_shared<SimpleRole>(uname, rolePtr);
	this->subjectAuth = buildRole->returnAuthLevelFromRole();	// TODO vector permissions
}

void Subject::privilegeAuthorisation() {
	uint16_t aggregateRole = 0;
	for (size_t i = 0; i < v_privilegeVector.size(); i++) {

		if (v_privilegeVector[i][0] == subjectAuth) {
			for (size_t j = v_privilegeVector[i].size(); j > 1; j--) {
				aggregateRole += v_privilegeVector[i][j - 1];
			}
		}
	}
	allocatePrivileges(aggregateRole);

	/*if (aggregateRole & 32) {
		buildRole = make_shared<FullAccess>(rolePtr);
		rolePtr = buildRole;
	}
	else {
		if (aggregateRole & 4) {
			buildRole = make_shared<ReadAccess>(rolePtr);
			rolePtr = buildRole;
		}
		if (aggregateRole & 8) {
			buildRole = make_shared<WriteAccess>(rolePtr);
			rolePtr = buildRole;
		}
		if (aggregateRole & 16) {
			buildRole = make_shared<ExecuteAccess>(rolePtr);
			rolePtr = buildRole;
		}
		if (aggregateRole & 64) {
			buildRole = make_shared<AdminAccess>(rolePtr);
			rolePtr = buildRole;
		}
	}*/
}

void Subject::allocatePrivileges(uint16_t bitwiseOption) {

	if (bitwiseOption & 64) {
		buildRole = make_shared<FullAccess>(rolePtr);
		rolePtr = buildRole;
	}
	else {
		if (bitwiseOption & 8) {
			buildRole = make_shared<ReadAccess>(rolePtr);
			rolePtr = buildRole;
		}
		if (bitwiseOption & 16) {
			buildRole = make_shared<WriteAccess>(rolePtr);
			rolePtr = buildRole;
		}
		if (bitwiseOption & 32) {
			buildRole = make_shared<ExecuteAccess>(rolePtr);
			rolePtr = buildRole;
		}
		if (bitwiseOption & 128) {
			buildRole = make_shared<AdminAccess>(rolePtr);
			rolePtr = buildRole;
		}
	}
}

void Subject::loadPrivilegesFromFile()	// TODO: - try move code to constructor?
{
	vector<uint16_t> localVect;
	try {
		uint16_t num;
		if_inFile.open(s_filename, ios::in);
		while (getline(if_inFile, s_fileLine)) {
			istringstream iss(s_fileLine);
			while (iss >> num) {
				localVect.push_back(num);
			}
			v_privilegeVector.push_back(localVect);
			localVect.clear();
		}
	}
	catch (exception e) {
		cerr << "Could not open file : " << e.what() << endl;
	}
}

void Subject::enhanceSubjectPrivileges(AuthEnum p_newAuth) {
	buildRole = make_shared<CompositeRole>();
	rolePtr = buildRole;

	allocatePrivileges((uint16_t)p_newAuth);
	setEnhancedAuthorisation(rolePtr->getRole((uint16_t)AuthEnum::NONE));
	//setAuthorisation(rolePtr->getRole((uint16_t)AuthEnum::NONE));
	cout << getAuthorisation() << endl;
}

void Subject::setAuthorisation(uint16_t subjectAuth) {
	this->subjectAuth = subjectAuth;
	this->subjectAuthorizationVector.push_back((AuthEnum)subjectAuth);
}

void Subject::setEnhancedAuthorisation(uint16_t enhancedAuth) {
	this->subjectAuth += enhancedAuth;
	subjectAuthorizationVector.clear();
	this->subjectAuthorizationVector.push_back((AuthEnum)subjectAuth);

}

uint16_t Subject::getAuthorisation() {
	return this->subjectAuth;	// TODO vector permissions
}