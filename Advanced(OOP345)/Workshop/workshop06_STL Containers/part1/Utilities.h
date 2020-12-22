/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <vector>
#include <sstream>
//#include <iostream>
//#include <string>
#include "Vehicle.h"
#include "Car.h"

namespace sdds
{
	inline Vehicle* createInstance(std::istream& in) {
		std::string strLine; 
		std::getline(in, strLine);	// Read one-line
		// After reading one-line, pointer indicates next line
		if (strLine[0] == 'c' || strLine[0] == 'C') {
			//int delimiterPosi = strLine.find(',');
			//strLine = strLine.substr(delimiterPosi+1);
			std::istringstream iss(strLine);
			Vehicle* car = new Car(iss);
			return car;
		}
		else {
			return nullptr;
		}
		
		//if(in.get())
		//std::vector<Vehicle> veh;

		//for (std::string strLine; std::getline(in, strLine); ) {
		//	//std::cout << strLine << std::endl;
		//	if (strLine[0] == 'c' || strLine[0] == 'C') {
		//		std::istringstream iss(strLine);
		//		//Vehicle* car = new Car(iss);
		//		veh.push_back(Car(iss));
		//	}
		//}
	}

}
#endif