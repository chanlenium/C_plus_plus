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
	const double MAX_WEIGHT = 777.555;
	const double MIN_WEIGHT = 44.2222;

	// store a description of the cargo (as a statically allocated array of characters) and the weight of the cargo (in tonnes)
	class Cargo{
		// Valid Description: a string of at most MAX_DESC characters (not including the null terminator)
		char cargoDesc[MAX_DESC+1]; 

		// Valid Weight: a floating point number in double precision in the interval [MIN_WEIGHT, MAX_WEIGHT]
		double cargoWeight;	

	public:
		// a modifier that receives two parameters(descriptionand weight).
		void initialize(const char* desc, double weight); 
		
		// a query that returns the description of the cargo
		const char* getDesc() const;	

		// a query that returns the weight of the cargo
		double getWeight() const;	

		// a modifier that sets the description of the cargo. If the string is longer than MAX_DESC, accept only MAX_DESC characters.
		void setDesc(const char* description); 

		// a modifier that sets the weight of the cargo. If the parameter is invalid, set the attribute to MIN_WEIGHT.
		void setWeight(double weight); 
	};
}
#endif
