/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include"Gift.h"
using namespace std;

namespace sdds
{
    void gifting(char* desc) {
        cout << "Enter gift description: ";
        cin.width(MAX_DESC + 1);
        cin >> desc;
    }

    void gifting(double& price) {
        int keeptrying = 1;

        cout << "Enter gift price: ";
        do
        {
            price = userInput();
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

        cout << "Enter gift units: ";
        do
        {
            units = userInput();
            if (units < 1) {
                cout << "Gift units must be at least 1" << endl;
            }
            else {
                keeptrying = 0;
            }
        } while (keeptrying == 1);
    }

    void gifting(Gift& theGift){
        cout << "Preparing a gift..." << endl;
        gifting(theGift.m_description);
        gifting(theGift.m_price);
        gifting(theGift.m_units);
        wrap(theGift);
    }

    void display(const Gift& theGift) {
        cout << "Gift Details:" << endl;
        cout << " Description: " << theGift.m_description << endl;
        cout << "       Price: " << theGift.m_price << endl;
        cout.setf(ios::fixed);
        cout.precision(0);
        cout << "       Units: " << theGift.m_units << endl;

        if (theGift.m_wrapLayers == 0) {
            cout << "Unwrapped!" << endl;
        }
        else {
            cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
            for (int i = 0; i < theGift.m_wrapLayers; i++) {
                cout << "Wrap #" << (i + 1) << " -> " << theGift.m_wrap[i].m_pattern << endl;
            }
        }
    }

    bool wrap(Gift& theGift) {
        if (theGift.m_wrapLayers != 0) {
            cout << "Gift is already wrapped!" << endl;
            return false;
        }
        else {
            cout << "Wrapping gifts..." << endl;
            int keeptrying = 1;
            
            do {
                cout << "Enter the number of wrapping layers for the Gift: ";
                theGift.m_wrapLayers = userInput();
                if (theGift.m_wrapLayers < 1) {
                    cout << "Layers at minimum must be 1, try again." << endl;
                }
                else {
                    keeptrying = 0;
                }
            } while (keeptrying == 1);

            theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];
            
            char  tempPattern[100];   // a temporary place to hold new word
            for (int i = 0; i < theGift.m_wrapLayers; i++) {
                cout << "Enter wrapping pattern #" << (i+1) << ": ";
                cin >> tempPattern;
                int len = strlen(tempPattern) + 1;
                theGift.m_wrap[i].m_pattern = nullptr;  // memory allocation
                theGift.m_wrap[i].m_pattern = new char[len];
                strcpy(theGift.m_wrap[i].m_pattern, tempPattern);
            }
            return true;
        }   
    }

    bool unwrap(Gift& theGift){
        if (theGift.m_wrapLayers == 0) {
            cout << "Gift isn't wrapped! Cannot unwrap." << endl;
            return false;
        }
        else {
            for (int i = 0; i < theGift.m_wrapLayers; i++) {
                delete [] theGift.m_wrap[i].m_pattern; // memory deallocation
                theGift.m_wrap[i].m_pattern = nullptr;
            }
            theGift.m_wrapLayers = 0;
            cout << "Gift being unwrapped." << endl;

            delete[] theGift.m_wrap;    // memory deallocation
            theGift.m_wrap = nullptr;

            return true;
        }        
    }

    double userInput() {
        int keeptrying = 1, rc;
        double value;
        char after;

        do
        {
            rc = scanf("%lf%c", &value, &after);
            if (rc == 0) {
                cout << "Invalid Number, try again: ";
                cin.clear();
                cin.ignore(2000, '\n');
            }
            else if (after != '\n') {
                cout << "Invalid trailing characters, try again: ";
                cin.clear();
                cin.ignore(2000, '\n');
            }
            else {
                keeptrying = 0;
            }
        } while (keeptrying == 1);
        return value;
    }

}