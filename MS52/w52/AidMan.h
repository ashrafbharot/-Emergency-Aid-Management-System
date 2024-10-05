/***********************************************************************

Name: MOHAMED ASHRAF BHAROT 
STUDENT ID : 139539225	
EMAIL: mamabharot@myseneca.ca
***********************************************************************/
#pragma once
#ifndef AIDMAN_H
#define AIDMAN_H
#include "Menu.h"
#include "iProduct.h"
namespace sdds {
	    
	const int sdds_max_num_items = 100;
	class AidMan {

		char* filename = nullptr; // this attribute  holds the name of the data file holding the aid & product information 
		Menu mainMenu; // a main menu object  
		iProduct* items[sdds_max_num_items];
		int noOfItems = 0;
	public:
		AidMan(const char* fileName = nullptr); // one-argument constructor 
		~AidMan(); // destructor
		AidMan(const AidMan&) = delete; // copy constructor 
		AidMan& operator=(const AidMan) = delete; // copy operator

		// this  function displays the menu in the loop and perfroms task chossen in this 
		void run();

		void save();
		void deallocateItems();
		bool load();
		int list(const char* sub_desc = nullptr);

		int search(int sku) const;
		void additem();
	private:
		unsigned int menu(); // this function recives nothing and returns and integer which shows the user selected opition from the menu 


	};
}

#endif