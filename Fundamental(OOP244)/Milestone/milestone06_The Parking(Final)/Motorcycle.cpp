/* Citation and Sources...
Final Project Milestone 6
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
			bool tempFlag;
			//istr >> this->hasSidecarFlag;
			istr >> tempFlag;
			this->setHasSidecarFlag(tempFlag);
			istr.ignore(2000, '\n');
		}
		else {
			cout << endl << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			this->setHasSidecarFlag(yesNo());
		}
		return istr;
	}

	std::ostream& Motorcycle::write(std::ostream& ostr) const {
		if (this->isEmpty()) {
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else {
			if (this->isCsv()) {
				ostr << "M,";
				Vehicle::write(ostr);
				ostr << this->getHasSidecarFlag() << endl;
			}
			else {
				ostr << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(ostr);
				if (this->getHasSidecarFlag() == true) {
					ostr << "With Sidecar" << endl;
				}
			}
		}
		return ostr;
	}

	bool Motorcycle::getHasSidecarFlag() const {
		return this->hasSidecarFlag;
	}

	void Motorcycle::setHasSidecarFlag(const bool flag) {
		this->hasSidecarFlag = flag;
	}
}