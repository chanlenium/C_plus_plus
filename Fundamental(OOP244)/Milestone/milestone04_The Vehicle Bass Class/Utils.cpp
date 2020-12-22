/* Citation and Sources...
Final Project Milestone 4
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/7 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds
{
	int getPosInt(int max, int min) {
		int value;
		int keepreading;

		keepreading = 1;
		do {
			cin >> value;

			if (cin.fail()) {   // check for invalid character
				cerr << "Invalid Integer, try again: ";
				cin.clear();
				cin.ignore(2000, '\n');
			}
			else if (value < min || value > max) {
				cerr << "Invalid selection, try again: ";
				cin.ignore(2000, '\n');
			}
			else if (char(cin.get()) != '\n') {
				cerr << "Trailing characters.  Try Again." << endl;
				cin.ignore(2000, '\n');
			}
			else
				keepreading = 0;
		} while (keepreading == 1);
		return value;
	}


	bool yesNo() {
		char inputVal;
		bool returnVal = false, run = true;
		do {
			cin >> inputVal;
			if (cin.fail() || char(cin.get()) != '\n') {
				cerr << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin.clear();
				cin.ignore(2000, '\n');
			}
			else {
				run = false;
				if (inputVal == 'N' || inputVal == 'n') {
					returnVal = false;
				}
				else if (inputVal == 'Y' || inputVal == 'y') {
					returnVal = true;
				}
				else {
					cerr << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin.clear();
					cin.ignore(2000, '\n');
				}
			}
		} while (run);

		return returnVal;
	}
}