/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Engine.h"
using namespace std;

namespace sdds
{
	Engine::Engine() {
		this->m_size = 0;
		this->m_type[0] = '\0';
	}

	// custom constructor that receives as parameters the engine type and the size
	Engine::Engine(const char* type, double size) {
		this->m_size = size;
		strcpy(this->m_type, type);
	}

	// query that returns the size of the engine
	double Engine::get() const {
		return this->m_size;
	}

	// a query that prints to the screen the content of an object
	void Engine::display() const {
		cout << this->m_size << " liters - " << this->m_type;
	}
}