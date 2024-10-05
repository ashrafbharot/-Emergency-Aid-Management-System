
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


#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
#include<cstring>
namespace sdds {

    /* this class contains
    * 3 - constructor : copy constructor ,  default constructor , argument constructor
    3 copy operator
    3 type conversion overloads , int , char and bool operator overload
    destructor
    1 helper function
    */

    class Status
    {
        // the two varaible of the class are private 
        char* m_description = nullptr;
        int m_code;
    public:

        Status();
        Status(const char* description);
        Status(const Status& stat);
        Status& operator =(const Status& other);
        Status& operator =(const char* description);
        Status& operator =(int code);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear(); // this function is used to delete the dynamic memory
        std::ostream& print(std::ostream& ostr) const; // it prints the status of the object  
        ~Status();

    };
    // it is a global function so 
    std::ostream& operator<<(std::ostream& os, const Status& stat);

}
#endif