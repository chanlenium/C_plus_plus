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
#include "MotorVehicle.h"
using namespace std;

namespace sdds
{
	MotorVehicle::MotorVehicle() {}

	MotorVehicle::MotorVehicle(const char* licensePlateNo, int year, const char* address) {
		int len = strlen(licensePlateNo);
		strncpy(this->licensePlateNo, licensePlateNo, len);
		this->licensePlateNo[len] = '\0';
		this->year = year;
		
		if (address == nullptr) {
			strcpy(this->address, "Factory");
		}
		else {
			int lenAddr = strlen(address);
			strncpy(this->address, address, lenAddr);
			this->address[lenAddr] = '\0';
		}
	}

	MotorVehicle::~MotorVehicle() {	}

	std::ostream& MotorVehicle::write(ostream& os) const{
		os << "| " << this->year;
		os << " | " << this->licensePlateNo;
		os << " | " << this->address;

		return os;
	}

	void MotorVehicle::setAddr(const char* newAddress) {
		int len = strlen(newAddress);
		strncpy(this->address, newAddress, len);
		this->address[len] = '\0';
	}

	void MotorVehicle::moveTo(const char* newAddress) {
		if (strcmp(this->address, newAddress)) {
			cout << "|";
			cout.width(10);
			cout << this->licensePlateNo;
			cout << "| |";
			cout.width(20);
			cout << this->address;
			cout << " --->--- ";
			cout.width(20);
			cout.setf(ios::left);
			cout << newAddress;
			cout << "|" << endl;
			cout.unsetf(ios::left);
			int len = strlen(newAddress);
			strncpy(this->address, newAddress, len);
			this->address[len] = '\0';
		}
	}

	std::ostream& operator<<(ostream& os, const MotorVehicle& motorVehicle) {
		motorVehicle.write(os);
		return os;
	}

	std::istream& operator>>(istream& is, MotorVehicle& motorVehicle) {
		motorVehicle.read(is);
		return is;
	}

	std::istream& MotorVehicle::read(istream& is) {
		int yearInput;      
		char licensePlateInput[32];
		char addressInput[64];

		cout << "Built year: ";
		is >> yearInput;
		cout << "License plate: ";
		is >> licensePlateInput;
		cout << "Current location: ";
		is >> addressInput;

		MotorVehicle temp(licensePlateInput, yearInput);
		strcpy(temp.address, addressInput);
		*this = temp;

		return is;
	}
}