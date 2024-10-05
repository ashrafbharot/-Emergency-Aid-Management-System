#pragma once
/***********************************************************************
// Final project Milestone
// Module: iProduct and Item
// File: main.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT   Date: 2023-11-23    Reason
***********************************************************************/
#include <iostream>
#ifndef SDDS_IPRODUCT_H_
#define SDDS_IPRODUCT_H_
namespace sdds {
    class iProduct {
    public:

        virtual int readSku(std::istream& istr);

        virtual int operator-=(int qty);

        virtual int operator+=(int qty);

        virtual operator double()const;

        virtual operator bool()const;

        virtual int qtyNeeded()const;

        virtual int qty()const;
        virtual void linear(bool isLinear);
        virtual std::ofstream& save(std::ofstream& ofstr)const;
        virtual std::ifstream& load(std::ifstream& ifstr);
        virtual std::ostream& display(std::ostream& ostr)const;
        virtual std::istream& read(std::istream& istr);
        virtual bool operator==(int sku)const;
        virtual bool operator==(const char* description)const;
        virtual ~iProduct() {};
    };
    std::ostream& operator<<(std::ostream& ostr, const iProduct& I);
    std::istream& operator>>(std::istream& istr, iProduct& I);
}

#endif // !SDDS_IPRODUCT_H_virtual
