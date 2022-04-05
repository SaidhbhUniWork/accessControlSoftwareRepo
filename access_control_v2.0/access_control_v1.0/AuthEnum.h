#pragma once

enum class AuthEnum
{
	NONE = 0,
	HIGH = 1,
	MED = 2,
	LOW = 4,

	R = 8,
	W = 16,
	E = 32,
	FA = 64,
	AD = 128
};
