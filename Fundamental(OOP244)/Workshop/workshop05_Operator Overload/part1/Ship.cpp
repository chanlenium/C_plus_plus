#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Ship.h"
using namespace std;

namespace sdds
{
	// set the current instance into a safe empty state
	Ship::Ship() {
		m_engines->m_size = 0;
		m_engines->m_type[0] = '\0';
		m_type[0] = '\0';
		m_engCnt = 0;
	}	

	// custom constructor that receives as parameters the type of the ship
	Ship::Ship(const char* type, Engine* engines, int size) {			   
		if (size < 10) {
			for (int i = 0; i < size; i++) {
				strcpy(this->m_engines[i].m_type, (engines + i)->m_type);
				this->m_engines[i].m_size = (engines + i)->m_size;
			}
			strcpy(this->m_type, type);
			this->m_engCnt = size;
		}
		else {
			*this = Ship();
		}

		if (!this) {
			*this = Ship();
		}
	}

	// returns true if the total output power of the ship is less than the number provided as parameter
	Ship::operator bool() const {
		bool valid = true;
		// check input validity
		int i = 0;
		do {
			if (this->m_engCnt <= 0 && this->m_type[0] == '\0' && 
				(this->m_engines+i)->m_size <= 0 && (this->m_engines + i)->m_type[0] == '\0') {
				valid = false;
			}
			i++;
		} while (valid == true && i < this->m_engCnt);

		return valid;
	}

	// a member operator that adds an engine to the array of engines
	Ship& Ship::operator+=(Engine engine) {
		if (this->m_engCnt >= 10) {
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			this->m_engines[m_engCnt].m_size = engine.m_size;
			strcpy(this->m_engines[m_engCnt].m_type, engine.m_type);
			m_engCnt++;
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
			cout << this->m_type << " - " << shipPower << endl;
			for (int i = 0; i < this->m_engCnt; i++) {
				cout << (this->m_engines+i)->m_size << " liters - " 
					<< (this->m_engines+i)->m_type << endl;
			}
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