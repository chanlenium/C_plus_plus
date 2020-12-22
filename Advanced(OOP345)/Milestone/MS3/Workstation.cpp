// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <iostream>

#include "Workstation.h"

void Workstation::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		m_orders.front().fillItem(*this, os);
	}
}

bool Workstation::moveOrder() {
	if (m_orders.empty()) {
		return false;
	}
	else {
		if (m_pNextStation != nullptr && m_orders.front().isOrderFilled() == false) {
			m_pNextStation->m_orders.push_back(std::move(m_orders.front()));
			m_orders.pop_front();
			return true;
		}
		else {
			return false;
		}
	}
}

void Workstation::setNextStation(Workstation& station) {
	m_pNextStation = &station;
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	if (m_orders.empty()) {
		return false;
	}
	else {
		if (m_orders.front().isOrderFilled()) {
			order = std::move(m_orders.front());
			m_orders.pop_front();
			return true;
		}
		else {
			return false;
		}
	}
}

void Workstation::display(std::ostream& os) {
	std::cout << getItemName() << " --> "
		<< (m_pNextStation != nullptr ? m_pNextStation->getItemName() : "END OF LINE")
		<< std::endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& order) {
	m_orders.push_back(std::move(order));
	return *this;
}