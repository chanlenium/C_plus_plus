/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _RESERVATION_H
#define _RESERVATION_H

namespace sdds
{
	class Reservation
	{
		char reservationId[10] = "";	// reservation id: an array of characters
		char nameOfReservation[10] = "";	// name on the reservation
		char email[20] = "";	// email that can be used to send confirmation that the reservation can be honored or cannot
		int noOfPeople = 0;	//	thenumber of people in the party
		int partyDay = 0;	// the day when the party expects to come(for simplicity, the day is an integer between 1 and 31)
		int partyHour = 0;	//	the hour when the party expects to come(for simplicity, the hour is an integer between 1 and 24)
	public:
		Reservation();
		Reservation(const std::string& res);
		void display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const Reservation& r);
	};
}
#endif

