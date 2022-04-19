#pragma once

#include <vector>
#include "AuthEnum.h"
#include "FileAccessRequest.h"

class FileType4 : public FileAccessRequest
{
private:
	std::vector<AuthEnum> fileTypeEnum;
public:
	FileType4();
	//void buildFileTypePermissions();
};

