//#pragma once
//
//#include <string>
//#include <vector>
//#include <iostream>
//#include <fstream>
//#include "Base64Encode.h"
//#include "EncryptDecrypt.h"
//
//namespace InitEnc
//{
//	std::ifstream inFile;
//	std::ofstream outFile;
//	std::string fileName, fileLine;
//	std::vector<std::string> fileVector;
//	unsigned char keyArray[32] = {};
//	unsigned char ivArray[16] = {};
//	EncryptDecrypt encDec;
//
//	void initEncryption(std::string fileName) {
//		std::string localString = {};
//		inFile.open(fileName);
//		while (getline(inFile, fileLine)) {
//			localString = fileLine;
//			fileVector.push_back(localString);
//		}
//		inFile.close();
//
//		encDec.keyGen(32, keyArray);
//		InitEnc::writeEncryptedFile("enc_" + fileName, keyArray, 32);
//		encDec.keyGen(16, ivArray);
//		InitEnc::writeEncryptedFile("enc_" + fileName, keyArray, 16);
//
//		encDec.fullEncrypt(fileVector, keyArray, ivArray);
//		//unsigned char cipher[256] = encDec.getCiphertext();
//		//writeEncryptedFile("enc_" + fileName, cipher, encDec.getCipherLength());
//	}
//
//	void writeEncryptedFile(std::string fileName, unsigned char* thisArr, int textLength) {
//		std::string locString = "";
//		locString = thisArr[0];
//		for (int j = 1; j < textLength; j++)
//		{
//			locString += thisArr[j];
//		}
//		locString += "\0";
//		std::vector<base64::byte> encodeData(begin(locString), end(locString));
//		auto encodedString = base64::encode(encodeData);
//		outFile.open(fileName, std::ios::app);
//		outFile << encodedString;
//		outFile << std::endl;
//		outFile.close();
//	}
//
//}