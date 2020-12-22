/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include "Truck.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds
{
	Truck::Truck(){	}

	Truck::Truck(const char* licensePlateNo, int year, float maxCapacity, const char* address, float load, bool isUserPrompt) : MotorVehicle(licensePlateNo, year){
		this->capacity = maxCapacity;
		this->currenCargoLoad = load;
		this->isUserPrompt = isUserPrompt;

		if(this->isUserPrompt == false){ 
			this->moveTo(address);
		}
		else {
			this->setAddr(address);
		}
	}

	Truck::~Truck(){

	}

	bool Truck::addCargo(double cargo) {
		bool returnVal = true;
		if (this->currenCargoLoad < this->capacity) {
			this->currenCargoLoad += cargo;
			this->currenCargoLoad = min(this->currenCargoLoad, this->capacity);
		}
		else {
			returnVal = false;
		}
		return returnVal;
	}

	bool Truck::unloadCargo() {
		bool returnVal = true;
		if (this->currenCargoLoad != 0) {
			this->currenCargoLoad = 0;
		}
		else {
			returnVal = false;
		}
		return returnVal;
	}

	void Truck::write(std::ostream& os) const {
		MotorVehicle::write(os);
		os.setf(ios::fixed);
		os.precision(0);
		os << " | " << this->currenCargoLoad << "/" << this->capacity;
	}

	std::ostream& operator<<(std::ostream& os, const Truck& truck) {
		truck.write(os);
		return os;
	}

	void Truck::read(std::istream& is) {
		int yearInput;
		char licensePlateInput[32];
		char addressInput[64];
		double capacityInput;
		double truckLoad;
		
		cout << "Built year: ";
		is >> yearInput;
		cout << "License plate: ";
		is >> licensePlateInput;
		cout << "Current location: ";
		is >> addressInput;
		cout << "Capacity: ";
		is >> capacityInput;
		cout << "Cargo: ";
		is >> truckLoad;

		Truck temp(licensePlateInput, yearInput, capacityInput, addressInput, truckLoad, true);
		*this = temp;
	}

	std::istream& operator>>(std::istream& is, Truck& truck) {
		truck.read(is);
		return is;
	}
}