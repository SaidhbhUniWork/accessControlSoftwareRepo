#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include "AuthEnum.h"
#include "CompositeRole.h"
#include "SimpleRole.h"
#include "ExecuteAccess.h"
#include "ReadAccess.h"
#include "WriteAccess.h"
#include "FullAccess.h"
#include "AdminAccess.h"

using namespace std;

class Subject
{
private:
	string s_username = "";
	string s_password = "";
	bool isAuthenticated = false;
	uint16_t subjectAuth;
	string uname;	// TODO check if needed
	vector<vector<uint16_t>> v_privilegeVector;
	string s_fileLine;
	string s_filename = "assignPrivileges.txt";
	ifstream if_inFile;
protected:
	shared_ptr<Role> buildRole;
	shared_ptr<Role> rolePtr;
public:
	Subject(string name, string password) : s_username(name), s_password(password) {}
	Subject(void) {}
	~Subject(void) {}

	string getPassword();
	string getUsername();
	void setPassword(string password);
	void setUsername(string name);
	void authenticateSubject();
	void getLoginDetails(void);

	void authorizeSubject();
	void simpleAuthorisation(string uname);
	void privilegeAuthorisation();
	void allocatePrivileges(uint16_t aggregateRole);
	void loadPrivilegesFromFile();
	void enhanceSubjectPrivileges(AuthEnum newAuth);
	void setAuthorisation(uint16_t subAuth);
	uint16_t getAuthorisation();
};

