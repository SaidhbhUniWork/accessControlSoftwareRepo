#include "ConcreteReferenceMonitor.h"

ConcreteReferenceMonitor::ConcreteReferenceMonitor(){

	vector<AuthEnum> l_tempVect;
	vector<string> locVector, decryptedVector;
	try {
		if_inFile.open(s_fileName, ios::in);		// open "enc_accessMatrix.txt"
		while (getline(if_inFile, s_fileLine)) {
			istringstream iss(s_fileLine);
			string locString = base64.decodeString(s_fileLine);
			locVector.push_back(locString);
		}
		encDec.fullDecrypt(locVector, decryptedVector);
		for (size_t i = 0; i < decryptedVector.size(); i++) {
			tokenString(decryptedVector[i]);
		}
		if_inFile.close();
	}
	catch (exception e) {
		cerr << REF_NO_FILE << e.what() << endl;
	}
}

void ConcreteReferenceMonitor::tokenString(string str) {
	size_t pos = 0;
	string delim = "\t";
	string token;
	uint16_t thisRole = 0;
	vector<string> tokenVect;
	vector<AuthEnum> authVect;
	while ((pos = str.find(delim)) != string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + delim.length());
		tokenVect.push_back(token);
	}
	tokenVect.push_back(str);
	thisRole = atoi(tokenVect[0].c_str());
	for (size_t i = 1; i < tokenVect.size(); i++) {
		authVect.push_back((AuthEnum)(atoi(tokenVect[i].c_str())));
	}
	map_SubjectAccessMap[thisRole] = authVect;
}

ConcreteReferenceMonitor::~ConcreteReferenceMonitor() {
	try {
		if (!if_inFile.fail()) {
			if_inFile.close();
		}
		for (size_t index = 0; index < vect_accessMatrixVector.size(); index++) {
			vect_accessMatrixVector.clear();
		}
	}
	catch (exception e) {
		cerr << REF_CLOSE_FAIL << e.what() << endl;
	}
}

bool ConcreteReferenceMonitor::validateResourceAccess(Subject &p_Subject, ReferenceMonitorEnum p_FileTypeSelection, AuthEnum p_AccessRequest){
	uint_SubjectRole = p_Subject.returnSubjectRoleFromSimpleRole(p_Subject.getUsername());
	this->enum_FileType = p_FileTypeSelection;
	AuthEnum actualRolePermissionFileType = accessActualPermission(uint_SubjectRole);	//permissions assigned to that subject's role from axxess matrix
	string loc_datetime = timeNow->getReferenceMonitorSaveString(p_Subject.getUsername(), enum_FileType); // generates the file string
	/* tests the users assigned privilege for the selected file type
	 * against their requested access type 
	 * if they do not have sufficient privileges
	 * they are denied access */
	if ((int)actualRolePermissionFileType & ((int)p_AccessRequest | (int)AuthEnum::FA)) {	
		setLogger(LoggerTypeEnum::RESOURCE_ACCESS);
		logger->createLog(loc_datetime);
		return true;
	}
	else {
		setLogger(LoggerTypeEnum::RESOURCE_DENIED);
		logger->createLog(loc_datetime);
		return false;
	}
}

void ConcreteReferenceMonitor::setLogger(LoggerTypeEnum p_logType) {
	string loc_fileDate = timeNow->getFileDate();
	switch (p_logType) {
	case LoggerTypeEnum::RESOURCE_ACCESS:
		s_logFilePath = RESOURCE_ACCESS_FPATH + loc_fileDate + RESOURCE_ACCESS_LOGGER;	 // creates unique filename for current date
		logger = make_shared<ResourceAccessSuccess>(s_logFilePath);
		break;
	case LoggerTypeEnum::RESOURCE_DENIED:
		s_logFilePath = RESOURCE_DENIED_FPATH + loc_fileDate + RESOURCE_DENIED_LOGGER;
		logger = make_shared<ResourceAccessDenied>(s_logFilePath);
		break;
	default:
		cout << REF_NO_LOG << endl;
	}
}

AuthEnum ConcreteReferenceMonitor::accessActualPermission(uint16_t uint_SubjectRole) {
	map<uint16_t, vector<AuthEnum>>::iterator it;
	try {
		it = map_SubjectAccessMap.find(uint_SubjectRole);
			if (it != map_SubjectAccessMap.end()) {
				if ((int)enum_FileType <= it->second.size()) {
					return it->second[(int)enum_FileType-1];
				}
				else return AuthEnum::NONE;
			}
			else return AuthEnum::NONE;
	}
	catch (exception e) {
		cerr << REF_PERMS_ERROR << e.what() << endl;
	}
}