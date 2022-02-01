#pragma once

#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class DateTime
{   
private:
	string s_dateToday;
	string s_timeNow;
	string s_filedate;
protected:
	struct tm newdate;

public:
	DateTime();
	string getDate();
	string getTime();
	string getFileDate();
};

