/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Employee.h"
using namespace std;

namespace sdds
{
	Employee::Employee(float hourlySalary, const int hours) : minNumberOfHours(hours) {
		this->hourlySalary = hourlySalary;
	}

	std::ostream& Employee::display(std::ostream& out) const {
		out.width(this->getIndentation());
		out << "Pay Rate: " << this->hourlySalary << endl;
		out.width(this->getIndentation());
		out << "Min Hours: " << this->minNumberOfHours << endl;
		return out;
	}

	std::ostream& operator<<(std::ostream& out, const Employee& employee) {
		employee.display(out);
		return out;
	}

	void Employee::setIndentation(const int indent) {
		this->indentation = indent;
	}

	int Employee::getIndentation() const {
		return this->indentation;
	}
}