#pragma once

enum class AuthEnum
{
	// user roles
	NONE = 0,
	HIGH = 1,
	MED = 2,
	LOW = 4,
	// user privileges
	NA = 8,		// no access
	R = 16,		// read access
	W = 32,		// write access
	E = 64,		// execute access
	FA = 128,	// full access
	AD = 256	// admin access
};
