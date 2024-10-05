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
#include "Menu.h"
#include "Utils.h"
#include <string>
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

namespace sdds {

    Menu::Menu(const char* content) // intializing the constructor with a c-string 
    {
        int opt = 0;
        for (size_t i = 0; i < strlen(content); i++)
        {
            if (content[i] == '\t') {
                opt++;
            }
        }

        if (content && opt <= 15) // the maximum number of options is 15
        {
            // dynamically allocating memory for the c-string 
            mContent = new char[strlen(content) + 1];
            strcpy(mContent, content);
            numOpt = opt + 1;
        }
        else  //  if the number of options is more than 15 or if the C-String is null, then the menu is rendered invalid.
        {
            mContent = nullptr;
            numOpt = 0;
        }
    }

    Menu::~Menu() {
        delete[] mContent; // making sure there is no memory leaks 
    }


    /*
    The run method will first displays the menu content in a menu format, prints a separator line and then prints "0- Exit"
    and finally goes to a new line. Then it will display "> " as a prompt and waits for the user to enter an integer
    */
    unsigned int Menu::run()
    {
        if (!mContent) {
            std::cout << "Invalid Menu!" << std::endl;
            return 0;
        }

        while (true) {

            size_t optionNum = 1;
            std::istringstream stream(mContent);
            std::string token;

            while (std::getline(stream, token, '\t')) {
                std::cout << optionNum << "- " << token << std::endl;
                optionNum++;
            }

            std::cout << "---------------------------------" << std::endl;
            std::cout << "0- Exit" << std::endl;

            unsigned int choice; // stores the choice enterd by user 
            do {
                std::cout << "> ";
                choice = ut.getint(0,7); 

                if (std::cin.fail()) // If the user enters a non-integer value and we check it by calling the fail function 
                {
                    std::cout << "Invalid Integer, retry: ";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cin >> choice;
                }
                else if (choice < 0 || choice > numOpt) // If the user enters an invalid integer  
                {
                    std::cout << "Value out of range [0<=val<=" << numOpt << "]: ";
                    std::cin >> choice;
                }
            } while (choice < 0 || choice > numOpt);

            if (choice == 0) {
                return choice;
            }

            return choice; // returns the option selected by user
        }


    }
}