
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
// Name: MOHAMED ASHRAF BHAROT    Date 2023-11-06          Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Status.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    // there are two constructor and according to instruction the code will be zero in both 
    // it is a default constructor and will be called when description is not provided 
    Status::Status()
    {
        m_description = 0;
        m_code = 0;
    }

    // one argument constructor and will be called when an object is intialized with the description 
    Status::Status(const char* description)
    {
        m_code = 0;
        if (description != nullptr)
        {
            ut.alocpy(m_description, description); // utlis module function alcopy is called we are reusing as many function we can to avoid lengthy code 
        }
    }

    // it is a copy constructor 
    Status::Status(const Status& stat)
    {
        m_code = stat.m_code;
        if (m_description != nullptr) // self-assigment check to ensure the function works correctly 
        {
            size_t len = strlen(stat.m_description);
            m_description = new char[len + 1];
            strcpy(m_description, stat.m_description);
        }
        else
        {
            m_description = nullptr;
        }

    }

    // it is a copy assigment operator which will copy an existing object into another created object 
    Status& Status::operator =(const Status& other)
    {
        if (this != &other) // self-assigment check to ensure values do not get corrupted 
        {
            m_code = other.m_code;
            ut.alocpy(m_description, other.m_description); // utlis function alcopy is beng called here 

        }

        return *this;
    }

    // it will only copy the description character value from one object to another object 
    Status& Status::operator =(const char* description)
    {
        if (description != nullptr)
        {
            ut.alocpy(m_description, description);
        }
        return *this;
    }
    // this copy operator will only copy the integer value of one object into another object 
    Status& Status::operator =(int code)
    {
        m_code = code;
        return *this;

    }
    // it will cast a staus object to an integer and will return the code 
    Status::operator int() const // we used const as per the instruction given in the milestone files to ensure we do not change or modify values unintentionally 
    {
        return m_code;
    }

    // it will just return the description of the object (conversion overload)
    Status::operator const char* () const
    {
        return m_description;
    }
    // it will return state of the class if the description is null it is in good state otherwise i bad state if not (there will be a posssibilty of memory leak )
    Status::operator bool() const
    {
        if (m_description == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // this method safely deallocates the description memory and sets code to 0 to ensure there is no memory leaks 
    Status& Status::clear()
    {
        if (m_description != nullptr)
        {
            delete[] m_description;
            m_description = nullptr;
            m_code = 0;
        }
        return *this; // it reutrns the current refrence of the object as per the insruction 
    }

    // destructor which delets the status object 
    Status::~Status()
    {
        delete[] m_description;
    }
    // this function is use to print the error with which code and with a query const n=to not modify the value of m_code
    std::ostream& Status::print(std::ostream& ostr) const
    {

        if (m_code == 0)
        {
            ostr << m_description;
        }
        else
        {
            ostr << "ERR#" << m_code << ": ";
            ostr << m_description;
        }
        return ostr;
    }
    // this function checks if the status of object is in bad state or not 
    std::ostream& operator<<(std::ostream& os, const Status& stat)
    {
        if (stat) // if it is in a good state 
        {
            //do nothing
        }
        else // if the object is in  a bad state 
        {
            stat.print(os); // it will call the print function to print that an object is in bad state 
        }
        return os;
    }



}