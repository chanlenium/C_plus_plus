/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TRUCK_H	// header guards
#define SDDS_TRUCK_H
#include <iostream>
#include "MotorVehicle.h"

namespace sdds
{
	class Truck : public MotorVehicle
	{
		double capacity;	
		double currenCargoLoad;
		bool isUserPrompt;
	public:
		Truck();
		Truck(const char* licensePlateNo, int year, float maxCapacity, const char* address, float load = 0, bool isUserPrompt = false);
		bool addCargo(double cargo);
		bool unloadCargo();
		void read(std::istream& is);
		void write(std::ostream& os) const;
		~Truck();
	};
	std::istream& operator>>(std::istream&, Truck&);
	std::ostream& operator<<(std::ostream&, const Truck&);
}
#endif