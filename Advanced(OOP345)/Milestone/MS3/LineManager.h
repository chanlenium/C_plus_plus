// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#ifndef _LINEMANAGER_H
#define _LINEMANAGER_H

#include <deque>
#include <vector>
#include "Workstation.h"
#include "CustomerOrder.h"
#include "Utilities.h"


class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	// A container containing all the references of the Workstation objects on the assembly line
	std::deque<CustomerOrder> ToBeFilled;	// A queue of customer orders to be filled
	std::deque<CustomerOrder> Completed;	// A queue of customer orders completed
	unsigned int m_cntCustomerOrder;		// The number of CustomerOrder objects the assembly line started with
public:
	LineManager(const std::string filename, std::vector<Workstation*>& sta, std::vector<CustomerOrder>& order);
	// the constructor will :
	// read the records from file and setup all the m_pNextStation references in the Workstation objects, 
	// linking each Workstation object together to form the assembly line
	// Move all the CustomerOrder objects onto the back of the ToBeFilled queue
	// Copy all the Workstation objects into the AssemblyLine container
	// custom constructor
	// This string contains the filename specified by the user to be used for linking the assembly line objects (example: AssemblyLine.txt)
	// a reference to a std::vector<Workstation*> that contains the addresses of all the Workstation objects created for the assembly line
	// a reference to a std::vector<CustomerOrder> that contains all the CustomerOrder objects to be filled


	bool run(std::ostream& os);
	// If there are any CustomerOrder objects in the ToBeFilled queue, 
	// move the one at the front of the queue onto the starting point of the AssemblyLine
	// (you have to identify which station is the starting point of your assembly line).
	// Only one order can be moved on the assembly line on each call to this function.
	
	// Loop through all stations on the assembly line and run one cycle of the station's process
	// Loop through all stations on the assembly line and move the CustomerOrder objects down the line.
	// Hint : completed orders should be moved into the Completed queue.
	// return true if all customer orders have been filled, otherwise returns false.
	
	void displayCompletedOrders(std::ostream& os) const;
	// displays all the orders that were completed
	
	void displayStations() const;
	// display all stations on the assembly line in the order they were received from the client
	
	void displayStationsSorted() const;
	// display all stations on the assembly line in the order they are linked.
};

#endif

