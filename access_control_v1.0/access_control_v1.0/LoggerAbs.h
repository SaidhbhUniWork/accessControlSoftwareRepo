#pragma once

#include <string>
//#include "TimeDate.h"

using namespace std;

class LoggerAbs
{
public:
	//LoggerAbs() { }
	virtual void createLog(string p_uname) = 0;
	//virtual void readFromFile() = 0;
	virtual ~LoggerAbs() {}
};

