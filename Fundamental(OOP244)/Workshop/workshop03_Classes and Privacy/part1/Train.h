/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TRAIN_H	// header guards
#define SDDS_TRAIN_H
#include "Cargo.h"

namespace sdds
{
	const int MAX_NAME = 30;

	class Train
	{
		char cargoName[MAX_NAME];
		int cargoId;
		Cargo* cargo;
	public:
		void initialize(const char*, int);
		bool isValid() const;
		void loadCargo(Cargo);
		void unloadCargo();
		void display() const;
	};
}
#endif
