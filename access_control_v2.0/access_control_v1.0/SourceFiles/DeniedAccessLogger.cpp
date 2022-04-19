#include "DeniedAccessLogger.h"

DeniedAccessLogger::DeniedAccessLogger(string filename) : s_filename(filename)
{
	try
	{
		of_outFileLog.open(filename, ios::out | ios::app);
	}
	catch (ofstream::failure)
	{
		cerr << "ERROR: Cannot open file : " << filename << endl;
	}

}


void DeniedAccessLogger::createLog(string p_uname)
{
	string loc_date = timeNow->getDate();
	string loc_time = timeNow->getTime();
	string loc_datetime = p_uname + " " + loc_date + " " + loc_time;
	streamsize ss = loc_datetime.size();
	try
	{
		of_outFileLog.write(loc_datetime.c_str(), ss);
		of_outFileLog << endl;
	}
	catch (exception e)
	{
		cerr << "Error: could not write to file : " << e.what() << endl;
	}
	cout << p_uname << endl;
	cout << loc_date << endl;
	cout << loc_time << endl;
}