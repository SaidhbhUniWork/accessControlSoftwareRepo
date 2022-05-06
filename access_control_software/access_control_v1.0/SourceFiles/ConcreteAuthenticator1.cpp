#include "ConcreteAuthenticator1.h"

bool ConcreteAuthenticator1::authenticate(Subject& p_sub) {
	string locStr_uname = p_sub.getUsername();
	string locStr_pword = p_sub.getPassword();
	if (ptr_authInfo->validateUser(locStr_uname, locStr_pword)) {
		cout << endl << LOGGED << endl << endl;
		system("pause");
		return true;
	}
	else {
		cout << LOGGED_ERROR << endl;
		return false;
	}
}

string ConcreteAuthenticator1::getFileName() {
	return this->s_fileName;
}

void ConcreteAuthenticator1::setFileName(std::string p_fileName) {
	this->s_fileName = p_fileName;
}