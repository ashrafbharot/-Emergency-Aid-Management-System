/**********************************************************************************

Name		   - Arth Patel
Email		   - parth-bimalbhai@myseneca.ca
student id     - 141716225
Section		   - ZCC
Date           - 14 Nov 2023
authentication :
I have done all the work on my own. I only used the files provided by the professor.
***********************************************************************************/

#ifndef SDDS_Item_H_
#define SDDS_Item_H_
#include <fstream>
#include "iProduct.h"
#include "Status.h"
namespace sdds {
    class Item : public iProduct {
        double Item_price;
        int Item_qty;
        int Item_qtyNeeded;
        char* Item_desc = nullptr;

    protected:
        bool Item_linear;
        Status i_state;
        int i_sku{};
        bool linear()const;
    public:
        Item();
        Item(const Item& I);
        Item& operator=(const Item& I);
        ~Item();

         char* desc() const;
        virtual int qtyNeeded()const;
        virtual int qty()const;
        virtual  operator double()const;
        virtual operator bool() const;

        virtual int operator-=(int qty);
        virtual int operator+=(int qty);
        virtual void linear(bool isLinear);

        virtual void clear();

        virtual bool operator==(int sku)const;
        virtual bool operator==(const char* description) const;

        virtual std::ofstream& save(std::ofstream& ofstr)const;
        virtual std::ifstream& load(std::ifstream& ifstr);
        virtual std::ostream& display(std::ostream& ostr)const;
        virtual  std::istream& read(std::istream& istr);
        virtual int readSku(std::istream& istr);

    };
}

#endif // !SDDS_Item_H_
