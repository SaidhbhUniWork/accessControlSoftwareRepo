#include "SystemAccessLogger.h"

SystemAccessLogger::SystemAccessLogger(string filename) : s_filename(filename)
{
	vector<string> localVect, decryptedVector;
	try
	{
		int count = 0;
		if_inFileLog.open(filename, ios::in);
		if (getline(if_inFileLog, s_fileLine).fail())	// if file is empty and no key/iv has been set
		{
			encDec.setNewFileEncryptionKeys(filename);	// set new file encryption keys
			encDec.getKeyArray(keyArray);
			encDec.getIvArray(ivArray);
		}
		else
		{
			do{				
				istringstream iss(s_fileLine);
				string locString = base64.decodeString(s_fileLine);
				localVect.push_back(locString);
				count++;
			} while (getline(if_inFileLog, s_fileLine) && count < 2);// 
		}
		if_inFileLog.close();
		if (localVect.size() == 2) {
			encDec.fullDecrypt(localVect, decryptedVector);
			encDec.getKeyArray(keyArray);
			encDec.getIvArray(ivArray);
			localVect.clear();
			decryptedVector.clear();
		}
	}
	catch (ofstream::failure)
	{
		cerr << "ERROR: Cannot open file : " << filename << endl;
	}
}

SystemAccessLogger::SystemAccessLogger(shared_ptr<LoggerAbs> thisLogger, string filename) : ptr_thisLogger{ move(thisLogger) }, s_filename(filename)
{
	vector<string> localVect;
	try
	{
		if_inFileLog.open(filename, ios::in);
		if (getline(if_inFileLog, s_fileLine).fail())	// if file is empty and no key/iv has been set
		{
			encDec.setNewFileEncryptionKeys(filename);	// set new file encryption keys
		}
		else
		{
			do {
				istringstream iss(s_fileLine);
				string locString = base64.decodeString(s_fileLine);
				localVect.push_back(locString);
			} while (getline(if_inFileLog, s_fileLine));
		}
		if_inFileLog.close();
		encDec.fullDecrypt(localVect, fileVector);
		encDec.getKeyArray(keyArray);
		encDec.getIvArray(ivArray);
		localVect.clear();
	}
	catch (ofstream::failure)
	{
		cerr << "ERROR: Cannot open file : " << filename << endl;
	}
}

SystemAccessLogger::~SystemAccessLogger() {
	try
	{
		if(if_inFileLog.is_open())
			of_outFileLog.close();
	}
	catch (ofstream::failure)
	{
		cerr << "ERROR: Cannot close file " << endl;
	}
	s_filename = "";
	s_fileLine = "";
	fileVector.clear();
}

void SystemAccessLogger::createLog(string p_uname)
{
	vector<string> loc_datetime = timeNow->getFileSaveString(p_uname);
	try
	{
		encDec.fullEncrypt(loc_datetime, keyArray, ivArray, s_filename);
	}
	catch (exception e)
	{
		cerr << "Error: could not write to file : " << e.what() << endl;
	}
}

void SystemAccessLogger::readFromFile(string fileName, vector<string> vect) {
	ptr_thisLogger->readFromFile(fileName, fileVector);
}
