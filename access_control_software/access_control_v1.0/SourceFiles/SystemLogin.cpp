#include "SystemLogin.h"

void SystemLogin::mainLogin()
{
	bool exitLogin = false;
	char loginChar;
	cout << endl << LOGIN_INTRO << endl << endl;
	while (isAuthenticated == false && exitLogin == false) {
		getSystemLogin();
		authenticateLogin(mySubject);	// authenticate subject against stored credentials

		if (isAuthenticated) {
			enum_subjectAuth = mySubject.authorizeSubject();	// allocate subject permissions
			break;
		}
		else {
			cout << LOGIN_ERROR << endl;
			cin >> loginChar;
			loginChar = tolower(loginChar);
			if (loginChar == LOGIN_ERROR_REPLY1) {
				break;
			}
			else if (loginChar == 0) {
				system("CLS");
				cout << endl << LOGIN_EXIT << endl;
				break;
			}
			else {
				cin.ignore();	//clear the input buffer
				system("cls");
				continue;
			}
		}
	}
	if (isAuthenticated)
	{
		if (mySubject.getSubjectRole() == (int)AuthEnum::AD) {
			adminMenu();
		}
		else if (mySubject.getSubjectAuthLevel() != (int)AuthEnum::NONE) {
			userMenu();
		}
	}	
}

void SystemLogin::userMenu() {
	uint16_t loc_userSelection = 0;
	bool logOut = false;
	while (logOut == false) {
		system("CLS");
		cout << endl << LOGIN_U_MENU << endl << endl;
		uint16_t index = 0;
		cout << ++index << LOGIN_U_RES << endl;
		cout << ++index << LOGIN_U_PASS << endl;
		cout << LOGIN_U_CHOICE << endl << endl;
		loc_userSelection = menuSelection(0, index);
		if (loc_userSelection != 0) {
			userSwitchMenu(loc_userSelection);
		}
		else logOut = true;
	}
}

void SystemLogin::userSwitchMenu(uint16_t p_selection) {
	switch (p_selection) {
	case 1: {
		// access resources
		if (enum_subjectAuth[0] != AuthEnum::NONE) {
			objectTypeSelection();
			bool temp = reference.validateResourceAccess(mySubject, fileTypeSelection, accessRequestSelection);
			if (temp) cout << endl << "Access Granted!" << endl << endl; //TODO: do something here with these results
			else cout << endl << "Access Denied: Insufficient Privileges!" << endl << endl;

			system("pause");
		}
		break;
	}
	case 2: {
		//change password
		if (enum_subjectAuth[0] != AuthEnum::NONE) {
			PasswordAuthentication pass(mySubject);//
			pass.generateNewPassword();
		}
		break;
	}
	}
}

void SystemLogin::adminMenu() {
	uint16_t loc_userSelection = 0;
	bool logOut = false;
	while (logOut == false) {
		system("CLS");
		cout << endl << LOGIN_AD_MENU << endl << endl;
		uint16_t index = 0;
		cout << ++index << LOGIN_M_RES << endl;
		cout << ++index << LOGIN_M_PASS << endl;
		cout << ++index << LOGIN_M_REQ << endl;
		cout << ++index << LOGIN_M_LOG << endl;
		cout << LOGIN_M_CHOICE << endl << endl;
		loc_userSelection = menuSelection(0, index);
		if (loc_userSelection != 0) {
			adminSwitchMenu(loc_userSelection);
		}
		else logOut = true;
	}
}

void SystemLogin::adminSwitchMenu(uint16_t p_selection) {
	switch (p_selection) {
	case 1: {
		// access files
		if (mySubject.getSubjectRole() == (int)AuthEnum::AD) {
			getFileTypeSelectionFull();
			this->accessRequestSelection = AuthEnum::FA;
			bool temp = reference.validateResourceAccess(mySubject, fileTypeSelection, accessRequestSelection);
			if (temp) cout << "TRUE!" << endl;
			else cout << "FALSE!" << endl;
		}
		break;
	}
	case 2: {
		// change password
		if (mySubject.getSubjectRole() == (int)AuthEnum::AD) {
			PasswordAuthentication pass(mySubject);//
			pass.generateNewPassword();
		}
		break;
	}

	case 3: {
		//subject.enhanceSubjectPrivileges(AuthEnum::AD);
		cout << "Enhance Privileges" << endl;
		break;
	}

	case 4: {
		// view file logs
		if (mySubject.getSubjectRole() == (int)AuthEnum::AD) {
			getLogViewSelectionFull();
		}
		break;
	}

	default:
		break;
	}
}

