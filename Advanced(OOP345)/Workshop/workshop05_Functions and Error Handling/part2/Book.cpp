/********************************************************* /
* Student ID : 128975190
* Seneca email : dcoh@myseneca.ca
* Section: NFF
* *********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <string>		// std::string
#include <algorithm>	// remove_if;
#include <iostream>		// std::cout, std::endl;
#include <iomanip>      // std::setw

namespace sdds {
	std::string Book::parseStr(std::string& recivedStr, const char delimiter) {
		size_t nextPoint;
		std::string memberVar = "";

		// Remove all forward white spaces
		bool found = false;
		int nonWhiteSpacePoint = 0;
		for (size_t i = 0; !found && i < recivedStr.length(); i++) {
			if (recivedStr[i] != ' ') {
				nonWhiteSpacePoint = i;
				found = true;
			}
		}
		recivedStr = recivedStr.substr(nonWhiteSpacePoint);
		nextPoint = recivedStr.find(delimiter) + 1;
		memberVar = recivedStr.substr(0, nextPoint - 1);
		if (delimiter != '\n') {
			recivedStr = recivedStr.substr(memberVar.length() + 1);
		}
		
		// remove all backward white spaces
		found = false;
		for (int i = memberVar.length() - 1; !found && i > 0; i--) {
			if (memberVar[i] != ' ') {
				nonWhiteSpacePoint = i;
				found = true;
			}
		}
		memberVar = memberVar.substr(0, nonWhiteSpacePoint + 1);

		return memberVar;		
	}

	Book::Book(const std::string& strBook) {
		std::string recivedStr = strBook;
		this->authorOfBook = parseStr(recivedStr, ',');
		this->titleOfBook = parseStr(recivedStr, ',');		
		this->countryOfPublication = parseStr(recivedStr, ',');		
		this->priceOftheBook = std::stod(parseStr(recivedStr, ','));		
		this->yearOfPublicaion = std::stoi(parseStr(recivedStr, ','));
		this->description = parseStr(recivedStr, '\n');
	}

	Book& Book::operator=(const Book& src) {
		if (this != &src) {
			this->authorOfBook = src.authorOfBook;
			this->titleOfBook = src.title();
			this->countryOfPublication = src.country();
			this->priceOftheBook = src.priceOftheBook;
			this->yearOfPublicaion = src.year();
			this->description = src.description;
		}
		return *this;
	}

	void Book::display(std::ostream& os) const {
		os.setf(std::ios::right);
		os << std::setw(20) << this->authorOfBook << " | ";
		os << std::setw(22) << this->title() << " | ";
		os << std::setw(5) << this->country() << " | ";
		os << std::setw(4) << this->year() << " | ";
		os.setf(std::ios::fixed);
		os << std::setw(6) << std::setprecision(2) << this->priceOftheBook << " | ";
		os << this->description;
		os << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const Book& book) {
		book.display(os);
		return os;
	}
}


