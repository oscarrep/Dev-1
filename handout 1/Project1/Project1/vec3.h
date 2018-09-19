#ifndef _VEC3_H_
#define _VEC3_H_
#include <math.h>

using namespace std;
template<class type>

class vec3
{
private:
	type x, y, z;
public:
	vec3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	vec3(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3 operator+(vec3 const &vect)
	{
		vec3 vecres(x + vect.x, y + vect.y, z + vect.z);
	}

	vec3 operator-(vec3 const &vect)
	{
		vec3 vecres(x - vect.x, y - vect.y, z - vect.z);
		return vecres;
	}

	void operator+=(vec3 const &vect)
	{
		x += vect.x;
		y += vect.y;
		z += vect.z;

	}

	void operator-=(vec3 const &vect)
	{
		x -= vect.x;
		y -= vect.y;
		z -= vect.z;
	}

	void operator=(vec3 const &vect)
	{
		x = vect.x;
		y = vect.y;
		z = vect.z;
	}

	bool operator==(vec3 const &vect)
	{
		if (x == vect.x && y == vect.y && z == vect.z) return true;
		else return false;
	}

	void normalize() const
	{
		type magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		if (magnitude != 0)
		{
			cout << x / magnitude << " " << y / magnitude << " " << z / magnitude << endl;
		}
		else
			cout << "no exist" << endl;
	}

	void zero()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	void is_zero()
	{
		if (x == 0 && y == 0 && z == 0) cout << "is zero" << endl;
		else cout << "no is zero" << endl;
	}

	void distance_to(vec3 const &vect)
	{
		cout << "(" << x - vect.x << " , " << y - vect.y << " , " << z - vect.z << ")" << endl;
	}

	void name()
	{
		cout << x << " " << y << " " << z << endl;
	}
};


#endif