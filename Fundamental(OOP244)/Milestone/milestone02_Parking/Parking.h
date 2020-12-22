/* Citation and Sources...
Final Project Milestone 1
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

#ifndef SDDS_PARKING_H	// header guards
#define SDDS_PARKING_H
#include "Menu.h"
#include "Utils.h"

namespace sdds
{
	class Parking
	{
		char* dataFileName;
		Menu* menu; 
		void setEmpty();		
		Parking(const Parking&) = delete;	// copying
		Parking& operator=(const Parking&) = delete; // assignment
		bool isEmpty();
		void parkingStatus();
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles();
		bool closeParking();
		bool exitParkingApp();
		bool loadDataFile();
		void saveDataFile();
	public:
		Parking();
		Parking(const char* nameOfDataFile);
		~Parking();
		int run();
	};
}
#endif