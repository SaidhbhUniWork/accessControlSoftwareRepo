#include "Subject.h"

std::string Subject::getPassword()
{
	return this->s_password;
}

std::string Subject::getUsername()
{
	return this->s_username;
}

void Subject::setPassword(std::string p_password)
{
	this->s_password = p_password;
}

void Subject::setUsername(std::string p_username)
{
	this->s_username = p_username;
}

void Subject::getLoginDetails()
{
	std::cout << "Enter Logins : " << std::endl;
	std::cout << "Username : ";
	getline(std::cin, this->s_username);
	std::cout << "Password : ";
	getline(std::cin, this->s_password);
	//setAuth(s_username);
	//return this->s_authLevel;
}

void Subject::setAuth(std::string name)
{
	//if (name == "dave")
	//{
	//	this->s_authLevel = AuthLevelEnum::LIMITED;
	//	this->isAuthenticated = true;
	//}
	//else this->s_authLevel = AuthLevelEnum::NONE;
}

AuthLevelEnum Subject::getAuth(void) const
{
	return this->s_authLevel;
}

void Subject::compositeRoleBuilder(uint16_t compRoleInt)
{
	std::shared_ptr<CompositeRole> thisRole = std::make_shared<CompositeRole>();
}
