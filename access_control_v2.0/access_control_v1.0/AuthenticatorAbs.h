#pragma once

#include "Subject.h"

class AuthenticatorAbs
{
public:
	//AuthenticatorAbs() {}
	virtual ~AuthenticatorAbs() {}

	virtual uint16_t authenticate(Subject& sub) = 0;
};


