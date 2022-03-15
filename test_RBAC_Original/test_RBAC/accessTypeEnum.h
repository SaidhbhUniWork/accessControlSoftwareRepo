#pragma once

enum class AccessTypeEnum : uint16_t
{
	NA = 0x00, 
	CO = 0x01, 
	E = 0x02, 
	W = 0x04, 
	R = 0x08, 
	FA = 0x10  

};