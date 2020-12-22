// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>	// std::setfill, std::setw

#include "CustomerOrder.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField = 0u;

CustomerOrder::CustomerOrder() {
}		

CustomerOrder::CustomerOrder(const std::string str) {
	std::string line = str;

	// Initialization
	Utilities util;
	size_t next_pos = 0u;
	bool more = true;
	size_t noOfDelimeterInLine = 0u;

	try {
		if (more == true) {
			m_name = util.extractToken(line, next_pos, more);				// extract "m_name"
			line = line.substr(next_pos);
		}

		if (more == true) {
			m_product = util.extractToken(line, next_pos, more);			// extract "Order Name"
			line = line.substr(next_pos);
		}

		// Count number of Items in an Order
		noOfDelimeterInLine = 0u;
		if (more == true) {
			for (size_t i = 0u; i < line.length(); i++) {
				if (line[i] == util.getDelimiter()) {
					noOfDelimeterInLine++;
				}
			}
		}

		m_lstItem = new Item * [noOfDelimeterInLine + 1];
		std::string token = "";
		for (size_t i = 0; i < (noOfDelimeterInLine+1); i++) {
			if (i != noOfDelimeterInLine) {
				token = util.extractToken(line, next_pos, more);				// extract "number of current item"
				m_lstItem[m_cntItem++] = new Item(token);
				line = line.substr(next_pos);
			}
			else {
				token = line;
				m_lstItem[m_cntItem++] = new Item(token);
			}
		}
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}

	if (more == true) {
		m_widthField = (m_widthField > util.getFieldWidth()) ? m_widthField : util.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	*this = std::move(src);
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
	if (this->m_lstItem != nullptr) {
		for (size_t i = 0; i < this->m_cntItem; i++) {
			delete this->m_lstItem[i];
		}
		delete[] this->m_lstItem;
		this->m_lstItem = nullptr;
	}

	if (this != &src) {
		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;

		src.m_name = "";
		src.m_product = "";
		src.m_cntItem = 0;
		src.m_lstItem = nullptr;
	}
	return std::move(*this);
}

CustomerOrder::CustomerOrder(CustomerOrder& src) {
	throw "error";
}


CustomerOrder::~CustomerOrder() {
	for (size_t i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}
	delete[] m_lstItem;
}

bool CustomerOrder::isOrderFilled() const {
	bool returnVal = true;
	for (size_t i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled == false) {
			returnVal = false;
			break;
		}
	}
	return returnVal;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	bool found = false;
	for (size_t i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == true) {
			found = true;
			break;
		}
	}
	return found;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	//bool found = false;
	size_t index;
	for (index = 0u; index < m_cntItem; index++) {
		if (m_lstItem[index]->m_itemName == station.getItemName()) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[index]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[index]->m_isFilled = true;
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[index]->m_itemName << "]" << std::endl;
			}
			else {
				os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[index]->m_itemName << "]" << std::endl;
			}
			//found = true;
			//break;
		}
	}

	//if (found) {
	//	if (station.getQuantity() > 0) {
	//		station.updateQuantity();
	//		m_lstItem[index]->m_serialNumber = station.getNextSerialNumber();
	//		m_lstItem[index]->m_isFilled = true;
	//		os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[index]->m_itemName << "]" << std::endl;
	//	}
	//	else {
	//		os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[index]->m_itemName << "]" << std::endl;
	//	}
	//}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0u; i < m_cntItem; i++) {
		os << "[" << std::setfill('0') << std::setw(6) << std::right << m_lstItem[i]->m_serialNumber << "] ";
		os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName;
		os << " - ";
		if (isItemFilled(m_lstItem[i]->m_itemName))
			os << "FILLED" << std::endl;
		else
			os << "MISSING" << std::endl;
	}
}

