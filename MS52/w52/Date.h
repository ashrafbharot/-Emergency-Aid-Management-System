#pragma once

#pragma once
/**********************************************************************************

Name		   - Arth Patel
Email		   - parth-bimalbhai@myseneca.ca
student id     - 141716225
Section		   - ZCC
Date           - 14 Nov 2023
authentication :
I have done all the work on my own. I only used the files provided by the professor.
***********************************************************************************/


#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include<cstring>
#include<sstream>
#include"Status.h"
namespace sdds {

    // the largest value acceptable value in year (maximum year value that can be entered )
    const int MAXIMUM_YEAR_VALUE = 2030;

    /* this class contains 2 constructor : defualt & 3 argument constructor
    * 2 private member function
      6 operator overload function used for comparison
      one red method & one std output function
      two global helper and extraction operator overloads

    */


    class Date
    {
        /* this date class has 5 arrtibrute
        2 bollean value
        status class
        */
        Status status; // status object which holds the validity of staatus of date 
        int m_year;
        int m_month;
        int m_day;
        bool m_format;
        bool invalid;
        bool validate(); // this function validates the date that is entered by the user 
     
    public:
        int uniqueDateValue() const;
        Date(); // it is a default constructor used  
        Date(int year, int month, int day);  // 3 argument constructor 
        operator bool() const;
        const Status& state();
        Date& formatted(bool slash);
        bool operator==(const Date& right) const;  // used to check if both object is equal or not 
        bool operator!=(const Date& right) const; // inverse of (==)
        bool operator>=(const Date& right) const;
        bool operator<=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;
       std::ostream& write(std::ostream& os, bool formate = true) const;    
       std::istream& read(std::istream& istr);
    };
    // global helper operator function 
    std::ostream& operator<<(std::ostream& os, const Date& dat);
    std::istream& operator>>(std::istream& is, Date& dat);
}
#endif