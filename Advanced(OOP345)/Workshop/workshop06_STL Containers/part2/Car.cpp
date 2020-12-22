/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iomanip>      // std::setw
#include <sstream>      // std::stringstream
#include <iostream>
#include <string>

#include "Car.h"

namespace sdds {
	Car::Car(std::istream& record) {
		std::string token;

		std::getline(record, mTag, ',');
		trim(mTag);
		
		std::getline(record, mMaker, ',');
		trim(mMaker);
		
		std::getline(record, mCondition, ',');
		trim(mCondition);
		if (mCondition != "n" && mCondition != "u" && mCondition != "b") {
			if (mCondition == "") {
				mCondition = "new"[0];
			}
			else {
				throw "Invalid record!";
			}
		}

		std::getline(record, token, ',');
		trim(token);
		try {
			mTopSpeed = stod(token);
		}
		catch (...) {
			throw "Invalid record!";
		}
	};

	void Car::trim(std::string& line) {	// Trim the line
		size_t i = 0u;
		for (i = 0u; i < line.length() && line[i] == ' '; ++i);	// forward
		line = line.substr(i);
		for (i = line.length(); i > 0u && line[i - 1] == ' '; --i);	// backward
		line = line.substr(0, i);
	}

	std::string Car::condition() const {
		std::string returnVal = "";
		if (mCondition[0] == 'n') {
			returnVal = "new";
		}else if(mCondition[0] == 'u') {
			returnVal = "used";
		}
		else if(mCondition[0] == 'b'){
			returnVal = "broken";
		}
		return returnVal;
	}

	double Car::topSpeed() const {
		return mTopSpeed;
	}

	void Car::display(std::ostream& out) const {
		out << "| ";
		out << std::setw(10) << std::right << mMaker;
		out << " | ";
		out << std::setw(6)  << std::left << this->condition();
		out << " | ";
		out << std::setw(6) << std::right << std::fixed << std::setprecision(2) << topSpeed();
		out << " |";
	}
}

