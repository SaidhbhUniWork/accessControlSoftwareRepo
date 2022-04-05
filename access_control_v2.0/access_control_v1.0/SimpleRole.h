#pragma once
#include "RoleBuilder.h"
#include "AuthEnum.h"
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class SimpleRole : public RoleBuilder
{
private:
	string s_fileLine;
	string s_fileName = "assignRole.txt";
	ifstream if_inFile;
	string s_uname;
	uint16_t uint_roleNum;
	map<string, uint16_t> map_roleMap;
protected:
	uint16_t _authLevel;
	vector<AuthEnum> authorizationVector;
public:
	SimpleRole(string name, shared_ptr<Role> auth = nullptr);
	uint16_t returnAuthLevelFromRole() { return _authLevel; }
	~SimpleRole(void);
	int getRole(int role) override;
};

