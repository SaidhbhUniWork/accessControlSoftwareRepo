#pragma once

#include <ctime>
#include <string>
#include <iostream>
#include <vector>
#include "ReferenceMonitorEnum.h"
using namespace std;

class DateTime
{   
private:
	string s_dateToday = "";
	string s_timeNow = "";
	string s_filedate = "";
	uint16_t uint_hour = 0;
	uint16_t uint_min = 0;
	uint16_t uint_sec = 0;
	string s_hour = "";
	string s_min = "";
	string s_sec = "";
	string s_fileDate = "";
	string s_fileTime = "";
	string s_filetype = "";
protected:
	struct tm newdate;

public:
	DateTime();
	string getDate();
	string getTime();
	string getFileDate();
	vector<string> getFileSaveString(string p_uname);
	string getReferenceMonitorSaveString(string p_uname, ReferenceMonitorEnum p_fileTypeSelection);
	void convertFileEnumToString(string& p_fileTypeString, ReferenceMonitorEnum p_fileTypeSelection);
};

