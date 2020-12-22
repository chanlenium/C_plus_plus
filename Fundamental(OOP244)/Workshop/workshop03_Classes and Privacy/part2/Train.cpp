/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
//#include <vld.h>
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
		}
		else {
			if (name[0] != '\0' && id > 0) {
				int len = strlen(name);
				strncpy(cargoName, name, len);
				cargoName[len] = '\0';
				cargoId = id;
			}
			else {
				cargoName[0] = '\0';
				cargoId = -1;
			}
		}
		cargo = nullptr;
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
		car.getDesc();
		cargo->setDesc(car.getDesc());
		cargo->setWeight(car.getWeight());
	}

	bool Train::swapCargo(Train& other) {
		bool returnVal = true;
		if (cargo != NULL && other.cargo != NULL) {
			Cargo tempCargo;

			tempCargo.setDesc(other.cargo->getDesc());
			tempCargo.setWeight(other.cargo->getWeight());

			other.cargo->setDesc(cargo->getDesc());
			other.cargo->setWeight(cargo->getWeight());

			cargo->setDesc(tempCargo.getDesc());
			cargo->setWeight(tempCargo.getWeight());
		}
		else {
			returnVal = false;
		}
		return returnVal;
	}

	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}


	bool Train::increaseCargo(double weight) {
		bool returnVal = true;
		if (cargo != NULL && cargo->getWeight() != MAX_WEIGHT) {
			double increasedWeight = cargo->getWeight() + weight;

			if (increasedWeight < MAX_WEIGHT) {
				cargo->setWeight(increasedWeight);
			}
			else {
				cargo->setWeight(MAX_WEIGHT);
			}
		}
		else {
			returnVal = false;
		}
		return returnVal;
	}

	bool Train::decreaseCargo(double weight) {
		bool returnVal = true;
		if (cargo != NULL && cargo->getWeight() != MIN_WEIGHT) {
			double decreasedWeight = cargo->getWeight() - weight;

			if (decreasedWeight > MIN_WEIGHT) {
				cargo->setWeight(decreasedWeight);
			}
			else {
				cargo->setWeight(MIN_WEIGHT);
			}
		}
		else {
			returnVal = false;
		}
		cout.precision(4);
		return returnVal;
	}


	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if ((cargoName == nullptr) || (cargoName[0] == '\0') || (cargoId < 0)) {
			cout << "This is an invalid train." << endl;
		}
		else {
			cout << "    Name: " << cargoName << endl;
			cout << "      ID: " << cargoId << endl;
			if (cargo == NULL) {
				cout << "No cargo on this train." << endl;
			}
			else {
				cout << "   Cargo: " << cargo->getDesc() << endl;
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << "  Weight: " << cargo->getWeight() << endl;
			}
		}
		cout.precision(3);
	}
}