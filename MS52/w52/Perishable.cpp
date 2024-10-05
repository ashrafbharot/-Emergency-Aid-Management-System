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
#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <sstream>
#include "Utils.h"
#include "Perishable.h"
#include "Item.h"
#include "Date.h"
using namespace std;
namespace sdds
{
	/// <summary>
	/// default construcotr which intializes the date to true & handlind to nullptr
	/// </summary>
	Perishable ::Perishable()
	{
		expiry_date.formatted(true);
		handling = nullptr;
	}

	Perishable ::Perishable(const Perishable &p) : Item(p)
	{
		// shallow copy
		expiry_date = p.expiry_date;
		if (p.handling != nullptr)
		{
			int len = strlen(p.handling);
			handling = new char[len + 1];
			strcpy(handling, p.handling);
		}
		else
		{
			handling = nullptr;
		}
	}
	Perishable &Perishable::operator=(const Perishable &p)
	{
		Item::operator=(p);
		if (this != &p)
		{
			expiry_date = p.expiry_date;

			delete[] handling;
			if (p.handling != nullptr)
			{
				int len = strlen(p.handling);
				handling = new char[len + 1];
				strcpy(handling, p.handling);
			}
			else
			{
				handling = nullptr;
			}
		}
		return *this;
	}
	Perishable::~Perishable()
	{

		delete[] handling;
	}
	/*
	it is a constant query called expiry that returns a constant reference of the expiry date. */
	const Date &Perishable::expiry() const
	{
		return expiry_date;
	}
	
	Perishable::operator bool() const
	{
		return desc() != nullptr;
	}
	/*
	ovveriding the readsku function of item.cpp to only receive SKU numbers between 10000 and 39999 (only SKUs starting with digits 1 to 3)*/
	int Perishable::readSku(std::istream &istr)
	{
		int sku;
		sku = ut.getint(10000, 39999, "SKU: ");
		i_sku = sku;
		return sku;
	}

	std::ofstream &Perishable::save(std::ofstream &ofstr) const
	{

		Item::save(ofstr);
		ofstr << "\t";
		if (handling) //   writes the handling instructions, if handling instructions exist and the attribute is not empty.
		{
			ofstr << handling;
		}
		ofstr << "\t";
		expiry_date.write(ofstr, false);

		return ofstr;
	}

	std::ifstream &Perishable::load(std::ifstream &ifstr)
	{
		string desc;
		Item::load(ifstr); // calls the load of the Base class.

		// Read handling instructions dynamically
		getline(ifstr, desc, '\t');
		ut.alocpy(handling, desc.c_str());
		// Read expiry date
		ifstr >> expiry_date; // reads the expiry date
		ifstr.ignore(1000, '\n');  
		// ignores the new line.

		if (ifstr.bad())
		{
			i_state = "Input file stream read (perishable) failed!";
		}
		return ifstr;
	}

	std::ostream &Perishable::display(std::ostream &ostr) const
	{
		if (!i_state)  // if the Perishable Item is in a bad state, the state is printed
		{
			ostr << i_state;
		}
		else
		{
			/*
			*  if linear
the display of the base class is called
if handling instructions are not null and not empty a single asterisk ('*') is printed otherwise a single space (' ') is printed.
the expiry date is printed
			*/
			if (Item_linear)
			{
				Item::display(ostr);
				// Include handling instructions (asterisk if not empty)
				if (handling && strlen(handling) > 0)
				{
					ostr << "*";
				}
				else
				{
					ostr << " ";
				}

				ostr << expiry_date;
			}
			else
			{
				ostr << "Perishable ";
				Item::display(ostr);

				// Display expiry date
				ostr << "Expiry date: ";
				ostr << expiry_date << endl;
				// Display handling instructions (if available)
				if (handling && strlen(handling) > 0)
				{
					ostr << "Handling Instructions: " << handling << std::endl;
				}
			}
		}
		return ostr;
	}

	std::istream &Perishable::read(std::istream &istr)
	{
		Item::read(istr);  // The read of the base class is called
		std::string desc;

		delete[] handling;  // the handling instructions memory is deleted and the attribute is set to null
		handling = nullptr;

		std::cout << "Expiry date (YYMMDD): ";
		istr >> expiry_date;

		istr.ignore();  // newline is ignored

		std::cout << "Handling Instructions, ENTER to skip: ";
		if (istr.peek() != '\n')
		{
			getline(istr, desc);
			ut.alocpy(handling, desc.c_str());
		}
		if (istr.fail())
		{
			i_state = "Perishable console date entry failed!";
		}

		return istr;
	}

}