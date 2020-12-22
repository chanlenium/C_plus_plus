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
//#include <vld.h>
#include "Saiyan.h"
using namespace std;

namespace sdds
{
	void Saiyan::clearmemory() {
		delete[] m_name;
		m_name = nullptr;
	}

	Saiyan::Saiyan() {
		setempty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {
		set(name, dob, power);
	}

	Saiyan::~Saiyan() {
		delete[] this->m_name;
		this->m_name = nullptr;
	}

	void Saiyan::setempty() {
		m_name = nullptr;
		m_dob = 9999;
		m_power = -1;
		m_super = false;
		m_level = -1;
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {
		if (name == nullptr) {
			name = NULL;
			setempty();
		}
		else {
			if (name[0] == '\0' || dob > 2020 || power < 0) {
				setempty();
			}
			else {
				clearmemory();
				int len = strlen(name);
				m_name = nullptr;
				m_name = new char[len + 1];

				strncpy(m_name, name, len);
				m_name[len] = '\0';

				m_dob = dob;
				m_power = power;
				m_level = level;
				m_super = super;
			}
		}
	}
	
	bool Saiyan::isValid() const {
		bool returnVal = true;
		if (m_name == nullptr || m_name[0] == '\0' || m_dob > 2020 || m_power < 0) {
			returnVal = false;
		}
		return returnVal;
	}

	void Saiyan::display() const {
		if (!isValid()) {
			cout << "Invalid Saiyan!" << endl;
		}
		else {
			cout << m_name << endl;
			cout.width(10);
			cout << "DOB: " << m_dob << endl;
			cout.width(10);
			cout << "Power: " << m_power << endl;
			cout.width(10);
			cout << "Super: " << ((m_super == 1) ? "yes" : "no");
			cout << endl;
			if (m_level > 0) {
				cout.width(10);
				cout << "Level: " << m_level << endl;
			}
		}
	}

	bool Saiyan::fight(Saiyan& other) {
		bool returnVal = false;
		if (m_level > 0) {
			m_power = m_power * (1 + 0.1 * m_level);
		}
		
		if (other.m_level > 0) {
			other.m_power = other.m_power * (1 + 0.1 * other.m_level);
		}

		if (m_power > other.m_power) {
			returnVal = true;
		}
		return returnVal;
	}
}