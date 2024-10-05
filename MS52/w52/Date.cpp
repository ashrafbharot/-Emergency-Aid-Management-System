/**********************************************************************************

Name		   - Arth Patel
Email		   - parth-bimalbhai@myseneca.ca
student id     - 141716225
Section		   - ZCC
Date           - 14 Nov 2023
authentication :
I have done all the work on my own. I only used the files provided by the professor.
***********************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Date.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    // this private method validate the date in the following order year - month - day 
    bool Date::validate() {

        bool isvalid = false;

        int cyear;

        ut.getSystemDate(&cyear); // using utlis function to get system defalut date 

        status.clear(); // calling status function to erase data to ensure the values are not corrupted 

        if (m_year < cyear || m_year > MAXIMUM_YEAR_VALUE) // if the year enterd is less than current year or greater than the maximum year 
        {

            status = "Invalid year in date";

            status = 1; // as per the instruction in the ms2 

        }

        else if (m_month < 1 || m_month> 12) // checking if the month entered is between the valid months 
        {

            status = "Invalid month in date";

            status = 2;

        }

        else if (m_day<1 || m_day > ut.daysOfMon(m_month, m_year)) // calling utlis function because the no of days in a month are diffrent in all the months 
        {

            status = "Invalid day in date";

            status = 3;

        }
        else if (invalid == true)
        {
            status = 0;
            status = "Invalid date value";
        }

        else {

            isvalid = true; // returns true if the date is valid 

        }

        return isvalid; // returns false if the date is not valid 

    }
    // this function returns the refrence to the state of date 
    const Status& Date::state()
    {
        return status;
    }
    // this function returns a unique integer value tied to date and this helps us to compare two dates by converting both of them in the same format 
    int Date::uniqueDateValue() const
    {
        return m_year * 372 + m_month * 31 + m_day;
    }

    // default constructor which intializes the object with current system date 
    Date::Date()
    {
        invalid = false;
        m_format = true;
        ut.getSystemDate(&m_year, &m_month, &m_day); // caling utlis function to get curretn date  
    }
    // this function is used if the date object is casted to boolean and it reutrns the state of the object 
    Date::operator bool() const {
        return status;
    }
    // intializes the object with the date provided 
    Date::Date(int year, int month, int day)
    {
        invalid = false;
        m_format = true;
        m_year = year;
        m_month = month;
        m_day = day;
        validate();

    }

    // 
    Date& Date::formatted(bool slash)
    {
        if (slash == false)
        {
            m_format = false;
        }


        return *this;
    }
    // compares the date of two object 
    bool Date::operator==(const Date& right) const
    {
        return this->uniqueDateValue() == right.uniqueDateValue();
    }
    // checks if the left date is not equal to right date 
    bool Date::operator!=(const Date& right) const
    {
        return this->uniqueDateValue() != right.uniqueDateValue();
    }
    // to check if the date on the lefthand side is greater than or equal to right 
    bool Date::operator>=(const Date& right) const
    {
        return this->uniqueDateValue() >= right.uniqueDateValue();
    }
    // iverse of this comparison overload(>=)
    bool Date::operator<=(const Date& right) const
    {
        return this->uniqueDateValue() <= right.uniqueDateValue();
    }
    // just check if the left object value is less than the right object's value 
    bool Date::operator<(const Date& right) const
    {
        return this->uniqueDateValue() < right.uniqueDateValue();
    }
    // inverse of  bool(<) function
    bool Date::operator>(const Date& right) const
    {
        return this->uniqueDateValue() > right.uniqueDateValue();
    }

    bool notint(bool chara)
    {
        return chara == true;
    }
    // this method reads thes input from the user as one integer value without any character and special characters also and this function returns the refrence of the istream object 
    std::istream& Date::read(std::istream& istr)
    {
        int number;
        int day1;
        int day2;
        int mon1;
        int mon2;
        int year1;
        int year2;
        istr >> number;
        if (istr)
        {
            if (number <= 9999)
            {
                day2 = number % 10;
                day1 = number / 10 % 10;
                mon2 = number / 100 % 10;
                mon1 = number / 1000 % 10;
                if (mon1 == 0)
                {
                    m_month = mon2;
                }
                else
                {
                    m_month = (mon1 * 10) + mon2;
                }
                if (day1 == 0)
                {
                    m_day = day2;
                }
                else
                {
                    m_day = (day1 * 10) + day2;
                }
                ut.getSystemDate(&m_year);
            }
            else if (number >= 100000 && number <= 999999) // converting the date in one integer 
            {
                day2 = number % 10;
                day1 = number / 10 % 10;
                mon2 = number / 100 % 10;
                mon1 = number / 1000 % 10;
                year2 = number / 10000 % 10;
                year1 = number / 100000 % 10;

                if (year1 == 0)
                {
                    m_year = 2000 + year2;
                }
                else
                {
                    m_year = 2000 + ((year1 * 10) + year2);
                }
                if (mon1 == 0)
                {
                    m_month = mon2;
                }
                else
                {
                    m_month = (mon1 * 10) + mon2;
                }
                if (day1 == 0)
                {
                    m_day = day2;
                }
                else
                {
                    m_day = (day1 * 10) + day2;
                }
            }

        }
        else
        {
            invalid = true;
        }

        if (!validate()) // calling validate function to check if the date is valid or not 
        {

            istr.setstate(ios::badbit); // used this if the validation fails
        }
        return istr; // returns the refrance of the istream object

    }
    // this function prints the date in two fromat
    // if date is valid - YYYY/MM/DD
    // if invalid - YYMMDD
    // this function returns the refrence of the ostream object 
std::ostream& Date::write(std::ostream& os, bool formate) const
    {

        if (m_format == true && formate)
        {
            os << m_year;
            os << '/';
            os.fill('0');
            os.width(2);
            os << m_month;
            os << '/';
            os.width(2);
            os << m_day;
            os.fill(' ');
        }
        else
        {
            int year = m_year - 2000;
            os << year;
            os.fill('0');
            os.width(2);
            os << m_month;
            os.width(2);
            os << m_day;
            os.fill(' ');
        }
        return os;
    }    // this function helps to write a date object through ostream (cin)
    std::ostream& operator<<(std::ostream& os, const Date& dat)
    {
        return dat.write(os); // calls write function to print the date entered 
    }
    // this function helps to read a date object through istream (cin)
    std::istream& operator>>(std::istream& is, Date& dat)
    {
        return dat.read(is); // calls read function to read the date 
    }
}