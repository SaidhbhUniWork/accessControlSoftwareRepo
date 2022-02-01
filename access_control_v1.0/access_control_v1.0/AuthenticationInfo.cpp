#include "AuthenticationInfo.h"

AuthenticationInfo::AuthenticationInfo(const string p_filename)
{
	try
	{
		if_inFile.open(p_filename, ios::in);
		while (getline(if_inFile, s_fileLine))
		{
			istringstream iss(s_fileLine);
			iss >> s_unameAuth >> s_pwordAuth;
			userMap[s_unameAuth] = s_pwordAuth;
		}
		if_inFile.close();
	}
	catch (exception e)
	{
		cerr << AUTH_INFO_OPEN_ERROR << e.what() << endl;
	}

}

AuthenticationInfo::~AuthenticationInfo()
{
	try
	{
		if (!if_inFile.fail())
		{
			if_inFile.close();
		}
		for (size_t index = 0; index < userMap.size(); index++)
		{
			userMap.clear();
		}
	}
	catch (exception e)
	{
		cerr << AUTH_INFO_CLOSE_ERROR << e.what() << endl;
	}
}

bool AuthenticationInfo::validateUser(string name, string pass)
{
	bool valid = false;
	map<string, string>::iterator it;
	it = userMap.find(name);
	if (it != userMap.end())
	{
		if (!(it->second.compare(pass)))
		{
			setLogger(LoggerTypeEnum::SYSTEM_ACCESS);
			logger->createLog(name);
			valid = true;
		}
	}
	if(!valid)
	{
		setLogger(LoggerTypeEnum::DENIED_ACCESS);
		logger->createLog(name);
	}
	return valid;
}

void AuthenticationInfo::setLogger(LoggerTypeEnum logType)
{
	switch (logType)
	{
	case LoggerTypeEnum::SYSTEM_ACCESS:
		logger = make_shared<SystemAccessLogger>(SYSTEM_ACCESS_LOGGER);
		break;
	case LoggerTypeEnum::DENIED_ACCESS:
		logger = make_shared<DeniedAccessLogger>(DENIED_ACCESS_LOGGER);
		break;
	default:
		cout << "No log" << endl;
	}
}
