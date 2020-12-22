/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include "Doctor.h"
using namespace std;

namespace sdds
{
	Doctor::Doctor(const char* typeOfDoctor, float hourlySalary, const int minNumberOfHours, bool isSpecialist) : Employee(hourlySalary, minNumberOfHours){
		strcpy(this->typeOfDoctor, typeOfDoctor);
		this->isSpecialist = isSpecialist;
		this->setIndentation(16);
	}

	std::ostream& Doctor::display(std::ostream& out) const {
		out << "Doctor" << endl;
		out.width(this->getIndentation());
		out << "Type: " << this->typeOfDoctor;
		if (this->isSpecialist == true) {
			out << " (specialist)" << endl;
		}
		else {
			out << endl;
		}
		Employee::display();		
		return out;
	}

	double Doctor::getSalary(int workedHours){
		double salary = 0;
		int extraTime;
		if (this->isSpecialist == false) {
			if (workedHours < this->getMinimumWorkingHours()) {
				salary = workedHours * this->getHourlySalary();
			}
			else{
				extraTime = workedHours - this->getMinimumWorkingHours();
				salary = this->getMinimumWorkingHours() * this->getHourlySalary() + extraTime * 1.5 * this->getHourlySalary();
			}
		}
		else {
			extraTime = max(workedHours - this->getMinimumWorkingHours(), 0);
			if (extraTime == 0) {
				salary = workedHours * this->getHourlySalary() + 2000;
			}
			else {
				salary = this->getMinimumWorkingHours() * this->getHourlySalary() + extraTime * 1.5 * this->getHourlySalary() + 2000;
			}	
		}
		return salary;
	}
}