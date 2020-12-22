/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/***********************************************************************
// Workshop 2: Dynamic Memory & Function Overloading
// Version 2.0
// Date	2020/05/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Gift.h"
//#include "Gift.h" // Intentional
using namespace std;
using namespace sdds;

int main() {
    int numberOfGifts = 0; // Initial number of Gifts
    int keeptrying = 1; // variable to check input validation

    // TODO 1: declare a pointer for a dynamic array of Gifts (remember to initialize it)
    Gift* gift = nullptr;
    // END TODO 1

    do {
        cout << "Enter number of Gifts to allocate: ";
        cin >> numberOfGifts;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(2000, '\n');
            cout << "You have entered wrong input" << endl;
            break;
        }
        else if (numberOfGifts < 1) {
            return 1;
        }
        else {
            keeptrying = 0;
        }
    } while (keeptrying == 1);

    

    // TODO 2: allocate dynamic memory for the gifts pointer using the numberOfGifts
    gift = new Gift[numberOfGifts];
    // END TODO 2

    for (int i = 0; i < numberOfGifts; ++i)
    {
        cout << "Gift #" << i + 1 << ": " << endl;
        
        // TODO 3: utilizing the gifting functions, allow input for the gift's description
        gifting(gift[i].m_description);
        // END TODO 3
        
        cin.ignore(2000, '\n'); // clear input buffer
        
        // TODO 4: utilizing the gifting functions, allow the user to input the gift's price
        gifting(gift[i].m_price);
        // END TODO 4
        
        cin.ignore(2000, '\n'); // clear input buffer
        
        // TODO 5: utilizing the gifting functions, allow the user to input the units of gift
        gifting(gift[i].m_units);
        // END TODO 5
        cin.ignore(2000, '\n');
        cout << endl;
    }



    // TODO 6: display the details of each gift using the Gifts module display function
    for (int i = 0; i < numberOfGifts; ++i) {
        cout << "Gift #" << i + 1 << ": " << endl;
        display(gift[i]);
    }
    // END TODO 6



    // TODO 7: deallocate the gifts pointer here to avoid memory as we are done with it
    delete[] gift;
    gift = nullptr;
    // END TODO 7

    return 0;
}