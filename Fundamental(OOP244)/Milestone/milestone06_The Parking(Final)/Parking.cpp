/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.cpp
Version 1.1
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/7 Preliminary release(draft 1.0)
2020/7/26 Specify all menu contents
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Parking.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	void Parking::setEmpty() {
		this->noOfSpots = 0;
		this->noOfParkedVehicles = 0;
		this->availableParkingIndex = 0;
		this->dataFileName = nullptr;
		for (int i = 0; i < maxNoOfParkingSpots; i++) {
			this->parkingSpots[i] = nullptr;
		}
	}

	Parking::Parking() {
		this->setEmpty();
	}

	/* Constructor with one-arguemnt*/
	// Set the value of the Number of Spots in the Parking to this value. This is the maximum number of Vehicles the Parking can accept. 
	// if this number is invalid (less than 10 or more than the Maximum Number of Parking Spots constant value) then the Parking is set an Invalid Empty State
	Parking::Parking(const char* nameOfDataFile, int noOfSpots) {
		if (nameOfDataFile == nullptr || nameOfDataFile[0] == '\0' || noOfSpots < 10 || noOfSpots > maxNoOfParkingSpots) {
			this->setEmpty();
		}
		else {
			this->noOfSpots = noOfSpots;
			this->noOfParkedVehicles = 0;
			this->availableParkingIndex = 0;
			int len = strlen(nameOfDataFile);
			this->dataFileName = new char[len + 1];
			strncpy(this->dataFileName, nameOfDataFile, len);
			this->dataFileName[len] = '\0';
			// all the elements of Parking Spots array are initialized to nullptr
			for (int i = 0; i < maxNoOfParkingSpots; i++) {
				this->parkingSpots[i] = nullptr;
			}
		}
		this->loadDataFile();
	}

	// Load Data reads Vehicle records from the datafile and saves them in the corresponding Parking Spots indices.
	void Parking::loadDataFile() {
		if (this->isEmpty()) {
			cout << "Error in data file" << endl;
		}
		else {
			// using an instance of the ifstream class open the file named in the Filename member variable
			ifstream fin(this->dataFileName);
			if (fin.is_open()) {
				while (fin.good() && this->noOfParkedVehicles <= this->noOfSpots && !fin.eof()) {
					char c = '\0';
					fin >> c;
					fin.ignore();
					if (c == 'C' || c == 'M') {
						if (c == 'C') {
							this->parkingSpots[availableParkingIndex] = new Car;
						}
						else {
							this->parkingSpots[availableParkingIndex] = new Motorcycle;
						}	
						this->parkingSpots[availableParkingIndex]->setCsv(true);
						fin >> *(this->parkingSpots[availableParkingIndex]);
						this->parkingSpots[availableParkingIndex]->setCsv(false);
						availableParkingIndex++;
						this->noOfParkedVehicles++;
					}
				}
			}
			else {
				fin.good();
			}
		}
	}

	bool Parking::isEmpty() {
		bool returnVal = (this->dataFileName == nullptr) ? true : false;
		return returnVal;
	}

	Parking::~Parking() {
		for (int i = 0; i < maxNoOfParkingSpots; i++) {
			delete this->parkingSpots[i];
		}
		delete[] this->dataFileName;
		this->setEmpty();
	}

	int Parking::run() {
		int returnVal = 0;
		if (this->isEmpty()) {
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
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(ios::left);
		cout << this->noOfSpots - this->noOfParkedVehicles;
		cout.unsetf(ios::left);
		cout << " *****" << endl;
	}

	void Parking::parkVehicle() {
		if (this->noOfSpots > this->noOfParkedVehicles) {
			Menu subMenu1("Select type of the vehicle:", 1);
			subMenu1 << "Car" << "Motorcycle" << "Cancel";
			subMenu1.display();

			int userSelection = getPosInt(3, 1);
			if (userSelection == 1 || userSelection == 2) {
				if (userSelection == 1) {	// userSelection "Car"
					this->parkingSpots[availableParkingIndex] = new Car;	// dynamically create an instance 
				}
				else {	// userSelection "Motorcycle"
					this->parkingSpots[availableParkingIndex] = new Motorcycle;	// dynamically create an instance 
				}
				this->parkingSpots[availableParkingIndex]->setCsv(false);	// set it NOT to be in Comma Separated mode 
				cin >> *(this->parkingSpots[availableParkingIndex]);	// reads it from the console
				this->parkingSpots[availableParkingIndex]->setParkingSpot(availableParkingIndex + 1);	// set PakingSlot number
				cout << endl;
				
				cout << "Parking Ticket" << endl;
				cout << *this->parkingSpots[availableParkingIndex] << endl;	// prints the Vehicle
				availableParkingIndex++;
				this->noOfParkedVehicles++;
			}
			else {	// userSelection "Cancel"
				cout << "Parking cancelled" << endl;
			}
		}
		else {
			cout << "Parking is full" << endl;
		}
	}

	void Parking::returnVehicle() {
		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		char userInputLicensePlate[9];
		int foundParkingIndex = -1;
		bool keeping = true;
		do {
			// Receives the license plate value in a C-style character string between 1 to 8 characters
			cin.getline(userInputLicensePlate, 9);
			convertLicencePlateUppercase(userInputLicensePlate);
			if (cin.fail()) {
				cerr << "Invalid Licence Plate, try again: ";
				cin.clear();
				cin.ignore(2000, '\n');
			}
			else if(strlen(userInputLicensePlate) < 1 || strlen(userInputLicensePlate) > 8) {
				cerr << "Invalid Licence Plate, try again: ";
				cin.ignore(2000, '\n');
			}
			else {
				int i = 0;
				// Search through the parked Vehicles for a matching licence plate
				while(foundParkingIndex == -1 && i <= this->noOfSpots){
					if (this->parkingSpots[i] != nullptr) {
						if (strcmp(this->parkingSpots[i]->getLicensePlate(), userInputLicensePlate) == 0) {
							foundParkingIndex = i;
						}
						i++;
					}
				}
				cout << endl;
				if (foundParkingIndex == -1) {
					cout << "License plate " << userInputLicensePlate << " Not found" << endl;
				}
				else {
					// prints the Vehicle, then it will delete the Vehicle from the memory and set the Parking Spot element back to nullptr
					cout << "Returning: " << endl;
					this->parkingSpots[foundParkingIndex]->setCsv(false);
					cout << *this->parkingSpots[foundParkingIndex] << endl;
					delete this->parkingSpots[foundParkingIndex];
					this->parkingSpots[foundParkingIndex] = nullptr;
					if (foundParkingIndex < this->availableParkingIndex) {
						this->availableParkingIndex = foundParkingIndex;
					}
					this->noOfParkedVehicles--;
				}
				keeping = false;
			}
		} while (keeping);
	}

	// Go through all the Parking Spot elements of the Parking (obviously up to Number of Spots) and prints all 
	void Parking::listParkedVehicles() {
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < this->noOfSpots; i++) {
			if (this->parkingSpots[i]->isEmpty()) {
			}
			else {
				this->parkingSpots[i]->setCsv(false);
				cout << *(this->parkingSpots[i]);
				cout << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::closeParking() {
		bool returnVal = true;
		if (this->noOfParkedVehicles == 0) {
			cout << "Closing Parking" << endl;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			bool yN = yesNo();
			if (yN == false) {
				cout << "Aborted!" << endl;
				returnVal = false;
			}
			else {
				cout << "Closing Parking" << endl;
				for (int i = 0; i < this->noOfSpots; i++) {
					if (this->parkingSpots[i] != nullptr) {
						if (!this->parkingSpots[i]->isEmpty()) {
							cout << endl << "Towing request" << endl;	// Print a towing ticket
							cout << "*********************" << endl;
							this->parkingSpots[i]->setCsv(false);
							cout << *this->parkingSpots[i];
							delete this->parkingSpots[i];	// Delete the Vehicle and sets the Parking Spot to null until all the Vehicles are removed from the Parking.
							this->parkingSpots[i] = nullptr;
						}
					}
				}
				this->noOfParkedVehicles = 0;
				this->availableParkingIndex = 0;
				this->saveDataFile();
				returnVal = true;
			}
		}
		return returnVal;
	}

	bool Parking::exitParkingApp() {
		bool returnVal = false;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		returnVal = yesNo();
		if (returnVal == true) {
			cout << "Exiting program!" << endl;
			returnVal = true;
			this->saveDataFile();
		}
		return returnVal;
	}

	// Using an instance of ofstream class open the file named in the Filename member variable. 
	void Parking::saveDataFile() {
		if (this->noOfParkedVehicles == 0) {
			ofstream fout(this->dataFileName, std::ios::trunc);
			fout.close();
		}
		else {
			ofstream fout(this->dataFileName, std::ios::trunc);
			if (fout.is_open()) {
				for (int i = 0; i < (this->noOfSpots+1); i++) {
					if (this->parkingSpots[i] != nullptr) {
						this->parkingSpots[i]->setCsv(true);
						fout << *this->parkingSpots[i];
					}
				}
			}
			else {
				cerr << "File is not open" << endl;
			}
			fout.close();
		}
	}
}