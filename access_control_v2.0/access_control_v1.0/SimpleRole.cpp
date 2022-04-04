#include "SimpleRole.h"

SimpleRole::SimpleRole(string uname, shared_ptr<Role> role) : RoleBuilder(move(role)) {
	cout << "Simple Role aassigned" << endl;

	try {
		if_inFile.open(s_fileName, ios::in);
		while (getline(if_inFile, s_fileLine)) {
			istringstream iss(s_fileLine);
			iss >> s_uname >> uint_roleNum;
			map_roleMap[s_uname] = uint_roleNum;
		}
		if_inFile.close();
	}
	catch (exception e) {
		cerr << "Error opening file : " << e.what() << endl;
	}
	map <string, uint16_t>::iterator it;
	it = map_roleMap.find(uname);
	if (it != map_roleMap.end()) {
		if (!(it->first.compare(uname))) {
			this->_authLevel = it->second;
		}
	}
}

SimpleRole::~SimpleRole(void) {
	cout << "Simple Role destroyed" << endl;
	try {
		if (!if_inFile.fail()) {
			if_inFile.close();
		}
		for (size_t index = 0; index < map_roleMap.size(); index++) {
			map_roleMap.clear();
		}
	}
	catch (exception e) {
		cerr << "Error closing file : " << e.what() << endl;
	}
}

int SimpleRole::getRole(int role) {
	cout << "Simple Role : " << _authLevel << endl;
	_authLevel += role;
	return RoleBuilder::getRole(_authLevel);
}
