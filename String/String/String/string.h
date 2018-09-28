#ifndef _STRING_H
#define _STRING_H

class String
{
private:
	char* new_char = nullptr;

public:
	String() {}
	String(const char* new_char)
	{
		this->new_char = (char*)new_char;
	}

	String(const String& new_string)
	{
		new_char = new_string.new_char;
	}

	~String() {}

	String operator=(const String& new_string)
	{
		new_char = new_string.new_char;
		return *this;
	}

	bool operator==(const String& new_string) const
	{
		return (new_char == new_string.new_char);
	}
};


#endif