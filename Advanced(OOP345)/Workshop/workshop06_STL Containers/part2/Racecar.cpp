/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in) {
		std::string token;
		std::getline(in, token, ',');
		trim(token);
		mBooster = stod(token);
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {	// returns the top speed of the car, including any booster effects.
		return Car::topSpeed() * (1 + mBooster);
	}
}