/* Citation and Sources...
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.cpp
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/23 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#include "Motorcycle.h"
#include "Utils.h"

namespace sdds
{
	Motorcycle::Motorcycle() {
		// sets the Motorcycle ( and therefore the Base class Vehicle) to a safe Invalid empty state
		//Vehicle::Vehicle();
	}

	Motorcycle::Motorcycle(const char* licensePlate, const char* makeAndModel) {
		// the values are used to set the properties of the Vehicle
		//Vehicle::Vehicle(licensePlate, makeAndModel);
	}

	Motorcycle::~Motorcycle() {
	}

	std::istream& Motorcycle::read(std::istream& istr) {
		if (this->isCsv()) {
			Vehicle::read(istr);
			istr >> this->hasSidecarFlag;
			istr.ignore(2000, '\n');
		}
		else {
			cout << endl << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			this->hasSidecarFlag = yesNo();
		}
		return istr;
	}

	std::ostream& Motorcycle::write(std::ostream& ostr) const {
		if (this->isEmpty()) {
			cout << "Invalid Motorcycle Object" << endl;
		}
		else {
			if (this->isCsv()) {
				cout << "M,";
				Vehicle::write(ostr);
				cout << this->hasSidecarFlag << endl;
			}
			else {
				cout << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(ostr);
				if (this->hasSidecarFlag == true) {
					cout << "With Sidecar" << endl;
				}
			}
		}
		return ostr;
	}
}