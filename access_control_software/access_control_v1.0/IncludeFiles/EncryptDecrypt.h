#pragma once
#include <stdio.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iterator>
#include <array>
#include <cstring>
#include <random>
#include <vector>
#include "Base64Encode.h"

class EncryptDecrypt
{
private:
	std::ifstream inFile;
	std::ofstream outFile;
	std::string fileName, fileLine;
	std::vector<std::string> fileVector;
	std::vector<std::string> decryptedVect;

	unsigned char keyArray[32] = {};
	unsigned char ivArray[16] = {};

	int ciphertext_len, decryptedtext_len;
	unsigned char ciphertext[256] = {};	// clearing the array
	unsigned char dexryptedtext[256] = {};	// clearing the array

public:
	void keyGen(int num, unsigned char* array);
	int encrypt(unsigned char* plaintext, int plaintext_len, unsigned char* key, unsigned char* iv, unsigned char* ciphertext);
	int decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key, unsigned char* iv, unsigned char* plaintext);
	void fullEncrypt(std::vector<std::string> vect, unsigned char* keyArray, unsigned char* ivArray);
	void fullDecrypt(std::vector<std::string> vect);
	void errorHandling(void);

	void initEncryption(std::string fileName);
	void writeEncryptedFile(std::string fileName, unsigned char* thisArr, int textLength);



};

