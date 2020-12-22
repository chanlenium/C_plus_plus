/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <cstring>
#include "ConfirmationSender.h"
#include "Reservation.h"

namespace sdds{
	ConfirmationSender::ConfirmationSender() {
		this->confirmRes = new const Reservation* [MAX_SIZE];
		this->noOfReservation = 0u;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] this->confirmRes;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool found = false;
		for (size_t i = 0; i < this->noOfReservation && !found; i++) {
			if (strcmp(confirmRes[i]->getID(), res.getID()) == 0) {
				found = true;
			}
		}
		if (!found) {
			this->confirmRes[this->noOfReservation] = &res;
			this->noOfReservation++;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool found = false;
		size_t i;
		for (i = 0; i < this->noOfReservation && !found; i++) {
			if (strcmp(this->confirmRes[i]->getID(), res.getID()) == 0) {
				found = true;
			}
		}

		if (found) {
			for (; i < this->noOfReservation; i++) {
				this->confirmRes[i - 1] = this->confirmRes[i];
			}
			if (this->noOfReservation) {
				this->confirmRes[noOfReservation - 1] = nullptr;
				this->noOfReservation--;
			}
		}
		return *this;
	}


	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src) {
			this->noOfReservation = src.noOfReservation;
			this->confirmRes = new const Reservation * [MAX_SIZE];
			for (size_t i = 0; i < src.noOfReservation; i++) {
				this->confirmRes[i] = src.confirmRes[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) {
		*this = std::move(src);
	}
	ConfirmationSender&& ConfirmationSender::operator=(ConfirmationSender&& src) {
		if (this != &src) {
			//delete[] this->confirmRes;
			this->confirmRes = src.confirmRes;
			this->noOfReservation = src.noOfReservation;
			src.confirmRes = nullptr;
			src.noOfReservation = 0;
		}
		return std::move(*this);
	}


	void ConfirmationSender::display(std::ostream& os) const {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if(this->noOfReservation == 0){
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < noOfReservation; i++) {
				this->confirmRes[i]->display(os);
			}
		}
		os << "--------------------------" << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& c) {
		c.display(os);
		return os;
	}
}