/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Engineer.h"
using namespace std;

namespace sdds
{
	Engineer::Engineer(float hourlySalary, int levelOfEngineer) : Employee(hourlySalary, 30){
		this->setIndentation(20);
		this->levelOfEngineer = levelOfEngineer;
	}

	ostream& Engineer::display(ostream& out) const {
		out << "Engineer" << endl;
		out.width(this->getIndentation());
		out << "Level: " << this->levelOfEngineer << endl;
		Employee::display();
		return out;
	}

	double Engineer::getSalary(int workedHours) {
		double salary;
		salary = workedHours * this->getHourlySalary() + 40 * this->levelOfEngineer;
		if (workedHours < this->getMinimumWorkingHours()) {
			salary *= 0.8;
		}
		return salary;
	}
}