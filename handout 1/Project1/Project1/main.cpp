#include <iostream>
#include "vec3.h"
using namespace std;

int main()
{
	vec3<double> v1(1, 2, 3);
	vec3<double> v2(1, 1, 1);
	vec3<double> v3 = v1 + v2;
	v3.name();
	v1.zero();
	v1.is_zero();
	v2.is_zero();
	system("pause");
	return 0;
}