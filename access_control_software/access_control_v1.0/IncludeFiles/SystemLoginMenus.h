#pragma once
#include <iostream>
#include "AuthEnum.h"
#include "ReferenceMonitorEnum.h"
using namespace std;

class SystemLoginMenus
{
private:

public:
	void objectAccessRequestMenu(uint16_t& p_input);
	AuthEnum objectAccessRequestActualReturned(uint16_t selection);
	void objectTypeMenu(uint16_t& p_input);
	ReferenceMonitorEnum objectTypeActualReturned(uint16_t selection);
	void logViewMainMenu(uint16_t& p_input);
	void accessLogMenu(uint16_t& p_input);
};

