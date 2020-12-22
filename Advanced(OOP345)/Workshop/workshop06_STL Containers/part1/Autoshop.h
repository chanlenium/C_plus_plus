/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
//#include <iostream>
//#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop{
		std::vector<Vehicle*> m_vehicles;	// a vector that store all the vehicles available at this autoshop.
	public:
		Autoshop& operator +=(Vehicle* theVehicle);	// adds the vehicle received as parameter into the m_vehicles vector.
		// iterates over the vehicles stored in m_vehicles and prints them into the parameter (use Vehicle::display()) using the format:
		void display(std::ostream& out) const;
		~Autoshop();
	};

}
#endif
