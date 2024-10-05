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
#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include "Utils.h"
#include <iostream>
#include <cstring>

namespace sdds {

    AidMan::AidMan(const char* inpFileName) : prmMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
        if (inpFileName && strlen(inpFileName) > 0) {
            dataFileName = new char[strlen(inpFileName) + 1];
            strcpy(dataFileName, inpFileName);
        }
        else {
            dataFileName = nullptr;
        }
    }

    AidMan::~AidMan() {
        delete[] dataFileName;
    }

    void AidMan::run() {
        while (true) {
            std::cout << "Aid Management System" << std::endl;

            std::cout << "Date: 2023/12/09" << std::endl;
            std::cout << "Data file: " << (dataFileName ? dataFileName : "No file") << std::endl;
            std::cout << "\n";

            unsigned int userChoice = menuOption();

            switch (userChoice) {
            case 0:
                std::cout << "Exiting Program!" << std::endl;
                return;
            case 1:
                std::cout << "\n****List Items****\n\n";
                break;
            case 2:
                std::cout << "\n****Add Item****\n\n";
                break;
            case 3:
                std::cout << "\n****Remove Item****\n\n";
                break;
            case 4:
                std::cout << "\n****Update Quantity****\n\n";
                break;
            case 5:
                std::cout << "\n****Sort****\n\n";
                break;
            case 6:
                std::cout << "\n****Ship Items****\n\n";
                break;
            case 7:
                std::cout << "\n****New/Open Aid Database****\n\n";
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
            }
        }
    }

    unsigned int AidMan::menuOption() {
        return prmMenu.run();
    }
}
