#pragma once

enum class AuthLevelEnum : uint16_t
{
	NONE = 0,
	ADMIN = 1,
	LIMITED = 2,
	USER = 4,
	//BONUS = 8
};
