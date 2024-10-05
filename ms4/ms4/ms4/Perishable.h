/* ------------------------------------------------------
Final project Milestone 4
Module: Perishable
Filename: main.cpp
Version 1.1
Author: Fardad Soleimanloo   2022-03-27
Revision History
-----------------------------------------------------------
Date          Reason
22-03-28      Added Rule of three tester
Name: MOHAMED ASHRAF BHAROT DATE:2023-11-29
-----------------------------------------------------------*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include "Item.h"
#include "Date.h"
namespace sdds
{
	class Perishable : public Item
	{
	private:
		Date m_expiry;
		char* m_instructions; // headline 
	public:
		Perishable();

		Perishable(const Perishable& perishable);
		Perishable& operator=(const Perishable& perishable);
		~Perishable();

		const Date& expiry()const;

		ofstream& save(ofstream& ofstr)const;
		ifstream& load(ifstream& ifstr);
		ostream& display(ostream& ostr)const;
		int readSku(istream& istr);
		istream& read(istream& istr);
	};
}

#endif // !SDDS_PERISHABLE_H

