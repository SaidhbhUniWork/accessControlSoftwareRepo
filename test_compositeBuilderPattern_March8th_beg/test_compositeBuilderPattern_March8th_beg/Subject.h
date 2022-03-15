#pragma once
#include "CompositeRole.h"
#include "SimpleRole.h"
#include "Execute.h"
#include "Read.h"
#include "Write.h"
#include "FullAccess.h"
#include "AuthEnum.h"
#include <memory>
#include <iostream>

using namespace std;

class Subject
{
private:
	//shared_ptr<int> subjectAuth;
	int subjectAuth;
protected:
	shared_ptr<Role> buildRole;
	shared_ptr<Role> rolePtr;

public:
	void authorizeSubject();
	void simpleAuthorisation(int aggRole);
	void privilegeAuthorisation(int aggRole);
	void setAuthorisation(int subAuth);
	int getAuthorisation();
};

