
#include "TimeDate.h"

DateTime::DateTime()
{
	time_t now = time(0);
	localtime_s(&newdate, &now);
	this->uint_hour = newdate.tm_hour;
	this->uint_min = newdate.tm_min;
	this->uint_sec = newdate.tm_sec;
	if (uint_hour < 10) s_hour = "0" + to_string(uint_hour);
	else s_hour = to_string(uint_hour);
	if (uint_min < 10) s_min = "0" + to_string(uint_min);
	else s_min = to_string(uint_min);
	if (uint_sec < 10) s_sec = "0" + to_string(uint_sec);
	else s_sec = to_string(uint_sec);

	this->s_dateToday = to_string(newdate.tm_mday) + "/" + to_string((newdate.tm_mon) + 1) + "/" + to_string((newdate.tm_year) + 1900);
	this->s_timeNow = s_hour + ":" + s_min + ":" + s_sec;
	this->s_filedate = to_string((newdate.tm_year) + 1900) + "-" + to_string((newdate.tm_mon) + 1) + "-" + to_string(newdate.tm_mday);
}

string DateTime::getDate()
{
	return this->s_dateToday;
}
string DateTime::getTime()
{
	time_t now = time(0);
	localtime_s(&newdate, &now);
	this->uint_hour = newdate.tm_hour;
	this->uint_min = newdate.tm_min;
	this->uint_sec = newdate.tm_sec;
	if (uint_hour < 10) s_hour = "0" + to_string(uint_hour);
	else s_hour = to_string(uint_hour);
	if (uint_min < 10) s_min = "0" + to_string(uint_min);
	else s_min = to_string(uint_min);
	if (uint_sec < 10) s_sec = "0" + to_string(uint_sec);
	else s_sec = to_string(uint_sec);
	this->s_timeNow = s_hour + ":" + s_min + ":" + s_sec;

	return this->s_timeNow;
}
string DateTime::getFileDate()
{
	return this->s_filedate;
}

vector<string> DateTime::getFileSaveString(string p_uname) {
	vector<string> locVect;
	s_fileDate = getDate();
	s_fileTime = getTime();
	string loc_datetime = p_uname + " " + s_fileDate + " " + s_fileTime;
	locVect.push_back(loc_datetime);

	return locVect;
}

string DateTime::getReferenceMonitorSaveString(string p_uname, ReferenceMonitorEnum p_fileTypeSelection) {
	s_fileTime = getTime();
	convertFileEnumToString(s_filetype, p_fileTypeSelection);
	//p_uname + " " + s_filetype + " " + s_fileTime;
	return p_uname + " " + s_filetype + " " + s_fileTime;
}

void DateTime::convertFileEnumToString(string& p_fileTypeString, ReferenceMonitorEnum p_fileTypeSelection) {
	switch ((ReferenceMonitorEnum)p_fileTypeSelection) {
		case ReferenceMonitorEnum::FILE1:
			p_fileTypeString = "File1";
			break;
		case ReferenceMonitorEnum::FILE2:
			p_fileTypeString = "File2";
			break;
		case ReferenceMonitorEnum::FILE3:
			p_fileTypeString = "File3";
			break;
		case ReferenceMonitorEnum::FILE4:
			p_fileTypeString = "File4";
			break;
		case ReferenceMonitorEnum::FILE5:
			p_fileTypeString = "File5";
			break;
		case ReferenceMonitorEnum::FILE6:
			p_fileTypeString = "File6";
			break;
		case ReferenceMonitorEnum::NONE:
			p_fileTypeString = "None";
			break;
		default:
			cout << "File Selection Error" << endl;
			break;	
	}
}