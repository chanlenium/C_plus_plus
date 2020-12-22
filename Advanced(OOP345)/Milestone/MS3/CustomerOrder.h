// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _CUSTOMERORDER_H
#define _CUSTOMERORDER_H

#include <string>
#include "Station.h"

struct Item
{
	std::string m_itemName = "";
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;
	Item(const std::string& src) : m_itemName(src) {};	// 1-argument constructor
};

class CustomerOrder
{
	std::string m_name = "";			// the name of the customer(e.g., John, Sara, etc)
	std::string m_product = "";			// the name of the product being assembled(e.g., Desktop, Laptop, etc)
	unsigned int m_cntItem = 0u;		// a count of the number of items for the customer's order
	Item** m_lstItem = nullptr;			// a dynamically allocated array of pointers.
										// Each element of the array is a dynamically allocated object of type Item(see below).
										// This is the resource that your class must manage.
	static size_t m_widthField;			//the maximum width of a field, used for display purposes
public:
	CustomerOrder();												// default constructor		
	CustomerOrder(const std::string str);							// custom constructor
	// This constructor uses an "Utilities" object to extract the tokens and populate the current instance.
	// After the extraction is finished, will update "CustomerOrder::m_widthField"
	// if the value stored there is smaller than the value stored in "Utilities::m_widthField".
	CustomerOrder(CustomerOrder& co);							// copy constructor
	CustomerOrder& operator=(const CustomerOrder& src) = delete;	// copy assignment operator.
	CustomerOrder(CustomerOrder&& src) noexcept;					// move constructor
	// This constructor should "promise" that it doesn't throw exceptions. 
	// Use the "noexcept" keyword in the prototype.
	CustomerOrder&& operator=(CustomerOrder&& src) noexcept;		// move assignment operator.
	// This operator should "promise" that it doesn't throw exceptions. 
	// Use the "noexcept" keyword in the prototype.
	~CustomerOrder();
	bool isOrderFilled() const;						
	// returns "true" if all the items in the order have been filled; "false" otherwise
	bool isItemFilled(const std::string& itemName) const;	
	// returns the "ItemInfo::m_fillState" of the item specified as a parameter. 
	// If the item doesn't exist in the order, return "true".
	void fillItem(Station& station, std::ostream& os);
	// fills the item in the current order that corresponds to the "station" passed into the function.
	void display(std::ostream& os) const;							
	// displays the state of the current object in the format
};

#endif

