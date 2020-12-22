/* Citation and Sources...
Final Project Milestone 6
Module: Car
Filename: Car.h
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/23 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_CAR_H	// header guards
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
using namespace std;

namespace sdds
{
	class Car : public Vehicle
	{
		bool carwashFlag;
	protected:
		bool getCarwashFlag() const;
		void setCarwashFlag(const bool flag);
	public:
		Car();	// Constructor with no-argument
		Car(const char* licensePlate, const char* makeAndModel);	// Constructor with two-arguments
		Car(const Car&) = delete;	// Vehicle can not get copied or assigned to another Vehicle
		virtual ~Car();	// Destructor
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
}
#endif