#ifndef _STRINGCLASS_H
#define _STRINGCLASS_H
#include <string.h>
#include <assert.h>
class String 
{
private:
	char* string = nullptr;
	unsigned int allocated_mem = 0u;

public:
	String(){}
	String(const char* txt)
	{
		assert(string != nullptr);
		if (string != nullptr)
		{
			allocated_mem = strlen(txt) + 1;
			this->string = new char[allocated_mem];
			strcpy_s(string,allocated_mem, txt);
		}
	}

	String(const String &newtxt)
	{
		assert(string != nullptr);
		if (newtxt.string != nullptr)
		{
			allocated_mem = newtxt.allocated_mem;
			this->string = new char[allocated_mem];
			strcpy_s(string, allocated_mem, newtxt.string);
		}
	}

	String operator=(const char* txt) 
	{
		if (string != nullptr)
		{
			if (strlen(string) >= allocated_mem) 
			{
				strcpy_s(string, allocated_mem, txt);
			}
			else
			{
				allocated_mem = strlen(txt) + 1;
				delete[] string;
				this->string = new char[allocated_mem];
				strcpy_s(string, allocated_mem, txt);
			}
		}
		return *this;
	}

	~String()
	{
		assert(string != nullptr);
		if (string != NULL) 
		{
			string = nullptr;
			allocated_mem = 0u;
			delete[] string;
		}
	}
};
#endif