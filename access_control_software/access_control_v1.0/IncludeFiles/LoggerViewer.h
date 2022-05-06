#pragma once
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <memory>
#include <iomanip>
#include <vector>
#include "LoggerTypeEnum.h"
#include "LoggerAbs.h"
#include "SystemAccessLogger.h"
#include "DeniedAccessLogger.h"
#include "Types.h"
#include "LoggerViewerMethods.h"

using namespace std;

class LoggerViewer : public LoggerAbs
{
private:
	LoggerViewerMethods logMethods;
	string s_logFilePath = "";
	string fileDate = "";
	LoggerTypeEnum logType = LoggerTypeEnum::NONE; 
	vector<string> fileVector;
protected:
	shared_ptr<LoggerAbs> logger;
public:
	LoggerViewer() {}
	~LoggerViewer() {}
	string returnFileDate();
	void createLog(string) {};
	void readFromFile(string fileName, vector<string> vect) override;
};

