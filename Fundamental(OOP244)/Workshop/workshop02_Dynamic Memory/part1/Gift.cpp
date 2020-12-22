/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<iostream>
#include<cstring>
#include"Gift.h"
using namespace std;

namespace sdds{
    void gifting(char* desc) {
        cout << "Enter gift description: ";
        cin.width(MAX_DESC + 1);
        cin >> desc;
    }

    void gifting(double& price) {
	    int keeptrying = 1;
        do
        {
            cout << "Enter gift price: ";
            cin >> price;
            if (price < 0 || price > MAX_PRICE) {
                cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
            }
            else {
                keeptrying = 0;
            }
        } while (keeptrying == 1);
    }

    void gifting(int& units) {
        int keeptrying = 1;
        do
        {
            cout << "Enter gift units: ";
            cin >> units;
            if (units < 1) {
                cout << "Gift units must be at least 1" << endl;
            }
            else {
                keeptrying = 0;
            }
        } while (keeptrying == 1);
    }

    void display(const Gift& theGift) {
        cout << "Gift Details:" << endl;
        cout << " Description: " << theGift.m_description << endl;
        cout << "       Price: " << theGift.m_price << endl;
        cout << "       Units: " << theGift.m_units << endl << endl;
    }
}