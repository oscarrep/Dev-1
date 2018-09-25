#ifndef _VEC3_H
#define _VEC3_H
#include <math.h>
//using namespace std;

template <class _type>
class vec3
{
private:

	_type x, y, z;
public:

	///////////////////////* CONSTRUCTOR *///////////////////////

	vec3() {}

	vec3(const _type &x, const _type &y, const _type &z) : 
		x(x),
		y(y),
		z(z)
	{}

	vec3(const vec3 &vector) : x(vector.x), y(vector.y), z(vector.z) {}

	///////////////////////* OPERATORS GO HERE *//////////////////////

	vec3 operator+(const vec3 &vectorB) const
	{
		return vec3(x + vectorB.x, y + vectorB.y, z + vectorB.z);
	}

	vec3 operator-(const vec3 &vectorB) const
	{
		return vec3(x - vectorB.x, y - vectorB.y, z - vectorB.z);
	}

	vec3 operator+=(const vec3 &vectorB)
	{
		x += vectorB.x; 
		y += vectorB.y; 
		z += vectorB.z;
		return *this;

	}

	vec3 operator-=(const vec3 &vectorB)
	{
		x -= vectorB.x; 
		y -= vectorB.y; 
		z -= vectorB.z;
		return *this;
	}

	vec3 operator=(const vec3 &vectorB)
	{
		x = vectorB.x; 
		y = vectorB.y; 
		z = vectorB.z;
		return *this;
	}

	bool operator==(const vec3 &vectorB) const
	{
		return (x == vectorB.x && y == vectorB.y && z == vectorB.z);
	}

	vec3 normalize() const
	{
		_type magnitude = sqrt((x * x) + (y * y) + (z * z));
		return vec3(x / magnitude, y / magnitude, z / magnitude);

	}

	vec3 zero()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		return *this;
	}

	bool is_zero() const
	{
		return (x == 0.0 && y == 0.0 && z == 0.0);

	}

	_type distance_to(const vec3 &vector) const
	{
		return sqrt(((x - vector.x) * (x - vector.x)) + ((y - vector.y) * (y - vector.y)) + ((z - vector.z) * (z - vector.z)));
	}

};

#endif