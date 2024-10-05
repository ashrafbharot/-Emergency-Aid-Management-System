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
#ifndef MENU_H
#define MENU_H

namespace sdds {

    class Menu {
    private:
        char* menu; 
        unsigned int numOptions;

    public:
        Menu(const char* content);
        ~Menu();

        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        unsigned int run();
    };

}

#endif // MENU_H
