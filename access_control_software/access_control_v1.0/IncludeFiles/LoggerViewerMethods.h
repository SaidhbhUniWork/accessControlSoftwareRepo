#pragma once
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <vector>
#include <iomanip>
#include "Types.h"
#include "Validation.h"


using namespace std;

class LoggerViewerMethods
{
private:
	Validation valid;
	uint16_t fileDay = 0;
	uint16_t fileMonth = 0;
	uint16_t fileYear = 0;
	string fileDate = "";
	string showDate = "";
	string logName = "";
	vector<string> fileVector;
	vector<string> filteredVector;
public:
    void setFileLogDate(uint16_t fileDay, uint16_t fileMonth, uint16_t fileYear);
    string getFileDate();
    //inline void setReadLoggerType(uint16_t logType) { this->logType = (LoggerTypeEnum)logType; }
	uint16_t getFileSearchParameters();
	void getUserNameSearchParam(vector<string> filterVect);
	void getDateSearchParam(vector<string> filterVect);
	bool getFileTimeInput(int& hour, int& min, int& sec, tm& tm);
	vector<string> tokeniseVector(string vectorString);
	void formatStringOutput(vector<string> fileVector);
	void filterResults(uint16_t userSelection, vector<string> vect);
	void formatActualDateForResultFiltering(string& hour, int intHour, string& min, int intMin, string& sec, int intSec);
};

