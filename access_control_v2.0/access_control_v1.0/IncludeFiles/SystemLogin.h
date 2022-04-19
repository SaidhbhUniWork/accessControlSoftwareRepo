#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "Subject.h"
#include "ConcreteAuthenticator1.h"
#include "ReferenceMonitor.h"
#include "ConcreteReferenceMonitor.h"
#include "AuthEnum.h"

class SystemLogin
{
private:
	string s_uname;
	string s_pword;
	Subject subject;	// (string p_uname, string p_pward);
	bool isAuthenticated = false;
	ConcreteReferenceMonitor reference;
	std::shared_ptr<AuthenticatorAbs> authenticate = std::make_shared<ConcreteAuthenticator1>();
	vector<AuthEnum> enum_subjectAuth;

public:
	SystemLogin() {}

	void mainLogin();
	void getSystemLogin();
	void authenticateLogin(Subject& sub);
};

