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
#ifndef AIDMAN_H
#define AIDMAN_H

#include "Menu.h"

namespace sdds {
    class AidMan {
        char* dataFileName;
        Menu prmMenu;

    public:
        AidMan(const char* inpfileName);
        ~AidMan();
        AidMan(const AidMan&) = delete;
        AidMan& operator=(const AidMan) = delete;

        void run(); 

    private:
        unsigned int menuOption();
    };
}

#endif
