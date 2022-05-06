#include "LoggerViewerMethods.h"

void LoggerViewerMethods::setFileLogDate(uint16_t fileDay, uint16_t fileMonth, uint16_t fileYear) {
	this->fileDate = to_string(fileYear) + "-" + to_string(fileMonth) + "-" + to_string(fileDay);
	this->showDate = to_string(fileDay) + "/" + to_string(fileMonth) + "/" + to_string(fileYear);
}

string LoggerViewerMethods::getFileDate() {
	bool validDate = false;
	bool validSelection = false;
	while (!validDate) {
		cout << endl << VIEW_FILE_DATE_INPUT << endl << endl;

		cout << VIEW_FILE_DAY;
		cin >> this->fileDay;
		valid.inputValidataion_integer(1, fileDay, MAX_DAY);
		cout << VIEW_FILE_MONTH;
		cin >> this->fileMonth;
		valid.inputValidataion_integer(1, fileMonth, MAX_MONTH);
		cout << VIEW_FILE_YEAR;
		cin >> this->fileYear;
		valid.inputValidataion_integer(1, fileYear, MAX_YEAR);
		setFileLogDate(fileDay, fileMonth, fileYear);
		cout << endl << VIEW_FILE_FILEDATE << showDate << endl;
		cout << VIEW_FILE_DATE_CONFIRM;
		while (!validSelection) {
			char confirm;
			cin >> confirm;
			confirm = tolower(confirm);
			if (confirm == 'y') {
				validDate = true;
				validSelection = true;
				cin.ignore();
				break;
			}
			else if (confirm == 'n') {
				validDate = false;
				cin.ignore();
				break;
			}
			else {
				validSelection = false;
				cin.ignore();
				break;
			}
		}
	}
	return fileDate;
}

uint16_t LoggerViewerMethods::getFileSearchParameters() {
	int index = 0;
	uint16_t selection = 0;
	system("CLS");
	cout << endl << "FILTER FILE LOGS" << endl << endl;
	cout << ++index << ": By User Name? " << endl;
	cout << ++index << ": By Time Stamp?" << endl;
	cout << ++index << ": By User Name AND Time Stamp?" << endl;
	cout << ++index << ": View All? " << endl << endl;
	cout << "Enter Selection (1 to " << index << ") : ";
	cin >> selection;
	valid.inputValidataion_integer(1, selection, index);
	return selection;
}

void LoggerViewerMethods::getUserNameSearchParam(vector<string> p_filterVect) {
	cout << endl << "Enter Employee User Name : ";
	cin.clear();
	cin.ignore();
	getline(cin, logName);
	for (size_t i = 0; i < p_filterVect.size(); i++) {
		size_t nameExists = p_filterVect[i].find(logName);
		if (nameExists != string::npos)
			filteredVector.push_back(p_filterVect[i]);
	}
}

void LoggerViewerMethods::getDateSearchParam(vector<string> filterVect) {
	struct tm tm1;
	tm tm2;
	bool timeValid = false;
	bool validSelection = false;
	bool validTime = false;
	while (!validTime) {
		int hour = 0;
		int min = 0;
		int sec = 0;
		system("CLS");
		cout << endl << " --- TIME SEARCH RANGE ---" << endl << endl;
		while (!timeValid) {
			cin.clear();
			cin.ignore();
			cout << endl << "Enter the start time : " << endl;
			timeValid = getFileTimeInput(hour, min, sec, tm1);
		}
		timeValid = false;
		while (!timeValid) {
			cin.clear();
			cin.ignore();
			cout << endl << "Enter the end time : " << endl;
			timeValid = getFileTimeInput(hour, min, sec, tm2);
		}
		string thisHour, thisMin, thisSec;
		formatActualDateForResultFiltering(thisHour, tm1.tm_hour,thisMin, tm1.tm_min, thisSec, tm1.tm_sec);
		string t1 = thisHour + ":" + thisMin + ":" + thisSec;
		formatActualDateForResultFiltering(thisHour, tm2.tm_hour, thisMin, tm2.tm_min, thisSec, tm2.tm_sec);
		string t2 = thisHour + ":" + thisMin + ":" + thisSec;

		cout << endl << "Viewing records between " << t1 << " and " << t2 << endl << endl;
		vector<string> validFileVector;
		for (size_t j = 0; j < filterVect.size(); j++) {
			vector<string> tokenVect = tokeniseVector(filterVect[j]);
			string thisTime = tokenVect[2];
			if (t1 < thisTime && thisTime < t2) {
				validFileVector.push_back(filterVect[j]);
			}
		}
		if (validFileVector.size() == 0) {
			cout << "No files match this time range" << endl << endl;
			cout << "Search again? (Y or N)";
			while (!validSelection) {
				char confirm;
				cin >> confirm;
				confirm = tolower(confirm);
				if (confirm == 'y') {
					validTime = false;
					validSelection = true;
					cin.ignore();
					break;
				}
				else if (confirm == 'n') {
					validTime = true;
					validSelection = false;
					cin.ignore();
					break;
				}
				else {
					validSelection = false;
					cin.ignore();
					break;
				}
			}

		}
		else {
			formatStringOutput(validFileVector);
			validTime = true;
			break;
		}
	}
}

