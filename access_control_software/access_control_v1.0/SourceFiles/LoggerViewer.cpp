#include "LoggerViewer.h"

string LoggerViewer::returnFileDate() {
	this->fileDate = logMethods.getFileDate();
	return fileDate;
}

void LoggerViewer::readFromFile(string fileName, vector<string> vect) {
	this->fileVector = vect;
	uint16_t input = logMethods.getFileSearchParameters();
	logMethods.filterResults(input, fileVector);
}
