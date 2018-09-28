#include "string.h"
#include <stdlib.h>

int main()
{
	String a;
	String b(a);
	String c("Hello");

	a = "hi";

	if (a == "bye")
		return true;

	system("pause");
	return 0;
}