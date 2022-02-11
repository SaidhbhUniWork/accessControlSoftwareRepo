#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

#include "authLevelEnum.h"
#include "accessTypeEnum.h"

class Permission
{
private:
	AuthLevelEnum authLevel = AuthLevelEnum::NONE;
	AccessTypeEnum accessType = AccessTypeEnum::NA;

	typedef std::vector<int> permissions;
	std::map<AuthLevelEnum, permissions> thisMap;

	std::ifstream inFile;
	std::string fileLine;
	std::string fileToken;
	std::string resourceMapFileName = "userResourceMapNums.txt";

public:
	Permission();
	~Permission();

	int checkPermission(AuthLevelEnum role, uint16_t fileTypeID);

};

