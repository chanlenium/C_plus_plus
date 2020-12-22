/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Autoshop.h"

namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {	
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------\n" ;
		out << "| Cars in the autoshop!        |\n" ;
		out << "--------------------------------" ;
		for (auto iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++) {
			out << std::endl;
			(*iter)->display(out);
		}
		out << std::endl << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop() {
		for (size_t i = 0; i < m_vehicles.size(); i++) {
			delete m_vehicles[i];
		}
		m_vehicles.clear();
	}
}