#pragma once

#include <iostream>
#include "AuthEnum.h"

class FileAccessRequest
{
private:

public:

	FileAccessRequest() {}
	~FileAccessRequest() {}
	virtual AuthEnum fileTypeRequested() = 0;
	void buildFileTypePermissions();
};

