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
*************************************************************************/
#pragma once
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <ostream>

namespace sdds {
    class Status {
    public:
        Status();
        Status(const char* desc);
        Status(int c);
        Status(const Status& other);
        Status& operator=(const Status& other);
        Status& operator=(const char* desc);
        Status& operator=(int c);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();
        friend std::ostream& operator<<(std::ostream& os, const Status& status);
        ~Status();

    private:
        char* description;
        int code;
    };
}



#endif
