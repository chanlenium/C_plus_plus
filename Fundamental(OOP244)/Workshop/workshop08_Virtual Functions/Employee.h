/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_EMPLOYEE_H	// header guards
#define SDDS_EMPLOYEE_H
#include <iostream>

using namespace std;

namespace sdds
{
	class Employee {
		const int minNumberOfHours;
		double hourlySalary;
		int indentation;
	protected:
		int getMinimumWorkingHours() {
			return minNumberOfHours;
		};
		double getHourlySalary() {
			return hourlySalary;
		};
	public:
		Employee(int t) : minNumberOfHours(t) {}	// initilizer list
		Employee(float hourlySalary, const int minNumberOfHours);
		virtual double getSalary(int workedHours) = 0;	// a pure virtual query
		virtual ostream& display(ostream& out = std::cout) const = 0;	// a pure virtual query
		virtual ~Employee() {};	// virtual empty destructor
		// When pointer is destructed, it will know to call the implicit Derived::~Derived() before calling Base::~Base()
		void setIndentation(const int indent);
		int getIndentation() const;
	};
	std::ostream& operator<<(std::ostream& out, const Employee& employee);
}
#endif
