
#include "TimeDate.h"

DateTime::DateTime()
{
	//struct tm newdate;
	time_t now = time(0);
	localtime_s(&newdate, &now);
	this->dateToday = to_string(newdate.tm_mday) + "/" + to_string((newdate.tm_mon) + 1) + "/" + to_string((newdate.tm_year) + 1900);
	this->timeNow = to_string(newdate.tm_hour) + ":" + to_string(newdate.tm_min) + ":" + to_string(newdate.tm_sec);
}

string DateTime::getDate()
{
	return this->dateToday;
}
string DateTime::getTime()
{
	return this->timeNow;
}
string DateTime::getFileDate()
{

}