uint16_t SystemLogin::menuSelection(uint16_t minNum, uint16_t p_num) {
	uint16_t locNum = 0;
	cout << LOGIN_M_SELECT << minNum << "-" << p_num << ") : ";
	cin >> locNum;
	validation.inputValidataion_integer(minNum, locNum, p_num);
	return locNum;
}

void SystemLogin::getSystemLogin() {
	cout << LOGIN_ENTRY << endl;
	cout << LOGIN_DIVIDE << endl;
	cout << LOGIN_UNAME_ENTRY;
	getline(cin, this->s_uname);
	cout << LOGIN_PWORD_ENTRY;
	getline(cin, this->s_pword);
	mySubject.setAllSubjectCredentials(s_uname, s_pword);
}

void SystemLogin::authenticateLogin(Subject& sub) {
	isAuthenticated = authenticate->authenticate(sub);
}

void SystemLogin::objectTypeSelection() {
	getFileTypeSelectionFull();
	getAccessRequestSelectionFull();
}

void SystemLogin::getFileTypeSelectionFull() {
	uint16_t index = 0;
	sysMenu.objectTypeMenu(index);
	this->fileTypeSelection = sysMenu.objectTypeActualReturned(objectTypeUserInput(index));
}

void SystemLogin::getAccessRequestSelectionFull() {
	uint16_t index = 0;
	sysMenu.objectAccessRequestMenu(index);
	this->accessRequestSelection = sysMenu.objectAccessRequestActualReturned(objectTypeUserInput(index));
}

void SystemLogin::getLogViewSelectionFull()
{
	bool validFile = false;
	uint16_t index = 0;
	sysMenu.logViewMainMenu(index);
	uint16_t logType = objectTypeUserInput(index);
	sysMenu.accessLogMenu(index);
	uint16_t fileLogType = objectTypeUserInput(index);
	while (!validFile) {
		s_filedate = logView.returnFileDate();						// selected file date returned
		s_logFilePath = createFilePathString(fileLogType, logType);	// required file path generated
		ifstream if_inFile; // check if file exists before attempting to open
		if (ifstream(s_logFilePath)) {
			validFile = true;
		}
		else {
			cout << LOGIN_NO_FILE << endl;
		}
	}
	readUserFiles(s_logFilePath, fileLogType, logType);
}

string SystemLogin::createFilePathString(uint16_t fileLogType, uint16_t logType) {
	if(logType == 1) {
		if (fileLogType == 1) {
			// creates unique filename for current date
			return SYSTEM_ACCESS_FPATH + s_filedate + SYSTEM_ACCESS_LOGGER;	 
		}
		else if (fileLogType == 2) {
			return DENIED_ACCESS_FPATH + s_filedate + DENIED_ACCESS_LOGGER;
		}
	}
	else if (logType == 2) {
		if (fileLogType == 1) {
			return RESOURCE_ACCESS_FPATH + s_filedate + RESOURCE_ACCESS_LOGGER;
		}
		else if (fileLogType == 2) {
			return RESOURCE_DENIED_FPATH + s_filedate + RESOURCE_DENIED_LOGGER;
		}
	}
	return LOGIN_NO_PATH;
}

void SystemLogin::readUserFiles(string s_logFilePath, uint16_t accessLogType, uint16_t logType) {
	logger = make_shared<LoggerViewer>();
	setLogger(accessLogType, logType,  s_logFilePath);
	logger->readFromFile(s_logFilePath, vect);
}

uint16_t SystemLogin::objectTypeUserInput(uint16_t maxSelection) {
	uint16_t uint_objectRequestType = 0;
	cin >> uint_objectRequestType;
	while (uint_objectRequestType < 1 || uint_objectRequestType > maxSelection) {
		cout << LOGIN_ERROR_INPUT << maxSelection << " : ";
		cin >> uint_objectRequestType;
	}
	return uint_objectRequestType;
}
void SystemLogin::setLogger(uint16_t accessLogType, uint16_t logType, string filepath) { // accessLogType = success/denied, logtype = user/file access
	switch (logType) {
	case 1: {	// user authentication log files

		if (accessLogType == 1) {
			logger = make_shared<SystemAccessLogger>(move(logger), filepath);
			break;
		}
		else if (accessLogType == 2) {
			logger = make_shared<DeniedAccessLogger>(move(logger), filepath);
			break;
		}
	}
	case 2: {	// reference validation file logs
		if (accessLogType == 1) {
			logger = make_shared<ResourceAccessSuccess>(move(logger), filepath);
			break;
		}
		else if (accessLogType == 2) {
			logger = make_shared<ResourceAccessDenied>(move(logger), filepath);
			break;
		}
	}
	default:
			cout << LOGIN_NO_LOG << endl;
	}
}


