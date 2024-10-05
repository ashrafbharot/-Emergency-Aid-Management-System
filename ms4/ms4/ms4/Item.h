//Arafat Sarkar
//ID-144252202
//OOP244ZEE

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"
using namespace std;
namespace sdds
{
	class Item : public iProduct
	{
	private:
		double m_price;
		int m_qty;
		int m_qtyNeeded;
		char* m_description;
	protected:
		bool m_linear;
		Status m_state;
		int m_sku;
		bool linear();
	public:
		Item();
		Item(const Item& item);
		Item& operator=(const Item& item);
		~Item();
		int qtyNeeded()const;
		int qty()const;
		operator double()const;
		operator bool()const;
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		void clear();
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		ofstream& save(ofstream& ofstr)const;
		ifstream& load(ifstream& ifstr);
		ostream& display(ostream& ostr)const;
		int readSku(istream& istr);
		istream& read(istream& istr);
	};
}

#endif // !SDDS_ITEM_H