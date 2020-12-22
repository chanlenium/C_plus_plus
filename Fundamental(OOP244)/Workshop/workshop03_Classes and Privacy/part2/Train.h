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

		bool swapCargo(Train& other); // swap the cargo between the two trains only if both trains are valid and carry valid cargo.Return true if a change has been made, false otherwise.
		bool increaseCargo(double weight);	// increases the carried cargo by weight tonnes only if the current train is valid, carries valid cargo and the new weight doesn't exceed MAX_WEIGHT. If the new cargo exceeds the capcity, do not accept more than capacity. Return true if a change has been made, false otherwise.
		bool decreaseCargo(double weight); // decreases the carried cargo by weight tonnes only if the current train is valid, carries valid cargoand the new weight is not less than MIN_WEIGHT.If the new cargo is below the lower limit, do not go below the lower limit.Return true if a change has been made, false otherwise.
	};
}
#endif
