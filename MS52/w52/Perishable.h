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

#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Item.h"
#include "Status.h"
#include "Date.h"
/*
this class is publicly derived from item class
this class contains one date object to record expiry date 
one dynamically pointer which stores the handlind instruction of the product
as usual these class also follows the rule of three 
it also has save , load , display and read function which overides the functions of item 

*/
namespace sdds
{
	class Perishable : public Item
	{
		
		char* handling = nullptr;
		Date expiry_date;
	public:
		Perishable();
		Perishable(const Perishable& p);
		Perishable& operator=(const Perishable& p);
		~Perishable();
		const Date& expiry() const;
		operator bool() const;
		int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

	};

}
#endif