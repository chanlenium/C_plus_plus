/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <vld.h>
#include<cstring>
#include<iostream>
#include "Train.h"
using namespace std;

namespace sdds
{
	void Train::initialize(const char* name, int id) {
		if (name == nullptr) {
			name = NULL;
			cargoName[0] = '\0';
			cargoId = -1;
			//cargo = NULL;
			cargo = nullptr;
		}
		else {
			if (name[0] != '\0' && id > 0) {
				int len = strlen(name);
				strncpy(cargoName, name, len);
				cargoName[len] = '\0';
				cargoId = id;
				//cargo = NULL;
				cargo = nullptr;
			}
			else {
				cargoName[0] = '\0';
				cargoId = -1;
				//cargo = NULL;
				cargo = nullptr;
			}
		}
	}

	bool Train::isValid() const {
		bool valid = false;
		valid = (cargoName[0] != '\0') && (cargoId > 0);
		return valid;
	}

	void Train::loadCargo(Cargo car) {
		if (cargo != nullptr) {
			delete cargo;
		}
		cargo = nullptr;
		cargo = new Cargo;
		int len = strlen(car.cargoDesc);
		strncpy(cargo->cargoDesc, car.cargoDesc, len);
		cargo->cargoDesc[len] = '\0';
		cargo->weight = car.weight;
	}

	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}

	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if ((cargoName == nullptr) || (cargoName[0] == '\0') || (cargoId < 0)) {
			cout << "This is an invalid train." << endl;
		}
		else {
			cout << "Name: " << cargoName << endl;
			cout << "ID: " << cargoId << endl;
			if (cargo == NULL) {
				cout << "No cargo on this train." << endl;
			}
			else {
				cout << "Cargo: " << cargo->cargoDesc << endl;
				cout.setf(ios::fixed);
				cout.precision(cargoId+1);
				cout << "Weight: " << cargo->weight << endl;
			}
		}
	}
}