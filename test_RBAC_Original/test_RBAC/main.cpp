
#include <iostream>
#include "Permission.h"
#include "Subject.h"
#include "Object.h"

using namespace std;

int main(void)
{
	Subject mySub;
	mySub.getLoginDetails();
	Subject sub(mySub.getUsername(), mySub.getPassword());
	//cout << (int)sub.getAuth();
	Permission myPermissions;
	{
		Object myResource(sub, myPermissions, 1, AccessTypeEnum::W);
	}

	return 0;
}