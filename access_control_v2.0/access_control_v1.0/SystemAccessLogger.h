#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include "LoggerAbs.h"
#include "TimeDate.h"

class SystemAccessLogger : public LoggerAbs
{
private:
	string s_filename;
	ofstream of_outFileLog;
	ifstream if_inFileLog;

protected:
	shared_ptr<DateTime> timeNow = make_shared<DateTime>();

public:
	SystemAccessLogger(const string p_filename);
	~SystemAccessLogger() {}
	void createLog(string p_uname);
	//void readFromFile();
};

