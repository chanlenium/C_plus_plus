// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#ifndef _WORKSTATION_H
#define _WORKSTATION_H

#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

class Workstation : public Station
{
	std::deque<CustomerOrder> m_orders;			// double ended queue with new CustomerOrders
	Workstation* m_pNextStation = nullptr;			// a pointer to the next station on the assembly line
public:
	Workstation(const std::string str) : Station(str) {
		m_pNextStation = nullptr;
	};							// custom constructor
	// This string contains a single record (one line) that has been retrieved from the input file specified by the user
	// to be used for Station instantiation.
	// this constructor will also set the m_pNextStation to a safe state.
	Workstation(Workstation& src) = delete;							// copy constructor
	Workstation& operator=(const Workstation& src) = delete;		// copy assignment operator.
	Workstation(Workstation&& src) = delete;						// move constructor
	Workstation&& operator=(Workstation&& src) = delete;			// move assignment operator

	void runProcess(std::ostream& os);
	// runs a single cycle of the assembly line for the current station
	// If there are "CustomerOrders" in the queue, this function fills the order in the front at the current Workstation

	bool moveOrder();
	// if the order at the front of the queue doesn't require service at the current station, 
	// move it to the next station on the assembly line and return true
	// Otherwise, do nothing and return false. If the queue is empty, return false.

	void setNextStation(Workstation& station);
	// stores the provided Station object's reference into the m_pNextStation pointer.

	const Workstation* getNextStation() const;
	// return the next station on the assembly line

	bool getIfCompleted(CustomerOrder& order);
	// if the order at the front of the queue is completed, this function removes from the queue, 
	// places it in the parameter and returns true; 
	// otherwise returns false. 
	// If the CustomerOrder queue is empty, returns false.

	void display(std::ostream& os);
	// writes the name of the Item 
	// this Workstation is responsible for into the parameter : ITEM_NAME-- > NEXT_ITEM_NAME
	// if m_pNextWorkstation does not exist it writes : ITEM_NAME-- > END OF LINE.
	// the messages are terminated with an endline

	Workstation& operator+=(CustomerOrder&& order);
	//moves the parameter onto the back of the CustomerOrder queue
};
#endif

