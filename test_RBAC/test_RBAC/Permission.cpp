#include "Permission.h"

Permission::Permission(void)
{
	try
	{
		inFile.open(resourceMapFileName, std::ios::in);
		permissions thisPermission;
		int count = 0;

		while (getline(inFile, fileLine)){
			std::istringstream iss(fileLine);

			for (int i = 0; i < 6; i++){
				iss >> fileToken;
				thisPermission.push_back(stoi(fileToken));
			}

			switch (count){
			case 0:
				authLevel = AuthLevelEnum::ADMIN;
				break;
			case 1:
				authLevel = AuthLevelEnum::LIMITED;
				break;
			case 2:
				authLevel = AuthLevelEnum::USER;
				break;
			default:
				authLevel = AuthLevelEnum::NONE;
				break;
			}

			thisMap.insert(std::pair <AuthLevelEnum, permissions> (authLevel, thisPermission ));
			thisPermission.clear();
			count++;
		}
	}
	catch (std::exception e)
	{
		std::cerr << "File Open error : " << e.what() << std::endl;
	}
}

Permission::~Permission(void)
{
	try
	{
		if (inFile.fail())
		{
			std::cout << "File closing : " << resourceMapFileName << std::endl;
			inFile.close();
		}
	}
	catch (std::exception e)
	{
		std::cerr << "File Close Error : " << e.what() << std::endl;
	}
}

int Permission::checkPermission(AuthLevelEnum role, uint16_t fileTypeID)
{
	std::map<AuthLevelEnum, permissions>::iterator it;
	it = thisMap.find(role);

	if (it != thisMap.end())
	{
		if (fileTypeID <= it->second.size())
		{
			return it->second[fileTypeID];
		}
		else
		{
			std::cout << "File Type ID " << fileTypeID << " not found." << std::endl;
		}
	}
	else
	{
		std::cout << "Subject not found." << std::endl;
	}
	return 0;	//AccessTypeEnum::NA;
}