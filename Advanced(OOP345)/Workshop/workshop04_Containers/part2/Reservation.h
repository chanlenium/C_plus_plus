/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _RESERVATION_H
#define _RESERVATION_H
#include <iostream>     // std::cout, std::endl
#include <string>

namespace sdds
{
	class Reservation
	{
		char reservationId[10] = "";		// reservation id - an array of characters
		char nameOfReservation[10] = "";	// name on the reservation
		char email[20] = "";				// email
		size_t noOfPeople = 0u;			//	number of people in the party
		size_t partyDay = 0u;			// day when the party expects to come(an integer between 1 and 31)
		size_t partyHour = 0u;			//	hour when the party expects to come(an integer between 1 and 24)
	public:
		Reservation();							// default constructor
		Reservation(const std::string& res);	// constructor with 1-argument
		void setEmpty();
		void display(std::ostream& os) const;	
		const char* getID() const;
		//insertion operator to insert the content of a reservation object into an ostream object:
		friend std::ostream& operator<<(std::ostream& os, const Reservation& r);
		void parseStr(std::string& recivedStr, char* memberVar, const char startDelimiter, const char endDelimeter);
		void parseNum(std::string& recivedStr, size_t* memberVar, const char startDelimiter, const char endDelimeter);
	};
}
#endif

