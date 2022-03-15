#pragma once

#include <iostream>
#include <map>
#include "Subject.h"
#include "Permission.h"
#include "accessTypeEnum.h"


class Object
{
	//friend std::ostream& operator<<(std::ostream& os, AccessTypeEnum &c);
private:
	AccessTypeEnum accessType;
	int fileTypeID;

public:

	Object(const Subject& subject, Permission &permission, int _fileTypeID = 0, AccessTypeEnum _accessType = AccessTypeEnum::NA ) : fileTypeID(_fileTypeID), accessType(_accessType){
		if (permission.checkPermission(subject.getAuth(), _fileTypeID) & ((int)_accessType | (int)AccessTypeEnum::FA))
		{
			accessType = _accessType;
			std::cout << "Access Granted to Object. Access Type : " << (int)accessType << std::endl;
		}
		else
		{
			std::cout << "Access denied" << std::endl;
		}
	}

};

