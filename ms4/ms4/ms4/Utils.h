//Arafat Sarkar
//ID-144252202
//OOP244ZEE

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
namespace sdds
{
	const int sdds_testYear = 2022;
	const int sdds_testMon = 03;
	const int sdds_testDay = 31;
	class Utils
	{
		bool m_testMode = false;
	public:
		void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
		int daysOfMon(int mon, int year)const;
		void testMode(bool testmode = true);
		int checking_num(std::istream& istr, int x, int y);
		double checking_float(std::istream& istr, double x, double y);
	};
	extern Utils ut;
}

#endif // !SDDS_UTILS_H