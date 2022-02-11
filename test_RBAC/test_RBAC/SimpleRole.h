#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

#include "Role.h"
#include "authLevelEnum.h"

class SimpleRole : public Role
{
private:
	std::ifstream inFile;
	std::string roleMapFileName = "userRoleMap.txt";
	std::string fileLine;
	std::string fileToken;
	//std::shared_ptr<AuthLevelEnum> roleAuth = std::make_shared<AuthLevelEnum>(AuthLevelEnum::NONE);//;
	AuthLevelEnum roleAuth = AuthLevelEnum::NONE;


	std::map<std::string, AuthLevelEnum> roleMap;

public:
	SimpleRole();
	~SimpleRole();
	AuthLevelEnum getRole(std::string name);
	void assignAuthLevel(uint16_t roleAuth);
};

