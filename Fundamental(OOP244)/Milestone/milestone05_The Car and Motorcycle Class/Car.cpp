/* Citation and Sources...
Final Project Milestone 5
Module: Car
Filename: Car.cpp
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

#include "Car.h"
#include "Utils.h"

namespace sdds
{
	Car::Car() {
		// sets the Car (and therefore the Base class Vehicle) to a safe Invalid empty state
		//Vehicle::Vehicle();	
	}

	Car::Car(const char* licensePlate, const char* makeAndModel) {
		// the values are used to set the properties of the Vehicle
		//Vehicle::Vehicle(licensePlate, makeAndModel);	
	}

	Car::~Car() {
	}

	std::istream& Car::read(std::istream& istr) {
		if (this->isCsv()) {	// If the Car is set to Comma Separated mode 
			Vehicle::read(istr);	// calls the read of the Base class
			istr >> this->carwashFlag;
			istr.ignore(2000, '\n');	// ignores what ever character is left up to and including a newline character('\n')
		}
		else {	// If the Car is not set to Comma Separated mode 
			cout << endl << "Car information entry" << endl;
			Vehicle::read(istr);	// calls the read of the Base class
			cout << "Carwash while parked? (Y)es/(N)o: ";
			this->carwashFlag = yesNo();
		}
		return istr;	// istream object is returned
	}

	std::ostream& Car::write(std::ostream& ostr) const {
		if (this->isEmpty()) {	// If the Car is in an invalid empty state
			cout << "Invalid Car Object" << endl;
		}
		else {	// When the Car is not in an invalid empty state
			if (this->isCsv()) {	// If the class is in comma separated mode
				cout << "C,";
				Vehicle::write(ostr);	// write the base class
				cout << this->carwashFlag << endl;	// print the carwash flag 
			}
			else {	// If the class is not in comma separated mode
				cout << "Vehicle type: Car" << endl;
				Vehicle::write(ostr);	// write the base class
				if (this->carwashFlag == true) {
					cout << "With Carwash" << endl;	
				}
				else {
					cout << "Without Carwash" << endl;
				}
			}
		}
		return ostr;	// return the ostream object 
	}
}