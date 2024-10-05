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
#pragma once
#pragma once
#ifndef MENU_H
#define MENU_H

namespace sdds {
    /* this class contains an  dynamic attribute
    *  two constructor : agrument & copy constructor
    * one public method
    */

    class Menu {
    private:
        char* mContent = nullptr;
        unsigned int numOpt;

    public:
        Menu(const char* content);
        ~Menu(); // destrucotr to prevent memory leaks 

        // as per the instruction to not allow copy of menu object to another 
        Menu(const Menu&) = delete; // delete keyword prohibts the  copying of menu object
        Menu& operator=(const Menu&) = delete;

        unsigned int run(); // This method receives nothing and returns an unsigned integer and will not change the state of the Menu object.
    };



}

#endif // MENU_H