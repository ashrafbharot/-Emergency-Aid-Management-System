//Arafat Sarkar
//ID-144252202
//OOP244ZEE

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds
{
	class Status
	{
	public:
		char* status_des;
		int status_code;
		Status(char* str = nullptr, int code = 0);
		Status(const Status& status);
		Status& operator=(const Status& status);
		~Status();
		Status& operator=(const char* str);
		Status& operator=(const int code);
		operator bool() const;
		operator int() const;
		operator char* () const;
		friend ostream& operator<<(ostream& os, const Status& status);
		Status& clear();
	};
}

#endif // !SDDS_STATUS_H