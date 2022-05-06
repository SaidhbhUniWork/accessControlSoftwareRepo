#include "AuthenticationInfo.h"

AuthenticationInfo::AuthenticationInfo(const string p_filename)
{
	vector<string> locVector, decryptedVector;
	try {
		if_inFile.open(p_filename, ios::in);
		while (getline(if_inFile, s_fileLine)) {
			istringstream iss(s_fileLine);
			string locString = base64.decodeString(s_fileLine);
			locVector.push_back(locString);
		}
		encDec.fullDecrypt(locVector, decryptedVector);
		for (size_t i = 0; i < decryptedVector.size(); i++) {
			tokenString(decryptedVector[i]);
		}
		if_inFile.close();
	}
	catch (exception e) {
		cerr << AUTH_INFO_OPEN_ERROR << e.what() << endl;
	}

}

void AuthenticationInfo::tokenString(string str) {
	size_t pos = 0;
	string delim = " ";
	string token;
	while ((pos = str.find(delim)) != string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + delim.length());
	}
	userMap[token] = str;
}

AuthenticationInfo::~AuthenticationInfo()
{
	try {
		if (!if_inFile.fail()) {
			if_inFile.close();
		}
		for (size_t index = 0; index < userMap.size(); index++) {
			userMap.clear();
		}
	}
	catch (exception e) {
		cerr << AUTH_INFO_CLOSE_ERROR << e.what() << endl;
	}
}

bool AuthenticationInfo::validateUser(string name, string pass)
{
	bool valid = false;
	map<string, string>::iterator it;
	it = userMap.find(name);
	if (it != userMap.end()) {
		if (!(it->second.compare(pass))) {
			setLogger(LoggerTypeEnum::SYSTEM_ACCESS);
			logger->createLog(name);
			valid = true;
		}
	}
	if(!valid) {
		setLogger(LoggerTypeEnum::DENIED_ACCESS);
		logger->createLog(name);
	}
	return valid;
}
// creates unique filename for current date

void AuthenticationInfo::setLogger(LoggerTypeEnum logType)
{
	string loc_fileDate = cl_fileDate.getFileDate();
	switch (logType) {
	case LoggerTypeEnum::SYSTEM_ACCESS:
		s_logFilePath = SYSTEM_ACCESS_FPATH + loc_fileDate + SYSTEM_ACCESS_LOGGER;

		logger = make_shared<SystemAccessLogger>(s_logFilePath);

		break;
	case LoggerTypeEnum::DENIED_ACCESS:
		s_logFilePath = DENIED_ACCESS_FPATH + loc_fileDate + DENIED_ACCESS_LOGGER;
		logger = make_shared<DeniedAccessLogger>(s_logFilePath);

		break;
	default:
		cout << "No log" << endl;
	}
}
