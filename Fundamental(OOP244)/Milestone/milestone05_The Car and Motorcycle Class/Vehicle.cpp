/* Citation and Sources...
Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.cpp
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
#include <cstring>
#include <string>
#include "Vehicle.h"


namespace sdds
{
	// no-argument constructor that sets the Vehicle to a safe Invalid empty state
	Vehicle::Vehicle() {
		this->setEmpty();
	}

	// constructor created using a license plate and a make and model value
	Vehicle::Vehicle(const char* licensePlate, const char* makeAndModel) {
		if (licensePlate == nullptr || licensePlate[0] == '\0' || makeAndModel == nullptr || makeAndModel[0] == '\0') {
			this->setEmpty();
		}
		else {
			if (strlen(makeAndModel) < 2 || strlen(licensePlate) > 8 || makeAndModel[0] == '\0') {
				this->setEmpty();
			}
			else {
				this->setLicensePlate(licensePlate);
				this->convertLicencePlateUppercase();
				int len = strlen(makeAndModel);
				this->makeAndModel = new char[len + 1];
				strncpy(this->makeAndModel, makeAndModel, len);
				this->makeAndModel[len] = '\0';
				this->parkingSpotNumber = 0;
			}
		}
	}

	// Clear dynamic memory
	void Vehicle::clearMemory() {
		delete[] this->makeAndModel;
		this->makeAndModel = nullptr;
	}

	// guarantees no memory is leaked when the object goes out of scope.
	Vehicle::~Vehicle() {
		this->clearMemory();
	}

	// covert LicencePlate to uppercase
	void Vehicle::convertLicencePlateUppercase() {
		int len = strlen(this->licensePlate);
		for (int i = 0; i < len; i++) {
			if (this->licensePlate[i] >= 97 && this->licensePlate[i] <= 122) {
				this->licensePlate[i] -= 32;
			}
		}
	}

	// sets the Vehicle to a safe Invalid empty state
	void Vehicle::setEmpty() {
		this->licensePlate[0] = '\0';
		this->makeAndModel = nullptr;
		this->parkingSpotNumber = 0;
	}

	// returns true if the Vehicle is in an invalid empty state, or else, it returns false.
	bool Vehicle::isEmpty() const {
		bool returnVal = false;
		if (this->licensePlate[0] == '\0' && this->makeAndModel == nullptr && this->parkingSpotNumber == 0) {
			returnVal = true;
		}
		return returnVal;
	}

	// returns a read only address of the license plate of the Vehicle
	const char* Vehicle::getLicensePlate() const {
		return this->licensePlate;
	}

	// resets the license plate of the Vehicle to a new value
	void Vehicle::setLicensePlate(const char* licencePlate) {
		strcpy(this->licensePlate, licencePlate);
		this->convertLicencePlateUppercase();
	}

	// returns a read only address of the make and model of the Vehicle
	const char* Vehicle::getMakeModel() const {
		return this->makeAndModel;
	}

	// resets the make and model of the Vehicle to a new value
	void Vehicle::setMakeModel(const char* makeAndModel) {
		if (this->getMakeModel() != nullptr) {
			this->clearMemory();
		}
		if (makeAndModel[0] != '\0' && strlen(makeAndModel) >= 2) {
			int len = strlen(makeAndModel);
			this->makeAndModel = new char[len + 1];
			strncpy(this->makeAndModel, makeAndModel, len);
			this->makeAndModel[len] = '\0';
		}
		else {	// If the new value is null or empty, the object is set to an invalid empty state.
			this->setEmpty();
		}
	}

	// returns the parking spot number of the Vehicle
	int Vehicle::getParkingSpot() const {
		return this->parkingSpotNumber;
	}

	// Resets the parking spot number to a new value
	void Vehicle::setParkingSpot(int parkingSpotNumber) {
		if (parkingSpotNumber >= 0) {
			this->parkingSpotNumber = parkingSpotNumber;
		}
		else {	// If the value is invalid, it will set the vehicle to an Invalid empty state.
			this->clearMemory();
			this->setEmpty();
		}
	}

	// Compares the license plate of the Vehicle with a license plate value
	bool operator==(const Vehicle& vehicle, const char* licensePlate) {
		char tempLicensePlate[9];
		int len = strlen(licensePlate);
		for (int i = 0; i < len; i++) {
			if (licensePlate[i] >= 97 && licensePlate[i] <= 122) {
				tempLicensePlate[i] = licensePlate[i] - 32;
			}
			else {
				tempLicensePlate[i] = licensePlate[i];
			}
		}
		bool returnVal = (strncmp(vehicle.getLicensePlate(), tempLicensePlate, len) == 0) ? true : false;
		return returnVal;
	}

	// Compares two Vehicles and if they have the same license plate
	bool operator==(const Vehicle& lhsVehicle, const Vehicle& rhsVehicle) {
		bool returnVal = (lhsVehicle == rhsVehicle.getLicensePlate());
		return returnVal;
	}

	// overrides the Read of the ReadWritable class
	std::istream& Vehicle::read(std::istream& istr) {
		if (isCsv()) {	// Comma Separated mode //
			istr >> this->parkingSpotNumber;
			if (istr.fail()) {	// check if the istream object failed while reading
				// If this was true it will set the Vehicle object to an invalid empty state.
				istr.clear();
				istr.ignore(2000, '\n');
				this->clearMemory();
				this->setEmpty();
			}
			else {
				istr.ignore();
				string csvStr = "";
				std::getline(istr, csvStr, ',');
				if (istr.fail()) {	// check if the istream object failed while reading
					istr.clear();
					istr.ignore(2000, '\n');
					this->clearMemory();
					this->setEmpty();
				}
				else {
					if (csvStr.length() <= 8) {
						this->setLicensePlate(csvStr.c_str());
						this->convertLicencePlateUppercase();

						csvStr = "";
						std::getline(istr, csvStr, ',');
						if (istr.fail()) {	// check if the istream object failed while reading
							istr.clear();
							istr.ignore(2000, '\n');
							this->clearMemory();
							this->setEmpty();
						}
						else {
							if (csvStr.length() >= 2 && csvStr.length() <= 60) {
								this->setMakeModel(csvStr.c_str());
							}
							else {
								std::cout << "Invalid input";
								this->setEmpty();
								istr.clear();
								istr.ignore(2000, '\n');
							}
						}
					}
					else {
						std::cout << "Invalid input";
						this->setEmpty();
						istr.clear();
						istr.ignore(2000, '\n');
					}
				}
			}
		}
		else {	// Vehicle is not set to Comma Separated mode //
			int keepreading = 1;
			std::cout << "Enter Licence Plate Number: ";
			keepreading = 1;
			string str = "";
			do {
				std::getline(istr, str);
				if (istr.fail()) {	// check if the istream object failed while reading
					istr.clear();
					istr.ignore(2000, '\n');
					this->clearMemory();
					this->setEmpty();
				}
				else {
					if (str.length() <= 8) {
						this->setLicensePlate(str.c_str());
						this->convertLicencePlateUppercase();
						keepreading = 0;
					}
					else {
						cerr << "Invalid Licence Plate, try again: ";
					}
				}
			} while (keepreading == 1);

			std::cout << "Enter Make and Model: ";
			str = "";
			keepreading = 1;
			do {
				std::getline(istr, str);
				if (istr.fail()) {	// check if the istream object failed while reading
					istr.clear();
					istr.ignore(2000, '\n');
					this->clearMemory();
					this->setEmpty();
				}
				else {
					if (str.length() >= 2 && str.length() <= 60) {
						this->setMakeModel(str.c_str());
						this->parkingSpotNumber = 0;
						keepreading = 0;
					}
					else {
						std::cout << "Invalid Make and model, try again: ";
					}
				}
			} while (keepreading == 1);
		}
		return istr;
	}

	std::ostream& Vehicle::write(std::ostream& ostr) const {
		if (this->isEmpty()) {
			ostr << "Invalid Vehicle Object" << endl;
		}
		else {
			if (isCsv()) {	// comma separated mode// 
				ostr << this->getParkingSpot() << "," << this->getLicensePlate() << "," << this->getMakeModel() << ",";
			}
			else {	// comma separated mode //
				ostr << "Parking Spot Number: ";
				if (this->parkingSpotNumber == 0) {
					ostr << "N/A" << endl;
				}
				else {
					ostr << this->getParkingSpot() << endl;
				}
				ostr << "Licence Plate: ";
				ostr << this->getLicensePlate() << endl;
				ostr << "Make and Model: ";
				ostr << this->getMakeModel() << endl;
			}
		}
		return ostr;
	}
}