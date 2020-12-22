/* Citation and Sources...
Final Project Milestone 6
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
-----------------------------------------------------------*/

#include "Car.h"
#include "Utils.h"

namespace sdds
{
	Car::Car() {
		// sets the Car (and therefore the Base class Vehicle) to a safe Invalid empty state
	}

	Car::Car(const char* licensePlate, const char* makeAndModel) {
		// the values are used to set the properties of the Vehicle
	}

	Car::~Car() {
	}

	std::istream& Car::read(std::istream& istr) {
		if (this->isCsv()) {	// If the Car is set to Comma Separated mode 
			Vehicle::read(istr);	// calls the read of the Base class
			bool tempFlag;
			istr >> tempFlag;
			this->setCarwashFlag(tempFlag);
			istr.ignore(2000, '\n');	// ignores what ever character is left up to and including a newline character('\n')
		}
		else {	// If the Car is not set to Comma Separated mode 
			cout << endl << "Car information entry" << endl;
			Vehicle::read(istr);	// calls the read of the Base class
			cout << "Carwash while parked? (Y)es/(N)o: ";
			this->setCarwashFlag(yesNo());
		}
		return istr;	// istream object is returned
	}

	std::ostream& Car::write(std::ostream& ostr) const {
		if (this->isEmpty()) {	// If the Car is in an invalid empty state
			ostr << "Invalid Car Object" << endl;
		}
		else {	// When the Car is not in an invalid empty state
			if (this->isCsv()) {	// If the class is in comma separated mode
				ostr << "C,";
				Vehicle::write(ostr);	// write the base class
				ostr << this->getCarwashFlag() << endl;	// print the carwash flag 
			}
			else {	// If the class is not in comma separated mode
				ostr << "Vehicle type: Car" << endl;
				Vehicle::write(ostr);	// write the base class
				if (this->getCarwashFlag() == true) {
					ostr << "With Carwash" << endl;
				}
				else {
					ostr << "Without Carwash" << endl;
				}
			}
		}
		return ostr;	// return the ostream object 
	}

	bool Car::getCarwashFlag() const {
		return this->carwashFlag;
	}

	void Car::setCarwashFlag (const bool flag) {
		this->carwashFlag = flag;
	}
}