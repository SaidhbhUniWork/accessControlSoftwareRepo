

#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class DateTime
{   
private:
	string dateToday;
	string timeNow;
	struct tm newdate;

public:
	DateTime();
	string getDate();
	string getTime();
	string getFileDate();
	//inline string getDateTime()
	//{
	//	struct tm newdate;
	//	time_t now = time(0);
	//	localtime_s(&newdate, &now);
	//	this->dateToday = to_string(newdate.tm_mday) + "/" + to_string((newdate.tm_mon) + 1) + "/" + to_string((newdate.tm_year) + 1900);
	//	return dateToday;
	//}
};

