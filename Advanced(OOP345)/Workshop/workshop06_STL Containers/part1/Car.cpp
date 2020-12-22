/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iomanip>      // std::setw
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& record) {
		std::string line;
		std::getline(record, line);

		trim(line);
		int delimiterPosi = line.find(',');
		trim(mTag = line.substr(0, delimiterPosi));
		line = line.substr(delimiterPosi + 1);

		trim(line);
		delimiterPosi = line.find(',');
		trim(mMaker = line.substr(0, delimiterPosi));
		line = line.substr(delimiterPosi + 1);

		trim(line);
		delimiterPosi = line.find(',');
		trim(mCondition = line.substr(0, delimiterPosi));
		line = line.substr(delimiterPosi + 1);

		trim(line);
		mTopSpeed = std::stoi(line.substr(0));
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
		out.setf(std::ios::right);
		out << std::setw(10) << mMaker;
		out << " | ";
		out.setf(std::ios::left);
		out << std::setw(6) << this->condition();
		out << " | ";
		out.setf(std::ios::right);
		out << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed();
		out << " |" << std::endl;
	}
}

