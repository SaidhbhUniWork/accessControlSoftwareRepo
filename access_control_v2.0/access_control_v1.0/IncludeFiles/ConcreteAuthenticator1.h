#pragma once

#include <iostream>
#include <string>

#include "AuthenticatorAbs.h"
#include "AuthenticationInfo.h"
#include "Subject.h"

class ConcreteAuthenticator1: public AuthenticatorAbs
{
private:
	std::string s_fileName = "userLogins.txt";

public:
	shared_ptr<AuthenticationInfo> ptr_authInfo = make_shared<AuthenticationInfo>(s_fileName);
	string getFileName();
	void setFileName(std::string p_filename);
	bool authenticate(Subject& sub);
	uint16_t getProofOfID();
};

