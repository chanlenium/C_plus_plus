/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOTORVEHICLE_H	// header guards
#define SDDS_MOTORVEHICLE_H
#include <iostream>

namespace sdds
{
	class MotorVehicle
	{
		char licensePlateNo[32];	// characters of size 32
		char address[64];
		int year;
	public:
		MotorVehicle();
		MotorVehicle(const char* licensePlateNo, int year, const char* address = nullptr);
		void moveTo(const char* address);
		std::istream& read(std::istream&);
		std::ostream& write(std::ostream& os) const;
		void setAddr(const char* address);
		~MotorVehicle();
	};
	std::istream& operator>>(std::istream& is, MotorVehicle& motorVehicle);
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& motorVehicle);
}
#endif