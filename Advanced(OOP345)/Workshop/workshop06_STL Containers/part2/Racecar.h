/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <string>
#include <iostream>			// getline
#include "Car.h"

namespace sdds {
	class Racecar :public Car {
		double mBooster;	// the percentage(stored as a number between 0 an 1) by which this Racecar can boost its top speed.
	public:
		// calls the constructor from Car to build the subobject, 
		// and then it extracts the last field from the stream containing the booster bonus. 
		// The input format for a racecar is TAG,MAKER,CONDITION,TOP_SPEED,BOOSTER
		Racecar(std::istream& in);

		// calls Car::display() to print the information about the car, 
		// and adds* at the end.The format should be | MAKER | CONDITION | TOP_SPEED | *
		void display(std::ostream& out) const;

		double topSpeed() const;	// returns the top speed of the car, including any booster effects.
	};
}
#endif