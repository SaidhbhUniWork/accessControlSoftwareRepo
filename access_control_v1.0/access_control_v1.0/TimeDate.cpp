
#include "TimeDate.h"

DateTime::DateTime()
{

	time_t now = time(0);
	localtime_s(&newdate, &now);
	this->s_dateToday = to_string(newdate.tm_mday) + "/" + to_string((newdate.tm_mon) + 1) + "/" + to_string((newdate.tm_year) + 1900);
	this->s_timeNow = to_string(newdate.tm_hour) + ":" + to_string(newdate.tm_min) + ":" + to_string(newdate.tm_sec);
	this->s_filedate = to_string(newdate.tm_mday) + to_string((newdate.tm_mon) + 1) + to_string((newdate.tm_year) + 1990);

}

string DateTime::getDate()
{
	return this->s_dateToday;
}
string DateTime::getTime()
{
	return this->s_timeNow;
}
string DateTime::getFileDate()
{
	return this->s_filedate;
}