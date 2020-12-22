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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Parking.h"

using namespace std;

namespace sdds
{
	void Parking::setEmpty() {
		this->dataFileName = nullptr;
	}

	Parking::Parking() {
		this->setEmpty();
	}

	Parking::Parking(const char* nameOfDataFile) {
		if (nameOfDataFile == nullptr || nameOfDataFile[0] == '\0') {
			this->setEmpty();
		}
		else {
			int len = strlen(nameOfDataFile);
			this->dataFileName = new char[len + 1];
			strncpy(this->dataFileName, nameOfDataFile, len);
			this->dataFileName[len] = '\0';
		}
		this->loadDataFile();
	}

	bool Parking::loadDataFile() {
		bool returnVal = false;
		if (this->isEmpty()) {
			cout << "Error in data file" << endl;
		}
		else {
			cout << "loading data from " << this->dataFileName << endl;
			returnVal = true;
		}
		return returnVal;
	}

	bool Parking::isEmpty() {
		bool returnVal = (this->dataFileName == nullptr)?true:false;
		return returnVal;
	}

	Parking::~Parking() {
		delete[] this->dataFileName;
		this->setEmpty();
	}

	int Parking::run() {
		int returnVal = 0;
		if(this->isEmpty()) {
			returnVal = 1;
		}
		else {
			Menu mainMenu("Parking Menu, select an action:");
			mainMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";

			returnVal = 0;
			bool loop = true;
			do {
				this->parkingStatus();
				mainMenu.display();
				int selectedMenuNo = getPosInt(5, 1);
				if (selectedMenuNo == 1) {
					this->parkVehicle();
				}
				else if (selectedMenuNo == 2) {
					this->returnVehicle();
				}
				else if (selectedMenuNo == 3) {
					this->listParkedVehicles();
				}
				else if (selectedMenuNo == 4) {
					loop = !(this->closeParking());
				}
				else if (selectedMenuNo == 5) {
					loop = !(this->exitParkingApp());
				}
			} while (loop);
		}
		return returnVal;
	}

	void Parking::parkingStatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
	}

	void Parking::parkVehicle() {
		Menu subMenu1("Select type of the vehicle:", 1);
		subMenu1 << "Car" << "Motorcycle" << "Cancel";
		subMenu1.display();

		switch (getPosInt(3, 1)) {
		case 1:
			cout << "Parking Car" << endl;
			break;
		case 2:
			cout << "Parking Motorcycle" << endl;
			break;
		case 3:
			cout << "Cancelled parking" << endl;
			break;
		default:
			break;
		}
	}

	void Parking::returnVehicle() {
		cout << "Returning Vehicle" << endl;
	}
	void Parking::listParkedVehicles() {
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::closeParking() {
		cout << "Closing Parking" << endl;
		return true;
	}

	bool Parking::exitParkingApp() {
		bool returnVal = false;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: " ;
		returnVal = yesNo();
		if (returnVal == true) {
			cout << "Exiting program!" << endl;
			returnVal = true;
			this->saveDataFile();
		}
		return returnVal;
	}

	void Parking::saveDataFile() {
		if (this->isEmpty()) {
			// Do something..
		}
		else {
			cout << "Saving data into " << this->dataFileName << endl;
		}
	}
}
