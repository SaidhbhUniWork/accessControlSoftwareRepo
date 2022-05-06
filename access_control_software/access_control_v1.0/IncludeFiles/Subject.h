#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include "Base64_encode.h"
#include "Encrypt.h"
#include "AuthEnum.h"
#include "CompositeRole.h"
#include "SimpleRole.h"
#include "ExecuteAccess.h"
#include "ReadAccess.h"
#include "WriteAccess.h"
#include "FullAccess.h"
#include "AdminAccess.h"
#include "NoAccess.h"
#include "Types.h"

using namespace std;

class Subject
{
private:
	string s_username = "";
	string s_password = "";
	bool isAuthenticated = false;
	uint16_t subjectAuth = 0;
	uint16_t subjectRole = 0;
	vector<AuthEnum> subjectAuthorizationVector;
	vector<AuthEnum> v_privilegeVector;	
	map < uint16_t, vector<AuthEnum>> map_privilegeMap;
	string s_fileLine = "";
	string s_filename = SUB_FNAME_PRIV;
	ifstream if_inFile;
	EncryptDecrypt encDec;
	Base64_encode base64;
protected:
	shared_ptr<Role> buildRole;
	shared_ptr<Role> rolePtr;
public:
	Subject(void);
	~Subject(void) {}

	string getPassword();
	string getUsername();
	int getSubjectAuthLevel();
	int getSubjectRole();
	void setPassword(string password);
	void setUsername(string name);
	void setAllSubjectCredentials(string p_uname, string p_pword);

	vector<AuthEnum> authorizeSubject();
	void simpleAuthorisation(string uname);
	uint16_t returnSubjectRoleFromSimpleRole(string uName);
	void privilegeAuthorisation(uint16_t permissionIter);

	void allocatePrivileges(uint16_t aggregateRole);
	void enhanceSubjectPrivileges(AuthEnum newAuth);

	void setAuthorisation(uint16_t subAuth);
	void setEnhancedAuthorisation(uint16_t enhancedAuth);
	vector<AuthEnum> getAuthorisationVector();

	void tokenString(string str);
};

