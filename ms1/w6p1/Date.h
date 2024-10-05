#pragma once
/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT      Date:2023-11-03     Reason
************************************************************************/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include<cstring>
#include<sstream>
#include"Status.h"
namespace sdds {

    const int MAXIMUM_YEAR_VALUE = 2030;



    class Date
    {
        Status status;
        int m_year;
        int m_month;
        int m_day;
        bool m_format;
        bool invalid;
        bool validate();
        int uniqueDateValue() const;
    public:
        Date();
        bool notint(bool chara = false);

        Date(int year, int month, int day);
        operator bool() const;
        const Status& state();
        Date& formatted(bool slash);
        bool operator==(const Date& right) const;
        bool operator!=(const Date& right) const;
        bool operator>=(const Date& right) const;
        bool operator<=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& os, const Date& dat);
    std::istream& operator>>(std::istream& is, Date& dat);
}
#endif