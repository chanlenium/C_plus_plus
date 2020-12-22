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
		this->noOfPeople = 0;
		this->partyDay = 0;
		this->partyHour = 0;
	}

	Reservation::Reservation(const std::string& res) {
		std::string recivedStr = res;

		// Remove all white space
		recivedStr.erase(remove_if(recivedStr.begin(), recivedStr.end(), isspace), recivedStr.end());

		size_t startingPoint = 0;	// Find start point for Id
		recivedStr = recivedStr.substr(startingPoint);
		size_t nextPoint = recivedStr.find(":") + 1;
		size_t len = recivedStr.substr(0, nextPoint - 1).length();
		strncpy(this->reservationId, recivedStr.c_str(), len);
		this->reservationId[len] = '\0';

		startingPoint = recivedStr.find(":") + 1;	// Find start point for name
		recivedStr = recivedStr.substr(startingPoint);
		nextPoint = recivedStr.find(",") + 1;	// Find point for next field(email)
		len = recivedStr.substr(0, nextPoint - 1).length();
		strncpy(this->nameOfReservation, recivedStr.c_str(), len);
		this->nameOfReservation[len] = '\0';

		startingPoint = recivedStr.find(",") + 1;	// Find start point for email
		recivedStr = recivedStr.substr(startingPoint);
		nextPoint = recivedStr.find(",") + 1;	// Find point for next field(email)
		len = recivedStr.substr(0, nextPoint - 1).length();
		strncpy(this->email, recivedStr.c_str(), len);
		this->email[len] = '\0';

		startingPoint = recivedStr.find(",") + 1;	// Find start point for number of people
		recivedStr = recivedStr.substr(startingPoint);
		nextPoint = recivedStr.find(",") + 1;	// Find point for next field(email)		
		this->noOfPeople = std::stoi(recivedStr.substr(0, len));

		startingPoint = recivedStr.find(",") + 1;	// Find start point for number of people
		recivedStr = recivedStr.substr(startingPoint);
		nextPoint = recivedStr.find(",") + 1;	// Find point for next field(email)		
		len = recivedStr.substr(0, nextPoint - 1).length();
		this->partyDay = std::stoi(recivedStr.substr(0, len));

		startingPoint = recivedStr.find(",") + 1;	// Find start point for number of people
		recivedStr = recivedStr.substr(startingPoint);
		nextPoint = recivedStr.find(",") + 1;	// Find point for next field(email)		
		len = recivedStr.substr(0, nextPoint - 1).length();
		this->partyHour = std::stoi(recivedStr.substr(0, len));
	};

	void Reservation::display(std::ostream& os) const {
		os << "Reservation " << this->reservationId << ":";
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
			os << "Drink ";
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
