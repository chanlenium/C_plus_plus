#define _CRT_SECURE_NO_WARNINGS
//#include <vld.h>
#include <iostream>
#include <cstring>
#include "Ship.h"
using namespace std;

namespace sdds
{
	// set the current instance into a safe empty state
	Ship::Ship() {
		this->m_engines = nullptr;
		this->m_type = nullptr;
		this->m_engCnt = 0;
	}	

	Ship::~Ship() {
		delete [] this->m_engines;
		this->m_engines = nullptr;

		delete[] this->m_type;
		this->m_type = nullptr;
	}

	// custom constructor that receives as parameters the type of the ship
	Ship::Ship(const char* type, Engine* engines, int size) {	
		this->m_engines = new Engine[size];

		if (size < 10) {
			for (int i = 0; i < size; i++) {
				strcpy(this->m_engines[i].m_type, (engines + i)->m_type);
				this->m_engines[i].m_size = (engines + i)->m_size;
			}

			int len = strlen(type);
			this->m_type = new char[len + 1];
			strncpy(this->m_type, type, len);
			this->m_type[len] = '\0';

			this->m_engCnt = size;
		}
		else {
			delete[] this->m_engines;
			*this = Ship();
		}

		if (!this) {
			delete[] this->m_engines;
			delete[] this->m_type;
			*this = Ship();
		}
	}

	// returns true if the total output power of the ship is less than the number provided as parameter
	Ship::operator bool() const {
		bool valid = true;
		// check input validity
		int i = 0;
		do {
			if (this->m_engCnt <= 0 && this->m_type == nullptr && (this->m_engines+i) == nullptr){
				valid = false;
			}
			i++;
		} while (valid == true && i < this->m_engCnt);

		return valid;
	}

	// a member operator that adds an engine to the array of engines
	Ship& Ship::operator+=(Engine engine) {
		if (this->m_engCnt >= 10 || engine.m_size == 0 || engine.m_type[0] == '\0') {
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			Engine* tempEngines;
			int resize = this->m_engCnt + 1;
			tempEngines = new Engine[resize];
			for (int i = 0; i < resize - 1; i++) {
				strcpy(tempEngines[i].m_type, this->m_engines[i].m_type);
				tempEngines[i].m_size = this->m_engines[i].m_size;
			}
			strcpy(tempEngines[resize - 1].m_type, engine.m_type);
			tempEngines[resize - 1].m_size = engine.m_size;

			delete[] this->m_engines;
			this->m_engines = nullptr;

			this->m_engines = new Engine[resize];
			for (int i = 0; i < resize; i++) {
				strcpy(this->m_engines[i].m_type, tempEngines[i].m_type);
				this->m_engines[i].m_size = tempEngines[i].m_size;
			}
			delete[] tempEngines;
			tempEngines = nullptr;
			
			this->m_engCnt++;
		}
		return *this;
	}

	// returns true if the total output power of the ship is less than the number provided as parameter
	bool Ship::operator<(double power) const {
		bool returnVal = false;
		double shipPower = calcPower();
		
		if (shipPower < power) {
			returnVal = true;
		}
		return returnVal;
	}

	// returns true if the first parameter is smaller than the total output power of the ship received in the second parameter
	bool operator<(double power, const Ship& theShip) {
		bool returnVal = !(theShip < sdds::MAX_STD_POWER);
		return returnVal;
	}

	// print to the screen the content of the current instance
	void Ship::display() const {
		if (this->m_engCnt == 0) {
			cout << "No available data" << endl;
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			double shipPower = calcPower();
			
			cout << this->m_type << " - ";
			
			cout.setf(ios::fixed);
			cout.width(6);
			cout.precision(2);
			cout << shipPower << endl;
			
			for (int i = 0; i < this->m_engCnt; i++) {
				cout.precision(2);
				cout << (this->m_engines+i)->m_size << " liters - " 
					<< (this->m_engines+i)->m_type << endl;
			}

			cout.precision(3);
		}
	}

	// calculate ship power
	double Ship::calcPower() const{
		double shipPower = 0;
		for (int i = 0; i < this->m_engCnt; i++) {
			shipPower += ((this->m_engines + i)->m_size * 5);
		}
		return shipPower;
	}
}