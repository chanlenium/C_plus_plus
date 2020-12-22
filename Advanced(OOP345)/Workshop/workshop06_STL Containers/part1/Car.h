/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
//#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle{	// inherits the interface "Vehicle" 
		std::string mTag;		// a single character representing the type of vehicle
		std::string mMaker;		// the name of the company that makes the car
		std::string mCondition;	// a car can be new("n"), used("u"), or broken("b") in need of repairs
		double mTopSpeed;		// the maximum speed the vehicle can achieve
	public:
		// 1-argument constructor reading a single record from the stream, 
		// extracting all the information about a single car and storing it in the attributes.
		Car(std::istream& record);
		void trim(std::string& line);
		std::string condition() const;	// a query that returns new, used or broken
		double topSpeed() const;
		void display(std::ostream& out) const;	//  a query that inserts in the first parameter the content of the car object
		//bool isValid(Car& car);
	};
}
#endif
