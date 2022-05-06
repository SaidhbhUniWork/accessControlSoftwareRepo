#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class LoggerAbs
{
public:
	virtual void createLog(string p_uname) = 0;
	virtual void readFromFile(string fileName, vector<string> vect) = 0;
	virtual string returnFileDate() = 0;
};

