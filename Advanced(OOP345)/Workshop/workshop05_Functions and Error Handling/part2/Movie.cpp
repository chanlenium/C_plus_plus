/********************************************************* /
* Student ID : 128975190
* Seneca email : dcoh@myseneca.ca
* Section: NFF
* *********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <string>		// std::string
#include <algorithm>	// remove_if;
#include <iostream>		// std::cout, std::endl;
#include <iomanip>      // std::setw

namespace sdds {
	std::string Movie::parseStr(std::string& recivedStr, const char delimiter) {
		size_t nextPoint;
		std::string memberVar = "";

		// remove all forward white spaces
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

	Movie::Movie(const std::string& strMovie) {
		std::string recivedStr = strMovie;
		this->titleOfMovie = parseStr(recivedStr, ',');
		this->yearOfRelease = std::stoi(parseStr(recivedStr, ','));
		this->description = parseStr(recivedStr, '\n');
	}

	Movie& Movie::operator=(const Movie& src) {
		if (this != &src) {
			this->titleOfMovie = src.title();
			this->yearOfRelease = src.yearOfRelease;
			this->description = src.description;
		}
		return *this;
	}

	void Movie::display(std::ostream& os) const {
			os.setf(std::ios::right);
			os << std::setw(40) << this->title() << " | ";
			os << std::setw(4) << this->yearOfRelease << " | ";
			os << this->description;
			os << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		movie.display(os);
		//if (movie.yearOfRelease != 0) {
		//	movie.display(os);
		//}
		return os;
	}
}


