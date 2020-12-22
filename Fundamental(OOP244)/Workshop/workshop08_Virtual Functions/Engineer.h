/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ENGINEER_H	// header guards
#define SDDS_ENGINEER_H
#include "Employee.h"

namespace sdds
{
	class Engineer : public Employee {
		int levelOfEngineer;
	public:
		Engineer(float hourlySalary, int levelOfEngineer);
		double getSalary(int workedHours);

		ostream& display(ostream& out = std::cout) const;
	};
}
#endif