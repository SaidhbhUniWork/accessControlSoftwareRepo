#pragma once

#include "Subject.h"

class AuthenticatorAbs
{
public:
	virtual ~AuthenticatorAbs() {}

	virtual bool authenticate(Subject& sub) = 0;
};


