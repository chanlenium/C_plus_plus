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
#include <algorithm>
#include "Cargo.h"
using namespace std;

namespace sdds
{
	void Cargo::initialize(const char* desc, double weight) {
		if (desc != nullptr && desc[0] != '\0') {
			setDesc(desc);
			setWeight(weight);
		}
		else {
			cargoDesc[0] = '\0';
			cargoWeight = 0;
		}
	}

	const char* Cargo::getDesc() const {
		return cargoDesc;
	}

	double Cargo::getWeight() const {
		return cargoWeight;
	}

	void Cargo::setDesc(const char* description) {
		int len = strlen(description);
		len = min(len, MAX_DESC);

		strncpy(cargoDesc, description, len);
		cargoDesc[len] = '\0';
	};

	void Cargo::setWeight(double weight) {
		if (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT) {
			cargoWeight = weight;
		}
		else {
			cargoWeight = MIN_WEIGHT;
		}
	};
}