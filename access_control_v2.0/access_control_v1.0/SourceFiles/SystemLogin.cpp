#include "SystemLogin.h"

void SystemLogin::mainLogin()
{
	char loginChar;
	cout << LOGIN_INTRO << endl << endl;
	while (isAuthenticated == false) {
		getSystemLogin();
		authenticateLogin(subject);

		if (isAuthenticated) {
			enum_subjectAuth = subject.authorizeSubject();
			break;
		}
		else {
			cout << "Login again? Y or N : " << endl;
			cin >> loginChar;
			if (loginChar == 'N') {
				break;
			}
			else {
				cin.ignore();	//clear the input buffer
				system("cls");
				continue;
			}
		}
	}

	//subject.enhanceSubjectPrivileges(AuthEnum::AD);
	if (enum_subjectAuth[0] != AuthEnum::NONE) {
		reference.objectTypeSelection();
	}
	
}

void SystemLogin::getSystemLogin()
{
	cout << "Enter Logins : " << endl;
	cout << "Username : ";
	getline(cin, this->s_uname);
	cout << "Password : ";
	getline(cin, this->s_pword);
	subject.setAllSubjectCredentials(s_uname, s_pword);
	//subject.authenticateSubject();	// getLoginDetails();
}

void SystemLogin::authenticateLogin(Subject& sub)
{
	//authenticate = std::make_shared<ConcreteAuthenticator1>();
	isAuthenticated = authenticate->authenticate(sub);
	
}