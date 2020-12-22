/********************************************************* /
* Student ID : 128975190
* Seneca email : dcoh@myseneca.ca
* Section: NFF
* *********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Restaurant.h"
#include "Reservation.h"
#include <iomanip>      // std::setw
#include <iostream>

namespace sdds {
	Restaurant::Restaurant() {
		this->setEmpty();
	}

	void Restaurant::setEmpty() {
		this->reservation = nullptr;
		this->noOfReservations = 0;
	}

	Restaurant::~Restaurant() {
		this->clearMemory();
	}

	void Restaurant::clearMemory() {
		delete[] this->reservation;
		this->reservation = nullptr;
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		this->noOfReservations = cnt;
		reservation = new Reservation[cnt];
		for (size_t i = 0; i < this->noOfReservations; i++) {
			reservation[i] = *reservations[i];
		}
	}

	size_t Restaurant::size() const {
		return this->noOfReservations;
	}

	Restaurant::Restaurant(const Restaurant& src) {
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src) {
			this->clearMemory();
			this->reservation = new Reservation[src.noOfReservations];
			for (size_t i = 0; i < src.noOfReservations; i++) {
				this->reservation[i] = src.reservation[i];
			}
			this->noOfReservations = src.noOfReservations;
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src) {
		*this = std::move(src);
	}
	Restaurant&& Restaurant::operator=(Restaurant&& src) {
		if (this != &src)
		{
			this->reservation = src.reservation;
			this->noOfReservations = src.noOfReservations;
			src.reservation = nullptr;
			src.noOfReservations = 0;
			
		}
		return std::move(*this);
	}

	void Restaurant::display(std::ostream& os) const {
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" << std::endl;
		os << "--------------------------" << std::endl;
		if (this->noOfReservations == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < this->noOfReservations; i++) {
				this->reservation[i].display(os);
			}
		}
		os << "--------------------------" << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& r) {
		r.display(os);
		return os;
	}
}