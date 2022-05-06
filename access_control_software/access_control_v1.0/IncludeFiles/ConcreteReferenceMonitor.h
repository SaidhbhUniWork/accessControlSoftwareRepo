#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include "AuthEnum.h"
#include "LoggerTypeEnum.h"
#include "LoggerAbs.h"
#include "ResourceAccessDenied.h"
#include "ResourceAccessSuccess.h"
#include "ReferenceMonitorEnum.h"
#include "ReferenceMonitor.h"
#include "Subject.h"
#include "Encrypt.h"
#include "Base64_encode.h"
#include "TimeDate.h"

using namespace std;

class ConcreteReferenceMonitor : public ReferenceMonitor
{
private:
	EncryptDecrypt encDec;
	Base64_encode base64;
	shared_ptr<DateTime> timeNow = make_shared<DateTime>();
	shared_ptr<LoggerAbs> logger;
	Subject mySubject;
	ifstream if_inFile;
	string s_fileName = REF_FILENAME;
	string s_fileLine = "";
	string s_logFilePath = "";
	vector<vector<AuthEnum>> vect_accessMatrixVector;
	map<uint16_t, vector<AuthEnum>> map_SubjectAccessMap;
	uint16_t uint_SubjectRole = 0;
	ReferenceMonitorEnum enum_FileType = ReferenceMonitorEnum::NONE;
	AuthEnum enum_subjectAuthorisation = AuthEnum::NONE;
public:
	ConcreteReferenceMonitor();
	~ConcreteReferenceMonitor();

	bool validateResourceAccess(Subject &p_Subject, ReferenceMonitorEnum p_FileTypeSelection, AuthEnum p_AccessRequest);
	AuthEnum accessActualPermission(uint16_t uint_SubjectRole);
	void tokenString(string str);
	void setLogger(LoggerTypeEnum p_logType);
};

