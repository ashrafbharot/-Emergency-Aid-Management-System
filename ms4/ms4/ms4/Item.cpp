//Arafat Sarkar
//ID-144252202
//OOP244ZEE

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <iostream>
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    Item::Item()
    {

        m_price = 0;
        m_qty = 0;
        m_qtyNeeded = 0;
        m_sku = 0;
        m_linear = false;
        m_state = false;
        m_description = nullptr;
    }

    Item::Item(const Item& item)
    {

        if (item)
        {

            m_price = item.m_price;
            m_qty = item.m_qty;
            m_qtyNeeded = item.m_qtyNeeded;
            m_sku = item.m_sku;

            m_linear = item.m_linear;


            m_state = item.m_state;


            m_description = new char[strlen(item.m_description) + 1];
            strcpy(m_description, item.m_description);
        }
        else
        {
            m_description = nullptr;
        }

    }


    Item& Item::operator=(const Item& item)
    {
        delete[] m_description;
        m_description = nullptr;
        m_price = item.m_price;
        m_qty = item.m_qty;
        m_qtyNeeded = item.m_qtyNeeded;
        m_sku = item.m_sku;

        m_linear = item.m_linear;
        m_state = item.m_state;

        if (item)
        {
            m_description = new char[strlen(item.m_description) + 1];
            strcpy(m_description, item.m_description);
        }
        else
        {
            m_description = nullptr;
        }
        return *this;
    }

    Item::~Item()
    {
        m_price = 0;
        m_qty = 0;
        m_qtyNeeded = 0;
        m_sku = 0;

        m_linear = false;
        m_state = false;

        delete[] m_description;
        m_description = nullptr;
    }

    int Item::qtyNeeded() const
    {
        return m_qtyNeeded;
    }

    int Item::qty() const
    {
        return m_qty;
    }

    Item::operator double() const
    {
        return m_price;
    }

    Item::operator bool() const
    {
        if (m_state)
        {
            return true;
        }
        return false;
    }

    int Item::operator-=(int qty)
    {
        return m_qty -= qty;
        return m_qty;
    }

    int Item::operator+=(int qty)
    {
        return m_qty += qty;
        return m_qty;
    }

    void Item::linear(bool isLinear)
    {

        if (isLinear)
        {
            m_linear = true;
        }
        else
        {
            m_linear = false;
        }
    }

    void Item::clear()
    {
        m_price = 0;
        m_qty = 0;
        m_qtyNeeded = 0;
        m_sku = 0;

        delete[] m_description;
        m_description = nullptr;

        m_linear = false;
        m_state = false;
    }

    bool Item::operator==(int sku) const
    {
        bool value = false;
        if (m_sku == sku)
        {
            value = true;
        }
        return value;
    }

    bool Item::operator==(const char* description) const
    {
        if (strstr(m_description, description))
            return true;
        return false;
    }

    std::ofstream& Item::save(std::ofstream& ofstr) const
    {
        if (m_state)
        {
            ofstr << m_sku << "\t";
            ofstr << m_description << "\t";
            ofstr << m_qty << "\t" << m_qtyNeeded << "\t" << m_price;
        }
        return ofstr;
    }

    std::ifstream& Item::load(std::ifstream& ifstr)
    {
        delete[] m_description;
        m_description = new char[1000];

        if (ifstr)
        {
            ifstr >> m_sku;
            ifstr.ignore(1000, '\t');
            ifstr.getline(m_description, 1000, '\t');
            ifstr >> m_qty;
            ifstr >> m_qtyNeeded;
            ifstr >> m_price;
            m_state.clear();
            m_state = "This object is in a good state!";
            m_state = true;
        }

        return ifstr;
    }

    std::ostream& Item::display(std::ostream& ostr) const
    {
        if (m_linear == true)
        {
            ostr << m_sku << " | ";
            char des[36];

            strncpy(des, m_description, 35);
            des[35] = '\0';
            ostr << left << setw(35) << des;
            ostr << " | ";
            // int x1 = to_string(m_qty).length();
            // int x2 = to_string(m_qty).length();
            // int  x3 = to_string(m_price).length();
            // ostr << 
            ostr << right << setw(4) << m_qty << " | " << right << setw(4)
                << m_qtyNeeded << " | " << right << setw(7) << m_price << " |";
        }
        else
        {
            ostr << "AMA Item:" << endl;
            ostr << m_sku << ": " << m_description << endl;
            ostr << "Quantity Needed: " << m_qtyNeeded << endl;
            ostr << "Quantity Available: " << m_qty << endl;
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << "Unit Price: $" << m_price << endl;
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << "Needed Purchase Fund: $";
            ostr << m_price * (m_qtyNeeded - m_qty) << endl;
        }
        return ostr;
    }

    std::istream& Item::read(std::istream& istr)
    {
        Utils a;
        delete[] m_description;
        m_description = nullptr;
        m_description = new char[1000];

        cout << "AMA Item:\n";
        cout << "SKU: ";
        cout << m_sku << endl;
        cout << "Description: ";

        istr.ignore(1000, '\n');
        istr.getline(m_description, 1000);

        if (m_description == nullptr)
        {
            cout << "Console entry failed!";
        }

        cout << "Quantity Needed: ";
        m_qtyNeeded = a.checking_num(istr, 1, 9999);

        if (m_qtyNeeded < 1 || m_qtyNeeded > 9999)
        {
            cout << "Console entry failed!";
        }

        cout << "Quantity On Hand: ";
        m_qty = a.checking_num(istr, 0, 22);

        if (m_qtyNeeded < 0 || m_qtyNeeded > m_qtyNeeded)
        {
            cout << "Console entry failed!";
        }

        cout << "Unit Price: $";
        m_price = a.checking_float(istr, 0, 9999);

        if (m_price < 0.0 || m_price > 9999.0)
        {
            cout << "Console entry failed!";
        }
        m_state.clear();
        m_state = "This object is in a good state!";
        m_state = true;

        return istr;
    }

    int Item::readSku(std::istream& istr)
    {
        Utils a;
        cout << "SKU: ";
        m_sku = a.checking_num(istr, 40000, 99999);
        return -1;
    }
}
