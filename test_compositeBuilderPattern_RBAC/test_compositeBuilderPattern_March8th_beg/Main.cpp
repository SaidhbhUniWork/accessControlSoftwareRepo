
#include <iostream>
#include <memory>
#include "Execute.h"
#include "Read.h"
#include "Write.h"
#include "SimpleRole.h"
#include "CompositeRole.h"
#include "AuthEnum.h"
#include "Subject.h"

using namespace std;

int main() {
	Subject mySubject;

	mySubject.authorizeSubject();

	return 0;
}