#include "SystemLogin.h"

void SystemLogin::mainLogin()
{
	cout << LOGIN_INTRO << endl << endl;

	getSystemLogin();
	subject.authorizeSubject();
	subject.enhanceSubjectPrivileges(AuthEnum::AD);
	reference.objectTypeSelection();
}

void SystemLogin::getSystemLogin()
{
	subject.authenticateSubject();
	uint16_t authLevel = authenticateLogin(subject);
}

uint16_t SystemLogin::authenticateLogin(Subject& sub)
{
	authenticate = std::make_shared<ConcreteAuthenticator1>();
	uint16_t authLevel = authenticate->authenticate(sub);
	return authLevel;
}