/***********************************************************************

Name: MOHAMED ASHRAF BHAROT
STUDENT ID : 139539225
EMAIL: mamabharot@myseneca.ca
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include "Utils.h"
#include "Item.h"
#include "Perishable.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

namespace sdds
{
    // the construcotr recives a filename from and intializes the main menu with all the option
    AidMan::AidMan(const char *fileName) : mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database")
    {
        if (fileName && strlen(fileName) > 0) //  filename is copied and dynamically kept in the filename attribute only if it is not nullptr
        {
            filename = new char[strlen(fileName) + 1];
            strcpy(filename, fileName);
        }
        else // if it is nullptr then the filename attribute will be nullptr as well.
        {
            filename = nullptr;
        }
    }

    AidMan::~AidMan() // destructor to ensure there is no memory leak
    {
        deallocateItems();
        delete[] filename;
    }

    void AidMan::run() // it is just an display program which returns nothing and display the option according to user selected option
    {
        bool check = true;
        while (true)
        {
            std::cout << "Aid Management System" << std::endl;

            std::cout << "Date: 2023/12/09" << std::endl;
            std::cout << "Data file: " << (filename ? filename : "No file") << std::endl;
            std::cout << "---------------------------------\n";

            unsigned int choice = menu();
            if (check)
            {
                check = false;
                choice = 7;
            }
            switch (choice)
            {
            case 0:
                std::cout << "Exiting Program!" << std::endl;
                return;
            case 1:
                std::cout << "\n****List Items****\n";
                list();
                break;
            case 2:
                std::cout << "\n****Add Item****\n";
                additem();
                save();
                break;
            case 3:
                std::cout << "\n****Remove Item****\n\n";
                break;
            case 4:
                std::cout << "\n****Update Quantity****\n\n";
                break;
            case 5:
                std::cout << "\n****Sort****\n\n";
                break;
            case 6:
                std::cout << "\n****Ship Items****\n\n";
                break;
            case 7:
                std::cout << "\n****New/Open Aid Database****\n";
                load();
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
            }
            cout << endl;
        }
        cout << "Exiting Program!" << endl;
        save();
        deallocateItems();
    }

    void AidMan::save()
    {
        if (filename != nullptr)
        {
            ofstream file(filename);
            for (int i = 0; i < noOfItems; i++)
            {
                items[i]->save(file);
                file << endl;
            }
            file.close();
        }
    }

    void AidMan::deallocateItems()
    {
        for (int i = 0; i < noOfItems; i++)
        {
            delete items[i];
        }
        noOfItems = 0;
    }

    bool AidMan::load()
    {
        string temp = "";
        save();
        deallocateItems();

        cout << "Enter file name: ";
        getline(cin, temp, '\n');
        ut.alocpy(filename, temp.c_str());

        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Failed to open" << filename << "for reading!" << endl;
            cout << "Would you like to create a new data file?" << endl;
            cout << "1- Yes!" << endl;
            cout << "0- Exit" << endl;
            if (ut.getint(0, 1, "> "))
            {
                ofstream temp(filename);
                temp.close();
            }
        }
        else
        {
            while (!file.eof() && file)
            {
                if (file.peek() == '1' || file.peek() == '2' || file.peek() == '3')
                {
                    items[noOfItems] = new Perishable();
                }
                else if (file.peek() == '4' || file.peek() == '5' || file.peek() == '6' || file.peek() == '7' || file.peek() == '8' || file.peek() == '9')
                {
                    items[noOfItems] = new Item();
                }
                else
                {
                    file.setstate(ios::failbit);
                }
                if (!file.fail())
                {
                    items[noOfItems]->load(file);
                    if (items[noOfItems]->operator bool())
                    {
                        noOfItems++;
                    }
                    else
                    {
                        delete items[noOfItems];
                    }
                }
            }
            if (noOfItems > 0)
            {
                cout << noOfItems << " records loaded!\n";
                return true;
            }
        }
        file.close();
        return false;
    }

    int AidMan::list(const char *sub_desc)
    {
        int temp = 0;
        cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
        cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
        for (int i = 0; i < noOfItems; i++)
        {
            if (!(sub_desc) || items[i]->operator==(sub_desc))
            {
                items[i]->linear(true);
                cout << setw(4) << setfill(' ') << right << (i + 1) << " | ";
                items[i]->display(cout);
                cout << endl;
                temp++;
            }
        }

        cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
        cout << "Enter row number to display details or <ENTER> to continue:\n> ";
        string input = "";
        getline(cin, input, '\n');
        if (input != "")
        {
            int temp = stoi(input);
            items[temp - 1]->linear(false);
            items[temp - 1]->display(cout);
            cout << endl;
        }
        return temp;
    }

    int AidMan::search(int sku) const
    {

        ifstream file(filename);

        for (int i = 0; i < noOfItems; i++)
        {
            if(items[i]->operator==(sku)) 
            {
            
                return i;
            }
        }
        return -1;
    }

    void AidMan::additem()
    {
        int choice;
        if (noOfItems >= sdds_max_num_items)
        {
            cout << "Database full!" << endl;
        }
        std::cout << "1- Perishable\n";
        std::cout << "2- Non-Perishable\n";
        std::cout << "-----------------\n";
        std::cout << "0- Exit\n";
        choice = ut.getint(0, 2, "> ", nullptr);
        if (choice ==0)
        {
            cout << "Aborted\n";
            return;
        }
       
        iProduct* new_item = nullptr;
        if (choice ==1 )
        {
            new_item = new Perishable();
        }
        else if (choice ==2 )
        {
            new_item = new Item();
        }
        else {
            std::cout << "Invalid choice!\n";
            return;
        }
       
        int found;
        int xy;
      found = new_item->readSku(cin);
    xy =   search(found);
        if (xy != -1)
        {
            cout << "Sku: " << found << " is already in the system, try updating quantity instead.\n";
            delete new_item;
            return;
        }
        else
        {
            new_item->read(cin);
        }
       
        if (new_item->operator bool()) {
            items[noOfItems] = new_item;
            noOfItems++;
        }
        else {
            new_item->display(std::cout);
            delete new_item;
            return; // Exit function as item is invalid
        }
    }

    unsigned int AidMan::menu() //  it will simply return the user selected option to above run function
    {
        return mainMenu.run(); // calling run function
    }
}