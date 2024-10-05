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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
#include<cstring>
namespace sdds {
    class Status
    {
        char* m_description{};
        int m_code;
    public:
        Status(const char* description = nullptr);
        Status(const Status& stat);
        Status& operator =(const char* description);
        Status& operator =(int code);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();
        std::ostream& print(std::ostream& ostr) const;
        ~Status();

    };
    std::ostream& operator<<(std::ostream& os, const Status& stat);

}
#endif