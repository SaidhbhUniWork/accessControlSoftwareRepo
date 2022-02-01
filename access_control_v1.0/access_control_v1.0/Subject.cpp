#include "Subject.h"

string Subject::getPassword()
{
	return this->s_password;
}

string Subject::getUsername()
{
	return this->s_username;
}

void Subject::setPassword(string p_password)
{
	this->s_password = p_password;
}

void Subject::setUsername(string p_username)
{
	this->s_username = p_username;
}

void Subject::getLoginDetails()
{
	cout << "Enter Logins : " << endl;
	cout << "Username : ";
	getline(cin, this->s_username);
	cout << "Password : ";
	getline(cin, this->s_password);
}