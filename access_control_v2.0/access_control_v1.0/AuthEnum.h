#pragma once

enum class AuthEnum
{
	NONE = 0,
	ADMIN = 1,
	USER = 2,
	R = 4,
	W = 8,
	E = 16,
	FA = 32,
	AD = 64
};
