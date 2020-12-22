/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _RESTAURANT_H
#define _RESTAURANT_H
#include "Reservation.h"

namespace sdds
{
	// class Reservation;

	class Restaurant
	{
		Reservation* reservation = nullptr;	// dynamically allocated array of objects of type Reservation
		size_t noOfReservations = 0u;	// number of reservations in a restaurant
	public:
		Restaurant();	// default constructor
		~Restaurant();	// destructor
		Restaurant(Reservation* reservations[], size_t cnt);	// constructor with 1-argument
		// constructor that receives as a parameter an array of pointers to objects of type Reservation 
		// (i.e., each element of the array is a pointer)
		void setEmpty();
		void clearMemory();
		size_t size() const;	// return how many reservations are in the system
		
		Restaurant(const Restaurant& src);	// copy assignmnet
		Restaurant& operator=(const Restaurant& src);

		Restaurant(Restaurant&& src);	// move assignment
		Restaurant&& operator=(Restaurant&& src);

		void display(std::ostream& os) const;

		// insertion operator to insert the content of a Restaurant object into an ostream object:
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& r);
	};
}
#endif

