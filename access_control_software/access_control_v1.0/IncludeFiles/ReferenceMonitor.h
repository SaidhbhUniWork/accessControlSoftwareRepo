#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "AuthEnum.h"
#include "ReferenceMonitorEnum.h"
#include "Subject.h"

using namespace std;

class ReferenceMonitor
{
private:
public:
	ReferenceMonitor() {}
	ReferenceMonitor(Subject mySub) {}
	~ReferenceMonitor() {}
	virtual bool validateResourceAccess(Subject& p_Subject, ReferenceMonitorEnum p_FileTypeSelection, AuthEnum p_AccessRequest) = 0;
};

