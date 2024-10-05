//Arafat Sarkar
//ID-144252202
//OOP244ZEE

#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
#include "Status.h"
namespace sdds
{
	const int MAX_YEAR = 2030;

	class Date
	{
	private:
		int year;
		int month;
		int day;
		Status status;
		bool format;
		bool validate();
	public:
		Date();
		Date(int m_year, int m_month, int m_day);
		int uniqueValue()const;
		const Status& state();
		bool formatted(bool m_format);
		operator bool() const;
		//void clear();
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

	};
	bool operator==(const Date& one, const Date& two);
	bool operator!=(const Date& one, const Date& two);
	bool operator>=(const Date& one, const Date& two);
	bool operator<=(const Date& one, const Date& two);
	bool operator<(const Date& one, const Date& two);
	bool operator>(const Date& one, const Date& two);
	std::istream& operator>>(std::istream&, Date&);
	std::ostream& operator<<(std::ostream&, const Date&);
}

#endif
