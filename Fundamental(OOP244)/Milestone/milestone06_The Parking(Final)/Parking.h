/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.cpp
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/7 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PARKING_H	// header guards
#define SDDS_PARKING_H
#include "Menu.h"
#include "Utils.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

namespace sdds
{
	const int maxNoOfParkingSpots = 100;	// Maximum Number of Parking Spots 
	
	class Parking
	{
		int noOfSpots;	// Number of Spots(always less than the Maximum Number of Parking Spots)
		int noOfParkedVehicles;	// Number of Parked Vehicles (always less than the Number of Spots)
		Vehicle* parkingSpots[maxNoOfParkingSpots];	// an array of Vehicle pointers that act like the Parking Spots in the Parking
		int availableParkingIndex;	// the lowest parking slot number vechicle can park
		char* dataFileName;
		Menu* menu;
		void setEmpty();
		Parking(const Parking&) = delete;	// copying deny
		Parking& operator=(const Parking&) = delete; // assignment overloading deny
		bool isEmpty();
		void parkingStatus();
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles();
		bool closeParking();
		bool exitParkingApp();
		void loadDataFile();
		void saveDataFile();
	public:
		Parking();
		Parking(const char* nameOfDataFile, int noOfSpots);
		virtual ~Parking();
		int run();
	};
}
#endif