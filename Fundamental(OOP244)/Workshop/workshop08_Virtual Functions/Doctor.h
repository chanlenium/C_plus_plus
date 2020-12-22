/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_DOCTOR_H	// header guards
#define SDDS_DOCTOR_H
#include "Employee.h"

namespace sdds
{
	class Doctor : public Employee {
		char typeOfDoctor[32];
		bool isSpecialist;
	public:
		Doctor(const char* typeOfDoctor, float hourlySalary, const int minNumberOfHours, bool isSpecialist = false);
		double getSalary(int workedHours);
		std::ostream& display(std::ostream& out = std::cout) const;
	};
}
#endif


