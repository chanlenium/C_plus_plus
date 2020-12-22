/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SHIP_H	// header guards
#define SDDS_SHIP_H
#include "Engine.h"

namespace sdds
{
	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;

	class Ship
	{
		Engine* m_engines;	// a dynamic allocated array of engines
		char* m_type;	// the engine model type
		int m_engCnt;
	public:
		Ship();	// set the current instance into a safe empty state
		~Ship();
		Ship(const char* type, Engine* engine, int size); // custom constructor that receives as parameters the type of the ship
		explicit operator bool() const;
		Ship& operator+=(Engine engine);	// a member operator that adds an engine to the array of engines
		bool operator<(double power) const;	// returns true if the total output power of the ship is less than the number provided as parameter
		void display() const;	// print to the screen the content of the current instance 
		double calcPower() const;	// calculate ship power
	};
	// returns true if the first parameter is smaller than the total output power of the ship received in the second parameter
	bool operator<(double power, const Ship& theShip);
}
#endif