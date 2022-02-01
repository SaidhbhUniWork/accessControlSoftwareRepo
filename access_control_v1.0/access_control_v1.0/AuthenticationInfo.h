#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Types.h"
#include "SystemAccessLogger.h"
#include "DeniedAccessLogger.h"
#include "LoggerTypeEnum.h"
#include "TimeDate.h"

using namespace std;

class AuthenticationInfo
{
private:
	string s_fileLine;
	string s_unameAuth;
	string s_pwordAuth;
	ifstream if_inFile;
	map<string, string> userMap;
protected:
	shared_ptr<LoggerAbs> logger;
public:
	
	AuthenticationInfo(const string p_filename);
	~AuthenticationInfo();
	bool validateUser(string p_uname, string p_pword);
	void setLogger(LoggerTypeEnum logType);
};

