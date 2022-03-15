#include "Object.h"

//std::ostream& operator<<(std::ostream& os, const AccessTypeEnum c)
//{
//	switch (c) {
//	case AccessTypeEnum::NA: os << "No access";			   break;
//	case AccessTypeEnum::CO: os << "Copy access";		   break;
//	case AccessTypeEnum::E:  os << "Execute access";       break;
//	case AccessTypeEnum::W:  os << "Write access";         break;
//	case AccessTypeEnum::R:  os << "Read access";          break;
//	case AccessTypeEnum::FA: os << "Full Access";		   break;
//	default: os.setstate(std::ios_base::failbit);
//	}
//	return os;
//}

//std::ostream& operator<<(std::ostream& out, const AccessTypeEnum val)
//{
//	const char* s = 0;
//#define PROCESS_VAL(p) case(p): s = #p; break;
//	switch (val)
//	{
//		PROCESS_VAL(AccessTypeEnum::NA);
//		PROCESS_VAL(AccessTypeEnum::CO);
//		PROCESS_VAL(AccessTypeEnum::E);
//		PROCESS_VAL(AccessTypeEnum::W);
//		PROCESS_VAL(AccessTypeEnum::R);
//		PROCESS_VAL(AccessTypeEnum::FA);
//	}
//#undef PROCESS_VAL
//
//	return out << s;
//}

//std::ostream& operator<<(std::ostream& os, AccessTypeEnum &val)
//{
//	switch (val) {
//	case AccessTypeEnum::NA: return os << "No access";			   
//	case AccessTypeEnum::CO: return os << "Copy access";
//	case AccessTypeEnum::E:  return os << "Execute access";
//	case AccessTypeEnum::W:  return os << "Write access";
//	case AccessTypeEnum::R:  return os << "Read access";
//	case AccessTypeEnum::FA: return os << "Full Access";
//	//default: os.setstate(std::ios_base::failbit);
//	}
//	return os << static_cast<std::uint16_t>(val);

