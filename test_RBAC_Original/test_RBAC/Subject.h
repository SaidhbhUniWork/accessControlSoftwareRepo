#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "authLevelEnum.h"
#include "SimpleRole.h"
#include "CompositeRole.h"

class Subject
{
private:
	std::string s_username = "";
	std::string s_password = "";
	AuthLevelEnum s_authLevel = AuthLevelEnum::NONE;
	bool isAuthenticated = false;
	std::shared_ptr<Role> newRole;

public:
	Subject(std::string name, std::string password) : s_username(name), s_password(password) {
		newRole = std::make_shared<SimpleRole>();
		s_authLevel = newRole->getRole(this->s_username);
		//newRole = std::make_shared<CompositeRole>(move(newRole));
		//s_authLevel = newRole->getRole(this->s_username);
	}
	Subject(void) {};
	~Subject(void) {};

	std::string getPassword();
	std::string getUsername();
	void setPassword(std::string password);
	void setUsername(std::string name);
	AuthLevelEnum getAuth(void) const;
	void setAuth(std::string name);

	void getLoginDetails(void);

	void compositeRoleBuilder(uint16_t compRoleInt);
};
