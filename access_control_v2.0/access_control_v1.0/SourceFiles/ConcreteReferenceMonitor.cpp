#include "ConcreteReferenceMonitor.h"

ConcreteReferenceMonitor::ConcreteReferenceMonitor() {
	cout << "Concrete Reference Monitor created" << endl;
	uint16_t tempAuth;
	vector<AuthEnum> tempVect;
	try {
		if_inFile.open(s_fileName, ios::in);		// open "accessMatrix.txt"
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

ConcreteReferenceMonitor::~ConcreteReferenceMonitor() {
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

bool ConcreteReferenceMonitor::validateResourceAccess(Subject p_Subject, ReferenceMonitorEnum p_FileTypeSelection){
	this->enum_FileType = p_FileTypeSelection;
	enum_subjectAuthorisation = p_Subject.getAuthorisation()[0];
}