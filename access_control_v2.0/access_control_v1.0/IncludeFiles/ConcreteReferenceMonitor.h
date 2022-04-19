#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "AuthEnum.h"
#include "ReferenceMonitorEnum.h"
#include "ReferenceMonitor.h"
#include "Subject.h"

using namespace std;

class ConcreteReferenceMonitor : public ReferenceMonitor
{
private:
	ifstream if_inFile;
	string s_fileName = "accessMatrix.txt";
	string s_fileLine = "";
	vector<vector<AuthEnum>> vect_accessMatrixVector;
	ReferenceMonitorEnum enum_FileType = ReferenceMonitorEnum::NONE;
	AuthEnum enum_subjectAuthorisation = AuthEnum::NONE;
public:
	ConcreteReferenceMonitor();
	~ConcreteReferenceMonitor();

	bool validateResourceAccess(Subject p_Subject, ReferenceMonitorEnum p_FileTypeSelection);
};

