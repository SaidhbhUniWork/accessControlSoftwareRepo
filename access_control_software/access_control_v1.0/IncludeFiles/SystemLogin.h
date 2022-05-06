#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include "Subject.h"
#include "ConcreteAuthenticator1.h"
#include "ReferenceMonitor.h"
#include "ConcreteReferenceMonitor.h"
#include "AuthEnum.h"
#include "Validation.h"
#include "SystemLoginMenus.h"
#include "SystemAccessLogger.h"
#include "DeniedAccessLogger.h"
#include "LoggerViewer.h"
#include "LoggerAbs.h"
#include "LoggerTypeEnum.h"
#include "PasswordAuthentication.h"

using namespace std;

class SystemLogin
{
private:
	Validation validation;
	SystemLoginMenus sysMenu;
	LoggerViewer logView;
	//PasswordAuthentication pass(Subject& subject);
	string s_uname = "";
	string s_pword = "";
	string s_logFilePath = "";
	string s_filedate = "";
	bool isAuthenticated = false;
	ConcreteReferenceMonitor reference;
	std::shared_ptr<LoggerAbs> logger;
	std::shared_ptr<AuthenticatorAbs> authenticate = std::make_shared<ConcreteAuthenticator1>();
	vector<AuthEnum> enum_subjectAuth;
	std::vector<string> vect;

	ReferenceMonitorEnum fileTypeSelection = ReferenceMonitorEnum::NONE;
	AuthEnum accessRequestSelection = AuthEnum::NONE;

public:
	Subject mySubject;

	SystemLogin() {}

	void mainLogin();
	void getSystemLogin();
	void userMenu();
	void userSwitchMenu(uint16_t p_selection);
	void adminMenu();
	void adminSwitchMenu(uint16_t p_selection);
	uint16_t menuSelection(uint16_t minNum, uint16_t p_num);
	void authenticateLogin(Subject& sub);

	void objectTypeSelection();
	uint16_t objectTypeUserInput(uint16_t maxSelection);
	void getFileTypeSelectionFull();
	void getAccessRequestSelectionFull();
	void getLogViewSelectionFull();
	string createFilePathString(uint16_t fileLogType, uint16_t logType);
	void setLogger(uint16_t logType, uint16_t accessType, string fileDate);
	void readUserFiles(string filename, uint16_t accessLogType, uint16_t actualLogType);
};

