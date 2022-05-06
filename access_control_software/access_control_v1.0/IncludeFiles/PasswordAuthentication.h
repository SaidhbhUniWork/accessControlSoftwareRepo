#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <memory>
#include "Types.h"
#include "Encrypt.h"
#include "Base64_encode.h"
#include "Subject.h"
#include "Validation.h"

using namespace std;

class PasswordAuthentication
{
private:
	EncryptDecrypt encDec;
	Base64_encode base64;
	Validation valid;
	shared_ptr<Subject> thisSubject;
	stringstream ss;
	ifstream if_inFile;
	string s_uname = "";
	string s_fileLine = "";
	string s_fileName = PASS_FNAME;
	string s_tempFile = "temp.txt";
	string s_newPassword = "";
	vector<string> vect_userPasswordVect;
	map<string, string> map_userPasswordMap;
	bool validPassword = false;
	unsigned char passArray[20] = {};
	unsigned char keyArray[ENC_KEY] = {};
	unsigned char ivArray[ENC_IV] = {};
public:
	PasswordAuthentication() {}
	PasswordAuthentication(Subject& p_subject);
	void generateNewPassword();
	void generatePassMenu();
	void tokenString(string p_str);
	void updateUserPassword();
	void saveNewPassword();
	void renameUserLoginFile(string deleteFile);
};

