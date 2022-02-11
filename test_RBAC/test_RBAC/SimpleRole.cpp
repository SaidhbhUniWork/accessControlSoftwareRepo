#include "SimpleRole.h"

SimpleRole::SimpleRole()
{
	try
	{
		std::string name, role;
		inFile.open(roleMapFileName, std::ios::in);

		while (getline(inFile, fileLine)) {
			std::istringstream iss(fileLine);
			iss >> name >> role;
			assignAuthLevel(stoi(role));
			roleMap.insert(std::pair<std::string, AuthLevelEnum>(name, roleAuth));
		}
	}
	catch (std::exception e)
	{
		std::cerr << "Cant open file : " << e.what() << std::endl;
	}
}

SimpleRole::~SimpleRole(void)
{
	try
	{
		if (inFile.fail())
		{
			std::cout << "File closing : " << roleMapFileName << std::endl;
			inFile.close();
		}
	}
	catch (std::exception e)
	{
		std::cerr << "File Close Error : " << e.what() << std::endl;
	}

}

void SimpleRole::assignAuthLevel(uint16_t roleInt)
{
	
	switch (roleInt) {
	case 1:
		roleAuth = AuthLevelEnum::ADMIN;
		break;
	case 2:
		roleAuth = AuthLevelEnum::LIMITED;
		break;
	case 4:
		roleAuth = AuthLevelEnum::USER;
		break;
	default:
		roleAuth = AuthLevelEnum::NONE;
		break;
	}

}

AuthLevelEnum SimpleRole::getRole(std::string name)
{
	std::map<std::string, AuthLevelEnum>::iterator it;
	it = roleMap.find(name);

	if (it != roleMap.end())
	{
		return it->second;
	}
	else
	{
		return AuthLevelEnum::NONE;
	}

}