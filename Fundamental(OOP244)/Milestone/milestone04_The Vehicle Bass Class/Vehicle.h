/* Citation and Sources...
Final Project Milestone 4
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/7 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_VEHICLE_H	// header guards
#define SDDS_VEHICLE_H
#include <iostream>
#include "ReadWritable.h"
using namespace std;

namespace sdds
{
	class Vehicle : public ReadWritable
	{
		char licensePlate[9];	// can be 1 to 8 characters
		char* makeAndModel;	// can not be a null address and can not be empty
		int parkingSpotNumber;	// can be zero or positive integer number
	protected:
		void setEmpty();	// no-argument constructor 
		void clearMemory();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		void setLicensePlate(const char* licencePlate);
		const char* getMakeModel() const;
		void setMakeModel(const char* makeAndModel);
		void convertLicencePlateUppercase();	// function to covert licenceplate to uppercase
	public:
		Vehicle();	// Constructor with no-argument
		Vehicle(const char* licensePlate, const char* makeAndModel);	// Constructor with two-arguments
		Vehicle(const Vehicle&) = delete;	// Vehicle can not get copied or assigned to another Vehicle
		virtual ~Vehicle();	// Destructor
		int getParkingSpot() const;
		void setParkingSpot(int parkingSpotNumber);
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		friend bool operator==(const Vehicle& vehicle, const char* licensePlate);
		friend bool operator==(const Vehicle&, const Vehicle&);
	};
}
#endif