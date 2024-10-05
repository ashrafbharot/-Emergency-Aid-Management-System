//Arafat Sarkar
//ID-144252202
//OOP244ZEE

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include "Status.h"
using namespace std;
namespace sdds
{
    Status::Status(char* str, int code)
    {
        status_code = code;

        if (str != NULL)
        {
            status_des = new char[strlen(str) + 1];
            strcpy(status_des, str);
        }
        else
        {
            status_des = NULL;
        }
    }

    Status::Status(const Status& status)
    {
        status_code = status.status_code;

        if (!status)
        {
            status_des = new char[strlen(status.status_des) + 1];
            strcpy(status_des, status.status_des);
        }
        else
        {
            status_des = NULL;
        }
    }

    Status& Status::operator=(const Status& status)
    {

        delete[] status_des;
        status_des = nullptr;

        status_code = status.status_code;

        if (status)
        {
            status_des = new char[strlen(status.status_des) + 1];
            strcpy(status_des, status.status_des);
        }
        else
        {
            status_des = NULL;
        }

        return *this;
    }

    Status::~Status()
    {
        delete[] status_des;
        status_des = nullptr;
    }

    Status& Status::operator=(const char* str)
    {
        delete[] status_des;
        status_des = nullptr;
        if (str == nullptr) return *this;
        status_des = new char[strlen(str) + 1];
        strcpy(status_des, str);
        return *this;
    }

    Status& Status::operator=(const int code)
    {
        status_code = code;
        return *this;
    }

    Status::operator bool() const
    {
        if (status_des != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Status::operator int() const
    {
        return status_code;
    }

    Status::operator char* () const
    {
        return status_des;
    }

    ostream& operator<<(ostream& os, const Status& status)
    {
        if (!status)
        {
            if (status.status_code != 0)
                os << "ERR#" << status.status_code << ": ";
            os << status.status_des;
        }
        return os;
    }

    Status& Status::clear()
    {
        delete[] status_des;
        status_des = nullptr;
        status_code = 0;
        return *this;
    }
}

