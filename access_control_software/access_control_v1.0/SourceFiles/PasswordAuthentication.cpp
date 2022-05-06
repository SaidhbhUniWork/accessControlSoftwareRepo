#include "PasswordAuthentication.h"

PasswordAuthentication::PasswordAuthentication(Subject &p_subject){
	this->s_uname = p_subject.getUsername();
	vector<string> localVect, decryptedVector;
	try {
		if_inFile.open(s_fileName, ios::in);
		while (getline(if_inFile, s_fileLine)) {
			istringstream iss(s_fileLine);
			string locString = base64.decodeString(s_fileLine);
			localVect.push_back(locString);
		}
		encDec.fullDecrypt(localVect, decryptedVector);
		for (size_t i = 0; i < decryptedVector.size(); i++) {
			tokenString(decryptedVector[i]);
		}
		if_inFile.close();
	}
	catch (exception e) {
		cerr << PASS_FOPEN_ERROR << e.what() << endl;
	}
}

void PasswordAuthentication::tokenString(string p_str){
	size_t pos = 0;
	string delim = " ";
	string token;
	while ((pos = p_str.find(delim)) != string::npos) {
		token = p_str.substr(0, pos);
		p_str.erase(0, pos + delim.length());
	}
	map_userPasswordMap[token] = p_str;
}

void PasswordAuthentication::updateUserPassword() {
	map<string, string>::iterator it;
	it = map_userPasswordMap.find(s_uname);
	if (it != map_userPasswordMap.end()) {
		it->second = s_newPassword;
	}
}

void PasswordAuthentication::generateNewPassword() {
	system("CLS");
	while (!validPassword) {
		cout << endl << PASS_INTRO << endl << endl;
		generatePassMenu();
		cin.clear();
		cin.ignore();
		cout << endl << "New Password : ";
		getline(cin, s_newPassword);
		validPassword = valid.passwordValidation(s_newPassword);
		if (validPassword) { 
			cout << endl << " Valid Password." << endl << endl;
			system("pause");
			break; }
		else {
			cout << endl << " Invalid Password, please try again." << endl << endl;
			system("pause");
		}
		system("CLS");
	}
	updateUserPassword();
	saveNewPassword();
}

void PasswordAuthentication::generatePassMenu() {
	cout << PASS_NEWPASS_INFO << endl;
	cout << PASS_REQ1 << endl;
	cout << PASS_REQ2 << endl;
	cout << PASS_REQ3 << endl;
	cout << PASS_REQ4 << endl;
	cout << PASS_REQ5 << endl;
}

void PasswordAuthentication::saveNewPassword() {
	encDec.setNewFileEncryptionKeys(s_tempFile);
	encDec.getKeyArray(keyArray);
	encDec.getIvArray(ivArray);
	string fileString = "";
	map<string, string>::iterator it;
	vector<string> localVector;
	it = map_userPasswordMap.begin();
	while (it != map_userPasswordMap.end()) {
		fileString = it->first + " " + it->second;
		localVector.push_back(fileString);
		it++;
	}
	encDec.fullEncrypt(localVector, keyArray, ivArray, s_tempFile);
	if (ifstream(s_fileName)) {
		remove(s_fileName.c_str());
		renameUserLoginFile(s_fileName);
	}
	else {
		renameUserLoginFile(s_fileName);
	}
}
void PasswordAuthentication::renameUserLoginFile(string deleteFile) {
	const int result = rename(s_tempFile.c_str(), deleteFile.c_str());
	if (result != 0) {
		perror("Error: Could not rename file");
	}
	else cout << endl << " --- PASSWORD UPDATED ---" << endl;
}
