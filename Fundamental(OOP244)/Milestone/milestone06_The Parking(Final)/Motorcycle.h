/* Citation and Sources...
Final Project Milestone 6
Module: Motorcycle
Filename: Motorcycle.h
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/23 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_MOTORCYCLE_H	// header guards
#define SDDS_MOTORCYCLE_H
#include <iostream>
#include "Vehicle.h"
using namespace std;

namespace sdds
{
	class Motorcycle : public Vehicle
	{
		bool hasSidecarFlag;
	protected:
		bool getHasSidecarFlag() const;
		void setHasSidecarFlag(const bool flag);
	public:
		Motorcycle();	// Constructor with no-argument
		Motorcycle(const char* licensePlate, const char* makeAndModel);	// Constructor with two-arguments
		Motorcycle(const Motorcycle&) = delete;	// Vehicle can not get copied or assigned to another Vehicle
		virtual ~Motorcycle();	// Destructor
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
}
#endif