void LoggerViewerMethods::formatActualDateForResultFiltering(string& hour, int intHour, string& min, int intMin, string& sec,int intSec) {
	/* function checks if the string value of the integern number is a double digit number
	 * converts numbers < 10 to double digits
	 * e.g. 9 becomes 09 and 3 becomes 03 etc.*/
	if (intHour < 10) hour = "0" + to_string(intHour);
	else hour = to_string(intHour);
	if (intMin < 10) min = "0" + to_string(intMin);
	else min = to_string(intMin);
	if (intSec < 10) sec = "0" + to_string(intSec);
	else sec = to_string(intSec);
}

bool LoggerViewerMethods::getFileTimeInput(int& hour, int& min, int& sec, tm& tm) {
	/* gets user input for time stamp */
	cout << "Hour (00 to 23) : ";
	cin >> hour;
	cout << "Minutes (00 to 59) : ";
	cin >> min;
	cout << "Seconds (00 to 59) : ";
	cin >> sec;
	/* validates hour, min, sec */
	if (hour < 0 || hour > 23 || min < 0 || min > 59 || sec < 0 || sec > 59) {
		cout << endl << "Invalid time, try again" << endl;
		return false;
	}
	else {
		/* if time is valid, struct tm is populated with the hour, min,sec data */
		tm.tm_hour = hour;
		tm.tm_min = min;
		tm.tm_sec = sec;
		return true;
	}
}

void LoggerViewerMethods::filterResults(uint16_t userSelection, vector<string> vect) {
	fileVector = vect;
	if (userSelection == 1) {
		//search by username
		getUserNameSearchParam(fileVector);
		if (filteredVector.size() == 0) cout << "No files match this user name" << endl;
		else formatStringOutput(filteredVector);
	}
	else if (userSelection == 2) {
		//search by date and time
		getDateSearchParam(fileVector);
	}
	else if (userSelection == 3) {
		// search by username and time stamp
		getUserNameSearchParam(fileVector);
		getDateSearchParam(filteredVector);
	}
	else if (userSelection == 4) {
		// display all file logs unfiltered
		formatStringOutput(fileVector);
	}
}

void LoggerViewerMethods::formatStringOutput(vector<string> fileVector) {
	/* formats the file data*/
	cout << endl;
	for (size_t i = 0; i < fileVector.size(); i++) {
		vector<string> locVect = tokeniseVector(fileVector[i]);
		cout << " Name : " << locVect[0] << endl;
		cout << " Time : " << locVect[2] << endl;
		/* searches the locVect[1] to see if the string contains the string 'File'
		 * prints that string only if conditional is true */
		if (locVect[1].find("File", 0) ==0) {	
			cout << " File : " << locVect[1] << endl;
		}
		cout << "------------------------" << endl;
	}
	cout << endl << endl << "Returning to Main Menu" << endl << endl;
	system("pause");
}

vector<string> LoggerViewerMethods::tokeniseVector(string vectorString) {
	size_t pos = 0;
	string delim = " ";
	string token;
	vector<string> tokenVect;
	while ((pos = vectorString.find(delim)) != string::npos) {
		token = vectorString.substr(0, pos);
		vectorString.erase(0, pos + delim.length());
		tokenVect.push_back(token.c_str());
	}
	tokenVect.push_back(vectorString.c_str());
	return tokenVect;
}
