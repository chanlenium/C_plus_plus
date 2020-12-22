/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Reservation.h"
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <string>		// std::stoi
#include <algorithm>	// remove_if;;
#include <cstring>

namespace sdds {
	Reservation::Reservation() {
		this->setEmpty();
	}

	void Reservation::setEmpty() {
		this->reservationId[0] = '\0';
		this->nameOfReservation[0] = '\0';
		this->email[0] = '\0';
		this->noOfPeople = 0;
		this->partyDay = 0;
		this->partyHour = 0;
	}

	const char* Reservation::getID() const {
		return reservationId;
	}

	void Reservation::parseStr(std::string& recivedStr, char* memberVar, const char startDelimiter, const char endDelimeter) {
		size_t startingPoint, nextPoint, len;
		if (startDelimiter == 0) {
			startingPoint = 0;	// Find start point for Id
		}
		else {
			startingPoint = recivedStr.find(startDelimiter) + 1;
		}
		recivedStr = recivedStr.substr(startingPoint);
		nextPoint = recivedStr.find(endDelimeter) + 1;
		len = recivedStr.substr(0, nextPoint - 1).length();

		strncpy(memberVar, recivedStr.c_str(), len);
		memberVar[len] = '\0';
	}

	void Reservation::parseNum(std::string& recivedStr, size_t* memberVar, const char startDelimiter, const char endDelimeter) {
		size_t startingPoint, nextPoint, len;
		if (startDelimiter == 0) {
			startingPoint = 0;	// Find start point for Id
		}
		else {
			startingPoint = recivedStr.find(startDelimiter) + 1;
		}
		recivedStr = recivedStr.substr(startingPoint);
		nextPoint = recivedStr.find(endDelimeter) + 1;
		len = recivedStr.substr(0, nextPoint - 1).length();

		*memberVar = std::stoi(recivedStr.substr(0, len));
	}
	

	Reservation::Reservation(const std::string& res) {
		std::string recivedStr = res;

		// Remove all white space
		recivedStr.erase(remove_if(recivedStr.begin(), recivedStr.end(), isspace), recivedStr.end());

		parseStr(recivedStr, this->reservationId, 0, ':');
		parseStr(recivedStr, this->nameOfReservation, ':', ',');
		parseStr(recivedStr, this->email, ',', ',');
		parseNum(recivedStr, &this->noOfPeople, ',', ',');
		parseNum(recivedStr, &this->partyDay, ',', ',');
		parseNum(recivedStr, &this->partyHour, ',', ',');
	};

	void Reservation::display(std::ostream& os) const {
		os << "Reservation " << this->reservationId << ": ";
		os.setf(std::ios::right);
		os << std::setw(10) << this->nameOfReservation;
		os.unsetf(std::ios::right);
		os << "  ";
		os.setf(std::ios::left);
		os << std::setw(20) << "<" + std::string(this->email) + ">";
		os << "    ";

		if ((this->partyHour >= 6) && (this->partyHour <= 9))
		{
			os << "Breakfast ";
		}
		else if ((this->partyHour >= 11) && (this->partyHour <= 15)) {
			os << "Lunch ";
		}
		else if ((this->partyHour >= 17) && (this->partyHour <= 21)) {
			os << "Dinner ";
		}
		else {
			os << "Drinks ";
		}

		os << "on day " << this->partyDay;
		os << " @ " << this->partyHour << ":00 ";
		os << "for " << this->noOfPeople << " people." << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& r) {
		r.display(os);
		return os;
	};
}
