#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "AuthEnum.h"
#include "ReferenceMonitorEnum.h"

using namespace std;

class ReferenceMonitor
{
private:
	uint16_t uint_objectRequestType = 0;
	ifstream if_inFile;
	string s_fileName = "accessMatrix.txt";
	string s_fileLine = "";
	vector<vector<AuthEnum>> vect_accessMatrixVector;
public:
	ReferenceMonitor();
	~ReferenceMonitor();
	void objectTypeSelection();
	void objectTypeMenu();
};

