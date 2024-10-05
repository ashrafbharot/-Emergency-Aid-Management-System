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
#include "Menu.h"
#include <string>
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

namespace sdds {

    Menu::Menu(const char* content) {
        int count = 0;
        for (size_t i = 0; i < strlen(content); i++) {
            if (content[i] == '\t') {
                count++;
            }
        }

        if (content && count <= 15) {
            menu = new char[strlen(content) + 1];  
            strcpy(menu, content);
            numOptions = count + 1;
        }
        else {
            menu = nullptr;  
            numOptions = 0;
        }
    }

    Menu::~Menu() {
        delete[] menu;  
    }

    unsigned int Menu::run() {
        if (!menu) { 
            std::cout << "Invalid Menu!" << std::endl;
            return 0;
        }

        while (true) {

            size_t optionNum = 1;
            std::istringstream stream(menu);  
            std::string token;

            while (std::getline(stream, token, '\t')) {
                std::cout << optionNum << "- " << token << std::endl;
                optionNum++;
            }

            std::cout << "---------------------------------" << std::endl;
            std::cout << "0- Exit" << std::endl;

            unsigned int userChoice;
            do {
                std::cout << "> ";
                std::cin >> userChoice;

                if (std::cin.fail()) {
                    std::cout << "Invalid Integer, retry: ";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cin >> userChoice;
                }
                else if (userChoice < 0 || userChoice > numOptions) {
                    std::cout << "Value out of range [0<=val<=" << numOptions << "]: ";
                    std::cin >> userChoice;
                }
            } while (userChoice < 0 || userChoice > numOptions);

            if (userChoice == 0) {
                return userChoice;
            }

            return userChoice;
        }
    }
}
