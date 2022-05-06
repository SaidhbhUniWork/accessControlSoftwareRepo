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
#include "Base64_encode.h"
#include "Types.h"

class EncryptDecrypt
{
private:
	Base64_encode base64;
	using byte = std::uint8_t;
	std::ifstream inFile;
	std::ofstream outFile;
	std::string fileName = "";
	std::string fileLine = "";
	std::vector<std::string> fileVector;
	std::vector<std::string> decryptedVect;

	unsigned char keyArray[ENC_KEY] = {};
	unsigned char ivArray[ENC_IV] = {};

	int ciphertext_len;
	int decryptedtext_len;
	unsigned char ciphertext[ENC_MAX_CIPHER_ARRAY] = {};	// clearing the array
	unsigned char dexryptedtext[ENC_MAX_CIPHER_ARRAY] = {};	// clearing the array

public:
	EncryptDecrypt();
	~EncryptDecrypt();
	void keyGen(int num, unsigned char* array);
	int encrypt(unsigned char* plaintext, int plaintext_len, unsigned char* key, unsigned char* iv, unsigned char* ciphertext);
	int decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key, unsigned char* iv, unsigned char* plaintext);
	void fullEncrypt(std::vector<std::string> vect, unsigned char* keyArray, unsigned char* ivArray, std::string encFileName);
	void fullDecrypt(std::vector<std::string> &vect, std::vector<std::string>& vectDecrypt);
	void errorHandling(void);

	void initEncryption(std::string fileName);
	void setNewFileEncryptionKeys(std::string p_fileName);
	void writeEncryptedFile(std::string fileName, unsigned char* thisArr, int textLength);

	void openFile(std::string fileName);

	inline void getKeyArray(unsigned char* keyArr) {
		for (int i = 0; i < ENC_KEY; i++) {
			keyArr[i] = this->keyArray[i];
		}
	}
	inline void getIvArray(unsigned char* ivArray) {
		for (int i = 0; i < ENC_IV; i++) {
			ivArray[i] = this->ivArray[i];
		}

	}

	inline std::vector<std::string> getVector() { return fileVector; }
};

