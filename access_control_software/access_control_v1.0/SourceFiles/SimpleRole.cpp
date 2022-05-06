#include "SimpleRole.h"

SimpleRole::SimpleRole(string uname, shared_ptr<Role> role) : RoleBuilder(move(role)) {
	this->_authLevel = 0;
	this->uint_roleNum = 0;
	vector<string> locVector, decryptedVector;
	try {
		if_inFile.open(s_fileName, ios::in);
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
		cerr << SIMPLE_FOPEN_ERROR << e.what() << endl;
	}
	map <string, uint16_t>::iterator it;
	it = map_roleMap.find(uname);
	if (it != map_roleMap.end()) {
		if (!(it->first.compare(uname))) {
			this->_authLevel = it->second;
			this->authorizationVector.push_back((AuthEnum)_authLevel);
		}
	}
}

void SimpleRole::tokenString(string str) {
	size_t pos = 0;
	string delim = " ";
	string token;
	vector<string> tokenVect;
	while ((pos = str.find(delim)) != string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + delim.length());
	}
	map_roleMap[token] = atoi(str.c_str());

}


SimpleRole::~SimpleRole(void) {
	try {
		if (!if_inFile.fail()) {
			if_inFile.close();
		}
		for (size_t index = 0; index < map_roleMap.size(); index++) {
			map_roleMap.clear();
		}
	}
	catch (exception e) {
		cerr << SIMPLE_FCLOSE_ERROR << e.what() << endl;
	}
}

int SimpleRole::getRole(int role) {
	//cout << "Simple Role : " << _authLevel << endl;
	_authLevel += role;
	authorizationVector.push_back((AuthEnum)role);
	return RoleBuilder::getRole(_authLevel);
}
