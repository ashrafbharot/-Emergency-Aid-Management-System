

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
#include "Utils.h"
#include "Status.h"
#include <string>
using namespace std;

namespace sdds
{
    bool Date::validate()
    {
        Utils a; //object for utils
        Status b; //object for status

        if (month < 1 || month > 12)
        {

            status.status_des = new char[22];
            strcpy(status.status_des, "Invalid month in date");
            status.status_code = 2;

            return false;
        }
        else if (year < sdds_testYear || year > MAX_YEAR)
        {
            status.status_des = new char[21];
            strcpy(status.status_des, "Invalid year in date");
            status.status_code = 1;

            return false;
        }
        else if (day < 1 || day > a.daysOfMon(month, year))
        {

            status.status_des = new char[20];
            strcpy(status.status_des, "Invalid day in date");
            status.status_code = 3;

            return false;
        }
        else
        {
            b.clear();
            return true;
        }
    }

    int Date::uniqueValue() const
    {
        return (year - 2000) * 10000 + month * 100 + day;
    }

    const Status& Date::state()
    {
        return status;
    }

    bool Date::formatted(bool m_format)
    {
        format = m_format;

        return *this;
    }

    Date::operator bool() const
    {
        return 0;
    }


    Date::Date()
    {
        //This is for getting the test date
        year = sdds_testYear;
        month = sdds_testMon;
        day = sdds_testDay;


        /*
        //This is for getting the current day :
        Utils a;
        a.getSystemDate(&year, &month, &day);
        */
        formatted(true);
    }



    Date::Date(int m_year, int m_month, int m_day)
    {
        year = m_year;
        month = m_month;
        day = m_day;
        formatted(true);
        validate();
    }


    bool operator==(const Date& one, const Date& two)
    {
        return one.uniqueValue() == two.uniqueValue();
    }

    bool operator!=(const Date& one, const Date& two)
    {
        return one.uniqueValue() != two.uniqueValue();
    }

    bool operator>=(const Date& one, const Date& two)
    {
        return one.uniqueValue() >= two.uniqueValue();
    }

    bool operator<=(const Date& one, const Date& two)
    {
        return one.uniqueValue() <= two.uniqueValue();
    }

    bool operator<(const Date& one, const Date& two)
    {
        return one.uniqueValue() < two.uniqueValue();
    }

    bool operator>(const Date& one, const Date& two)
    {
        return one.uniqueValue() > two.uniqueValue();
    }

    /*
    void Date::clear()
    {
        year = 0;
        month = 0;
        day = 0;
        status = false;
        format = false;
    }
    */

    std::istream& Date::read(std::istream& istr)
    {
        int value = 0;
        string input;

        istr >> value;
        if (istr.fail())
        {
            cout << "Invalid date value";
            cin.setstate(ios::badbit);
            return istr;
        }

        if (to_string(value).length() == 4 || to_string(value).length() == 3)
        {
            year = sdds_testYear;
            day = value % 100;
            month = value / 100;
        }
        else if (to_string(value).length() == 6 || to_string(value).length() == 5)
        {
            day = value % 100;
            value = value / 100;
            month = value % 100;
            year = value / 100 + 2000;
        }
        else
        {
            month = 0;
            day = 0;
            year = 0;
        }
        if (validate() == false)
        {
            cin.setstate(ios::badbit);
        }
        return istr;
    }

    std::ostream& sdds::Date::write(std::ostream& ostr) const
    {
        if (format == true)
        {
            ostr << year << '/' << setw(2) << setfill('0') << month << '/' << setw(2) << setfill('0') << day;
        }
        else
        {
            ostr << year % 100 << setw(2) << setfill('0') << month << setw(2) << setfill('0') << day;
        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Date& D)
    {
        D.write(ostr);
        return ostr;
    }


    std::istream& operator>>(std::istream& istr, Date& D)
    {
        D.read(istr);
        return istr;
    }
}
