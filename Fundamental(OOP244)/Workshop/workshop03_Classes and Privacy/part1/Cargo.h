/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CARGO_H	// header guards
#define SDDS_CARGO_H
//#include "Train.h"

namespace sdds
{
	const int MAX_DESC = 20;

	struct Cargo{
		char cargoDesc[MAX_DESC];
		double weight;	
	};
}
#endif
