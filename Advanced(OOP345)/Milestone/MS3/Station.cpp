// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iomanip>	// std::setfill, std::setw
#include "Station.h"
#include "Utilities.h"

size_t Station::m_widthField = 0u;
size_t Station::id_generator = 0u;

Station::Station(const std::string str) {
	std::string line = str;

	// Initialization
	Utilities util;
	size_t next_pos = 0u;
	bool more = true;

	try {
		if (more == true) {
			m_nameOfItem = util.extractToken(line, next_pos, more);				// extract "name of item"
		}

		if (more == true) {
			line = line.substr(next_pos);
			m_nextSerialNo = stoi(util.extractToken(line, next_pos, more));		// extract "serial number"
		}

		if (more == true) {
			line = line.substr(next_pos);
			m_noOfCurrentItems = stoi(util.extractToken(line, next_pos, more));	// extract "number of current item"
		}

		if (more == true) {
			int len = strlen(line.substr(next_pos).c_str());					// extract "description of station"
			m_descOfStation = new char[len + 1];
			strncpy(m_descOfStation, line.substr(next_pos).c_str(), len);
			m_descOfStation[len] = '\0';
		}
	}
	catch (const std::invalid_argument & ia) {
		std::cerr << "Invalid argument: " << ia.what() << '\n';
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}

	if (more == true) {
		m_widthField = (m_widthField > util.getFieldWidth()) ? m_widthField : util.getFieldWidth();
		m_idOfStation = ++Station::id_generator;
	}
}

const std::string& Station::getItemName() const {
	return m_nameOfItem;
}

unsigned int Station::getNextSerialNumber() {
	return m_nextSerialNo++;
}

unsigned int Station::getQuantity() const {
	return m_noOfCurrentItems;
}

void Station::updateQuantity() {
	if (m_noOfCurrentItems > 0) {
		--m_noOfCurrentItems;
	}
	else {
		m_noOfCurrentItems = 0;
	}
	//m_noOfCurrentItems = (m_noOfCurrentItems > 0) ? --m_noOfCurrentItems : 0;
}
void Station::display(std::ostream& os, bool full) const {
	os << "[" << std::setfill('0') << std::setw(3) << std::right << m_idOfStation << "]";
	os << " Item: " << std::setfill(' ') << std::setw(m_widthField) << std::left << getItemName();
	os << " [" << std::setfill('0') << std::setw(6) << std::right << m_nextSerialNo << "]";
	if (full == true) {
		os << " Quantity: " << std::setfill(' ') << std::setw(m_widthField) << std::left << getQuantity();
		os << " Description: ";
		if (m_descOfStation != nullptr)
			os << m_descOfStation << std::endl;
		else
			os << std::endl;
	}
	else {
		os << std::endl;
	}
}

Station::Station(Station&& src) {
	*this = std::move(src);
}

const unsigned int Station::getStaionId() const {
	return m_idOfStation;
}

Station&& Station::operator=(Station&& src) {
	if (this != &src) {
		m_idOfStation = src.m_idOfStation;
		m_nameOfItem = src.m_nameOfItem;
		m_descOfStation = src.m_descOfStation;
		m_nextSerialNo = src.m_nextSerialNo;
		m_noOfCurrentItems = src.m_noOfCurrentItems;

		src.m_idOfStation = 0;
		src.m_nameOfItem = "";
		src.m_descOfStation = nullptr;
		src.m_nextSerialNo = 0;
		src.m_noOfCurrentItems = 0;
	}
	return std::move(*this);
}

Station::~Station() {
	delete[] m_descOfStation;
}