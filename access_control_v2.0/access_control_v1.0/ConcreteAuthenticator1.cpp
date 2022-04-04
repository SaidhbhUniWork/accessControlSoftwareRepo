#include "ConcreteAuthenticator1.h"

uint16_t ConcreteAuthenticator1::authenticate(Subject& p_sub)
{
	string locStr_uname = p_sub.getUsername();
	string locStr_pword = p_sub.getPassword();
	if (ptr_authInfo->validateUser(locStr_uname, locStr_pword))
	{
		cout << LOGGED << endl;
		return 1;
	}
	else
	{
		cout << LOGGED_ERROR << endl;
		return -1;
	}
}

//uint16_t ConcreteAuthenticator1::getProofOfID()
//{
//
//}

string ConcreteAuthenticator1::getFileName()
{
	return this->s_fileName;
}

void ConcreteAuthenticator1::setFileName(std::string p_fileName)
{
	this->s_fileName = p_fileName;
}