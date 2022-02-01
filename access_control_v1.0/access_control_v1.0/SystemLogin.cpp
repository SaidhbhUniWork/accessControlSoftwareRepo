#include "SystemLogin.h"

void SystemLogin::mainLogin()
{
	cout << LOGIN_INTRO << endl << endl;

	getSystemLogin();

}

void SystemLogin::getSystemLogin()
{
	subject.getLoginDetails();
	uint16_t authLevel = authenticateLogin(subject);
}

uint16_t SystemLogin::authenticateLogin(Subject& sub)
{
	uint16_t authLevel = authenticate.authenticate(sub);
	return authLevel;
}