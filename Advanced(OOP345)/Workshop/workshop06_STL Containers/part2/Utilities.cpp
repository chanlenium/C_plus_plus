/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <sstream>
#include "Utilities.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		std::string strLine;
		std::getline(in, strLine);	// Read one-line
		// After reading one-line, pointer indicates next line

		size_t i = 0u;
		for (i = 0u; i < strLine.length() && strLine[i] == ' '; ++i);		// forward
		strLine = strLine.substr(i);
		for (i = strLine.length(); i > 0u && strLine[i - 1] == ' '; --i);	// backward
		strLine = strLine.substr(0, i);

		if (strLine != "") {
			if (strLine[0] == 'c' || strLine[0] == 'C') {
				std::istringstream iss(strLine);
				Vehicle* car = new Car(iss);
				return car;
			}
			else if (strLine[0] == 'r' || strLine[0] == 'R') {
				std::istringstream iss(strLine);
				Vehicle* racecar = new Racecar(iss);
				return racecar;
			}
			else {
				std::string s = "";
				s += strLine[0];
				throw ("Unrecognized record type: [" + s + "]");
			}
		}
		else {
			return nullptr;
		}
	}
}
