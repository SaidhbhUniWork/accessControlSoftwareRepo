#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include "LoggerAbs.h"
#include "TimeDate.h"

class DeniedAccessLogger : public LoggerAbs
{
private:
	string s_filename;
	ofstream of_outFileLog;
	ifstream if_inFileLog;

protected:
	shared_ptr<DateTime> timeNow = make_shared<DateTime>();

public:
	DeniedAccessLogger(const string p_filename);
	~DeniedAccessLogger() {}
	void createLog(string p_uname);
	//void readFromFile();
};

