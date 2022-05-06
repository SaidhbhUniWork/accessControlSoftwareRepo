#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <vector>
#include "LoggerAbs.h"
#include "TimeDate.h"
#include "Encrypt.h"
#include "Base64_encode.h"
#include "Types.h"

class ResourceAccessDenied : public LoggerAbs
{
private:
	EncryptDecrypt encDec;
	Base64_encode base64;
	string s_filename = "";
	string s_fileLine = "";
	ofstream of_outFileLog;
	ifstream if_inFileLog;
	unsigned char keyArray[ENC_KEY] = {};
	unsigned char ivArray[ENC_IV] = {};
	vector<string> fileVector;
protected:
	shared_ptr<DateTime> timeNow = make_shared<DateTime>();
	shared_ptr<LoggerAbs> ptr_thisLogger;
public:
	ResourceAccessDenied(shared_ptr<LoggerAbs> thisLogger, const string p_filename);
	ResourceAccessDenied(const string p_filename);

	~ResourceAccessDenied();
	void createLog(string p_filename) override;
	void readFromFile(string fileName, vector<string> vect) override;
	inline string returnFileDate() { return ""; }
};

