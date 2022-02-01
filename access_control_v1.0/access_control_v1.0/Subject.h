#pragma once

#include <iostream>
#include <string>

using namespace std;

class Subject
{
private:
	string s_username = "";
	string s_password = "";
	bool isAuthenticated = false;

public:
	Subject(string name, string password) : s_username(name), s_password(password) {}
	Subject(void) {}
	~Subject(void) {}

	string getPassword();
	string getUsername();
	void setPassword(string password);
	void setUsername(string name);

	void getLoginDetails(void);
};

