#include "Subject.h"

Subject::Subject() {

	vector<string> localVect, decryptedVector;
	try {
		if_inFile.open(s_filename, ios::in);
		while (getline(if_inFile, s_fileLine)) {
			istringstream iss(s_fileLine);
			string locString = base64.decodeString(s_fileLine);
			localVect.push_back(locString);
		}
		encDec.fullDecrypt(localVect, decryptedVector);
		for (size_t i = 0; i < decryptedVector.size(); i++) {
			tokenString(decryptedVector[i]);
		}
		if_inFile.close();
	}
	catch (exception e) {
		cerr << SUB_FOPEN_ERROR << e.what() << endl;
	}
}

string Subject::getPassword()
{
	return this->s_password;
}

string Subject::getUsername()
{
	return this->s_username;
}

int Subject::getSubjectAuthLevel() {
	return this->subjectAuth;
}

int Subject::getSubjectRole() {
	return this->subjectRole;
}

void Subject::setPassword(string p_password)
{
	this->s_password = p_password;
}

void Subject::setUsername(string p_username)
{
	this->s_username = p_username;
}

void Subject::setAllSubjectCredentials(string uname, string pword) {
	setUsername(uname);
	setPassword(pword);
}


vector<AuthEnum> Subject::authorizeSubject() {

	uint16_t defaultRole = (uint16_t)(AuthEnum::NONE);

	while (!isAuthenticated) {
		for (uint16_t i = 0; i < v_privilegeVector.size(); i++)
		{
			buildRole = make_shared<CompositeRole>();
			rolePtr = buildRole;
			simpleAuthorisation(s_username);						//assign user their role
			privilegeAuthorisation(i);								//assign user their file privileges
			setAuthorisation(rolePtr->getRole(defaultRole));
		}
		isAuthenticated = true;
	}

	return getAuthorisationVector();
}

void Subject::simpleAuthorisation(string uname) {

	buildRole = make_shared<SimpleRole>(uname, rolePtr);
	this->subjectRole = buildRole->returnAuthLevelFromRole();
	this->subjectAuth = subjectRole;
}

uint16_t Subject::returnSubjectRoleFromSimpleRole(string uName) {
	shared_ptr<Role> thisRole;
	shared_ptr<Role> tempPtr = thisRole;
	thisRole = make_shared <SimpleRole>(uName, thisRole);
	return thisRole->returnAuthLevelFromRole();
}

void Subject::privilegeAuthorisation(uint16_t permissionIter) {

	uint16_t aggregateRole = 0;
	map<uint16_t, vector<AuthEnum>>::iterator it;
	it = map_privilegeMap.find(subjectAuth);
	if (it != map_privilegeMap.end())
	{
		if (permissionIter <= it->second.size())
		{
			aggregateRole += (int)it->second[permissionIter];
		}
	}
	allocatePrivileges(aggregateRole);
}

void Subject::allocatePrivileges(uint16_t bitwiseOption) {

	if (bitwiseOption & 8) {
		buildRole = make_shared<NoAccess>(rolePtr);
		rolePtr = buildRole;
	}
	if (bitwiseOption & 16) {
		buildRole = make_shared<ReadAccess>(rolePtr);
		rolePtr = buildRole;
	}
	if (bitwiseOption & 32) {
		buildRole = make_shared<WriteAccess>(rolePtr);
		rolePtr = buildRole;
	}
	if (bitwiseOption & 64) {
		buildRole = make_shared<ExecuteAccess>(rolePtr);
		rolePtr = buildRole;
	}
	if (bitwiseOption & 128) {
		buildRole = make_shared<FullAccess>(rolePtr);
		rolePtr = buildRole;
	}
	if (bitwiseOption & 256) {
		buildRole = make_shared<AdminAccess>(rolePtr);
		rolePtr = buildRole;
	}
}

void Subject::tokenString(string str) {

	size_t pos = 0;
	string delim = "\t";
	string token;
	uint16_t thisRole = 0;
	vector<string> tokenVect;
	vector<AuthEnum> authVect;
	while ((pos = str.find(delim)) != string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + delim.length());
		tokenVect.push_back(token);
	}
	tokenVect.push_back(str);
	thisRole = atoi(tokenVect[0].c_str());
	for (size_t i = 1; i < tokenVect.size(); i++) {
		authVect.push_back((AuthEnum)(atoi(tokenVect[i].c_str())));
	}
	v_privilegeVector = authVect;
	map_privilegeMap[thisRole] = authVect;
}

void Subject::enhanceSubjectPrivileges(AuthEnum p_newAuth) {

	buildRole = make_shared<CompositeRole>(); // TODO THIS!!!!! implement
	rolePtr = buildRole;

	allocatePrivileges((uint16_t)p_newAuth);
	setEnhancedAuthorisation(rolePtr->getRole((uint16_t)AuthEnum::NONE));
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

vector<AuthEnum> Subject::getAuthorisationVector() {
	return subjectAuthorizationVector;
}