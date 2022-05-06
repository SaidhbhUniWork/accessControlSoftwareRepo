#include "SystemLoginMenus.h"

void SystemLoginMenus::objectAccessRequestMenu(uint16_t& p_input) {
	cout << endl << ++p_input << ": Read Access" << endl;
	cout << ++p_input << ": Write Access" << endl;
	cout << ++p_input << ": Execute Access" << endl;
	cout << ++p_input << ": Full Access" << endl;
	cout << endl << "How to you wish to access this file (1 - 4) : ";
}

AuthEnum SystemLoginMenus::objectAccessRequestActualReturned(uint16_t selection) {
	switch (selection) {
	case 1: {
		return AuthEnum::R;
		break;
	}
	case 2: {
		return AuthEnum::W;
		break;
	}
	case 3: {
		return AuthEnum::E;
		break;
	}
	case 4: {
		return AuthEnum::FA;
		break;
	}
	default: {
		return AuthEnum::NONE;
		break;
	}
	}
}

void SystemLoginMenus::objectTypeMenu(uint16_t& p_input) {
	system("CLS");
	cout << endl << " --- SELECT FILE TO ACCESS ---" << endl << endl;
	cout << ++p_input << ": File Type 1" << endl;
	cout << ++p_input << ": File Type 2" << endl;
	cout << ++p_input << ": File Type 3" << endl;
	cout << ++p_input << ": File Type 4" << endl;
	cout << ++p_input << ": File Type 5" << endl;
	cout << ++p_input << ": File Type 6" << endl;

	cout << endl << "Which File do you wish to access (1 - " << p_input << ") : ";
}

ReferenceMonitorEnum SystemLoginMenus::objectTypeActualReturned(uint16_t selection) {
	switch (selection) {
	case 1: {
		return ReferenceMonitorEnum::FILE1;
		break;
	}
	case 2: {
		return ReferenceMonitorEnum::FILE2;
		break;
	}
	case 3: {
		return ReferenceMonitorEnum::FILE3;
		break;
	}
	case 4: {
		return ReferenceMonitorEnum::FILE4;
		break;
	}
	case 5: {
		return ReferenceMonitorEnum::FILE5;
		break;
	}
	case 6: {
		return ReferenceMonitorEnum::FILE6;
		break;
	}

	default: {
		return ReferenceMonitorEnum::NONE;
		break;
	}
	}
}

void SystemLoginMenus::logViewMainMenu(uint16_t& p_input) {
	system("CLS");
	cout << endl << "File Logs Viewer" << endl << endl;
	cout << "Choose File Log type" << endl << endl;
	cout << ++p_input << ": User Access Logs" << endl;
	cout << ++p_input << ": File Access Logs" << endl;
	cout << endl << "Which User Logs do you wish to view (1 - " << p_input << ") : ";
}

void SystemLoginMenus::accessLogMenu(uint16_t& p_input) {
	system("CLS");
	p_input = 0;
	cout << endl << "Viewing User File Logs." << endl << endl;
	cout << ++p_input << ": Access: Success" << endl;
	cout << ++p_input << ": Access: Denied" << endl;
	cout << "(1 or " << p_input << ") : ";
}