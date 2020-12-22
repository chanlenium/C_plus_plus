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
	Saiyan::Saiyan() {
		setempty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {
		set(name, dob, power);
	}

	void Saiyan::setempty() {
		m_name[0] = '\0';
		m_dob = 9999;
		m_power = -1;
		m_super = false;
	}

	void Saiyan::set(const char* name, int dob, int power, bool super) {
		if (name == nullptr) {
			name = NULL;
			setempty();
		}
		else {
			int len = strlen(name);
			strncpy(m_name, name, len);
			m_name[len] = '\0';

			m_dob = dob;
			m_power = power;
			m_super = super;
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
			cout << "DOB: " << m_dob << endl;
			cout << "Power: " << m_power << endl;
			cout << "Super: " << ((m_super == 1) ? "yes" : "no");
			cout << endl;
		}
	}

	bool Saiyan::fight(const Saiyan& other) const {
		bool returnVal = false;
		if (m_power > other.m_power) {
			returnVal = true;
		}
		return returnVal;
	}
}