#pragma once

#include <iostream>
#include <string>
//#include <sqlite3.h>
#include "Subject.h"
#include "ConcreteAuthenticator1.h"

class SystemLogin
{
private:
	Subject subject;
	ConcreteAuthenticator1 authenticate;

public:
	SystemLogin() {}

	void mainLogin();
	void getSystemLogin();
	uint16_t authenticateLogin(Subject& sub);
};

