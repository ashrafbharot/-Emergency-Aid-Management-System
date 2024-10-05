/***********************************************************************
// Final project Milestone 2
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT      Date:2023-11-14     Reason
*************************************************************************/
#pragma once
#ifndef SDDS_DATE_H
#define SDDS_DATE_H

#include "Status.h"
#include <iostream>

namespace sdds {
    class Date {
    private:
        int m_year;
        int m_month;
        int m_day;
        Status m_state;
        bool m_formatted;

        bool validate();

    public:
        Date();
        Date(int year, int month, int day);
        void formatted(bool value);
        Status state() const;
        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>=(const Date& other) const;

        int uniqueDateValue() const;
        void read(std::istream& is);
        void write(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Date& date);
    std::istream& operator>>(std::istream& is, Date& date);
}

#endif 