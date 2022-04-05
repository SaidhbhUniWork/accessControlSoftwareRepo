#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "Subject.h"
#include "ConcreteAuthenticator1.h"
#include "ReferenceMonitor.h"

class SystemLogin
{
private:
	Subject subject;
	ReferenceMonitor reference;
	std::shared_ptr<AuthenticatorAbs> authenticate;

public:
	SystemLogin() {}

	void mainLogin();
	void getSystemLogin();
	uint16_t authenticateLogin(Subject& sub);
};

