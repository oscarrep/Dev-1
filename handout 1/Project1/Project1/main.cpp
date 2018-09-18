#include <iostream>
#include <vector>
using namespace std;

class vec3 {
public:
	vec3();
	vec3(float, float, float);
	vec3 operator+(vec3 rhs);
	vec3 operator-(vec3 rhs);
	vec3 operator+=(vec3 rhs);
	vec3 operator-=(vec3 rhs);
	vec3 operator=(vec3 rhs);
	vec3 operator==(vec3 rhs);

	float dot(vec3 rhs);
	float length();

	float X;
	float Y;
	float Z;	
};