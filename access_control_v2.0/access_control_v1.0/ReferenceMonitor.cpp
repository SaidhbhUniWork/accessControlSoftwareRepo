#include "ReferenceMonitor.h"

ReferenceMonitor::ReferenceMonitor() {
	cout << "Reference Monitor created" << endl;
	uint16_t tempAuth;
	vector<AuthEnum> tempVect;
	try {
		if_inFile.open(s_fileName, ios::in);
		while (getline(if_inFile, s_fileLine)) {
			istringstream iss(s_fileLine);
			while (iss >> tempAuth) {
				tempVect.push_back((AuthEnum)tempAuth);
			}
			vect_accessMatrixVector.push_back(tempVect);
			tempVect.clear();
		}
		if_inFile.close();
	}
	catch (exception e) {
		cerr << "Could not open File : " << e.what() << endl;
	}
}

ReferenceMonitor::~ReferenceMonitor() {
	cout << "Reference Monitor destroyed" << endl;
	try {
		if (!if_inFile.fail()) {
			if_inFile.close();
		}
		for (size_t index = 0; index < vect_accessMatrixVector.size(); index++) {
			vect_accessMatrixVector.clear();
		}
	}
	catch (exception e) {
		cerr << "File close failed : " << e.what() << endl;
	}
}

void ReferenceMonitor::objectTypeSelection() {
	objectTypeMenu();
	cin >> uint_objectRequestType;
	while (uint_objectRequestType < 1 || uint_objectRequestType > 4) {
		cout << "Incorrect file type, please select 1 - 4 : ";
		cin >> uint_objectRequestType;
	}

	switch (uint_objectRequestType)
	{
	case static_cast<uint16_t>(ReferenceMonitorEnum::FILE1): {
		cout << "1" << endl;
		break;
	}
	case static_cast<uint16_t>(ReferenceMonitorEnum::FILE2): {
		cout << "2" << endl;
		break;
	}
	case static_cast<uint16_t>(ReferenceMonitorEnum::FILE3): {
		cout << "3" << endl;
		break;
	}
	case static_cast<uint16_t>(ReferenceMonitorEnum::FILE4): {
		cout << "4" << endl;
		break;
	}
	default:
		cout << "Incorrect File type selected" << endl;
		break;
	}
}

void ReferenceMonitor::objectTypeMenu() {
	cout << (uint16_t)ReferenceMonitorEnum::FILE1 << " File Type 1" << endl;
	cout << (uint16_t)ReferenceMonitorEnum::FILE2 << " File Type 2" << endl;
	cout << (uint16_t)ReferenceMonitorEnum::FILE4 << " File Type 3" << endl;
	cout << (uint16_t)ReferenceMonitorEnum::FILE4 << " File Type 4" << endl;
	cout << endl << "Which File do you wish to access (1 - 4) : ";
}