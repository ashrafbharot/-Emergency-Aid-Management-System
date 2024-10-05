/**********************************************************************************

Name		   - Arth Patel
Email		   - parth-bimalbhai@myseneca.ca
student id     - 141716225
Section		   - ZCC
Date           - 14 Nov 2023
authentication :
I have done all the work on my own. I only used the files provided by the professor.
***********************************************************************************/
#include <iostream>
#include "iProduct.h"
namespace sdds {
    /*
    this function were genrating error that'why i commented it */


    // // read the stock-Keeping unit from the console before

    // int iProduct::readSku(std::istream& istr)
    // {
    //     int flag;
    //     istr >> flag;
    //     return flag;
    // }
    // // this operator function will reduce the qunatity 
    // int iProduct::operator-=(int qty)
    // {
    //     return qty; // returns qty after 
    // }

    // iProduct::operator double() const
    // {
    //     return 0.0;
    // }

    // iProduct::operator bool() const
    // {
    //     return false;
    // }

    // int iProduct::qtyNeeded() const
    // {
    //     return 0;
    // }

    // int iProduct::qty() const
    // {
    //     return 0;
    // }

    // void iProduct::linear(bool isLinear)
    // {
    //     std::cout << isLinear;
    // }

    // std::ofstream& iProduct::save(std::ofstream& ofstr) const
    // {
    //     return ofstr;
    // }

    // std::ifstream& iProduct::load(std::ifstream& ifstr)
    // {
    //     return ifstr;
    // }

    // std::ostream& iProduct::display(std::ostream& ostr) const
    // {
    //     return ostr;
    // }

     /*std::istream& iProduct::read(std::istream& istr)
     {
         return istr;
     }*/

    // bool iProduct::operator==(int sku) const
    // {
    //     return false;
    // }

    // bool iProduct::operator==(const char* description) const
    // {
    //     return false;
    // }

    // int iProduct::operator+=(int qty)
    // {
    //     return qty;
    // }

    std::ostream& operator<<(std::ostream& ostr, const iProduct& I)
    {
        return I.display(ostr);
    }

    std::istream& operator>>(std::istream& istr, iProduct& I)
    {
        return I.read(istr);
    }


}
