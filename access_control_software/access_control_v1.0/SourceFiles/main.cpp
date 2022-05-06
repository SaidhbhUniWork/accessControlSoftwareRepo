/* CURRENT VERSION */


#include <iostream>
#include <string>
#include <vector>
#include "SystemLogin.h"
#include "Encrypt.h"


using namespace std;

void initEncryptFile();

int main()
{
	SystemLogin login;

	login.mainLogin();
	return 0;
}


void initEncryptFile(){
	/* Function can be called if a new textfile
	 * to be encrypted for the first time.
	* Converts textfile from plaintext to encrypted strings*/
	EncryptDecrypt enc;
	std::string fileName = "assignPrivileges.txt";
	vector<string> decrypt;
	enc.initEncryption(fileName);
	enc.openFile("enc_assignPrivileges.txt");
	vector<string> encVector = enc.getVector();
	enc.fullDecrypt(encVector, decrypt);
}