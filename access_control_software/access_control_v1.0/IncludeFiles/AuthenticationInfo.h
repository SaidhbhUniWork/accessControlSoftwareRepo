#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "Encrypt.h"
#include "Base64_encode.h"
#include "TimeDate.h"
#include "Types.h"
#include "SystemAccessLogger.h"
#include "DeniedAccessLogger.h"
#include "LoggerTypeEnum.h"

using namespace std;

class AuthenticationInfo
{
private:
	string s_fileLine = "";
	string s_unameAuth = "";
	string s_pwordAuth = "";
	string s_logFilePath = "";
	ifstream if_inFile;
	map<string, string> userMap;
	EncryptDecrypt encDec;
	Base64_encode base64;
protected:
	shared_ptr<LoggerAbs> logger;
	DateTime cl_fileDate;
public:
	
	AuthenticationInfo(const string p_filename);
	~AuthenticationInfo();
	bool validateUser(string p_uname, string p_pword);
	void setLogger(LoggerTypeEnum logType);
	void tokenString(string str);
};

