/* ------------------------------------------------------
Final project Milestone 4
Module: Perishable
Filename : main.cpp
Version 1.1
Author : Fardad Soleimanloo   2022 - 03 - 27
Revision History
---------------------------------------------------------- -
Date          Reason
22 - 03 - 28      Added Rule of three tester
Name : MOHAMED ASHRAF BHAROT DATE : 2023 - 11 - 29
----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <iostream>
#include "Perishable.h"
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds {

Perishable::Perishable() : Item::Item()
{
 m_instructions = nullptr; 
 m_expiry.formatted(true);
}

Perishable::Perishable(const Perishable& perishable) : Item::Item(perishable)
{
    

 m_expiry = perishable.m_expiry;

 if (perishable)
 {
  m_instructions = new char[strlen(perishable.m_instructions) + 1];
  strcpy(m_instructions, perishable.m_instructions);
 }
 else
 {
  m_instructions = nullptr;
 }
}

Perishable& Perishable::operator=(const Perishable& perishable)
{
     delete[] m_instructions;
 m_instructions = nullptr;
 m_expiry = perishable.m_expiry;

 if (perishable)
 {
     Item::operator=(perishable);
  m_instructions = new char[strlen(perishable.m_instructions) + 1];
  strcpy(m_instructions, perishable.m_instructions);
 }
 else
 {
  m_instructions = nullptr;
 }
 return *this;
}

Perishable::~Perishable()
{
 delete[] m_instructions;
 m_instructions = nullptr;
 m_expiry.formatted(false);
}

const Date& Perishable::expiry() const
{
 return m_expiry;
}

int Perishable::readSku(std::istream& istr)
{
 Utils a;
 cout << "SKU: ";
 m_sku = a.checking_num(istr, 10000, 39999);
 return -1;
}

std::ofstream& Perishable::save(std::ofstream& ofstr) const
{
 if (m_state)
 {  
  Item::save(ofstr);
  ofstr << "\t";
  if (m_instructions != nullptr) {
   ofstr << m_instructions << "\t";
  }
  ofstr << m_expiry.uniqueValue();
 }
 return ofstr;
}

std::ifstream& Perishable::load(std::ifstream& ifstr) {
 Item::load(ifstr);

 delete[] m_instructions;
 m_instructions = nullptr;

 if (ifstr)
 {
  ifstr.ignore(1000, '\t');
   m_instructions = new char[1000];
  ifstr.getline(m_instructions, 1000, '\t');
  ifstr >> m_expiry;
  ifstr.ignore(1000, '\n');
 }
 

 return ifstr;
}

std::ostream& Perishable::display(std::ostream& ostr) const {
 if (m_linear) {
     ostr << setfill(' ');
     Item::display(ostr);
     if (m_instructions != nullptr && strlen(m_instructions) != 0)
     {
         ostr << "*";
  }
  else
  {
   ostr << " ";
  }
  ostr << m_expiry;
 }
 else
 {
     ostr << std::setfill(' ');
     ostr << "Perishable ";
     Item::display(ostr);
     ostr << "Expiry date: " << m_expiry << endl;
     if (m_instructions != nullptr && strlen(m_instructions) != 0)
     {
         ostr << "Handling Instructions: " << m_instructions << endl;
  }
 }
 return ostr;
}

std::istream& Perishable::read(std::istream& istr) {
 Item::read(istr);

 delete[] m_instructions;
 m_instructions = nullptr;
 m_instructions = new char[1000];

 cout << "Expiry date (YYMMDD): ";
 istr >> m_expiry;
 istr.ignore(1000, '\n');

 cout << "Handling Instructions, ENTER to skip: ";
 istr.getline(m_instructions, 1000);

 if (m_instructions[0] == '\n')
 {
  m_instructions = nullptr;
 }

 m_state = true;

 return istr;
}
}

 