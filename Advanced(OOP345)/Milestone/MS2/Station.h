// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#include <iomanip>	// std::setfill, std::setw

#ifndef _STATION_H
#define _STATION_H

class Station
{
	int m_idOfStation = 0;				// the id of a station (integer)
	std::string m_nameOfItem = "";
	//char* m_nameOfItem = nullptr;		// the name of the item handled that the station (array of characters)
	char* m_descOfStation = nullptr;	// the description of the station (array of characters)
	unsigned int m_nextSerialNo = 0;	// the next serial number to be assigned to an item at this station (integer)
	int m_noOfCurrentItems = 0;			// the number of current items left in stock (integer)
	static size_t m_widthField;			// the maximum characters required to print to screen 
	static size_t id_generator;			// a variable used to generate IDs for new instances of type Station
public:
	Station(const std::string str);
	// custom constructor
	// This string contains a single record (one line) that has been retrieved from the input file specified by the user.
	// uses an Utilities object(created local in the function) to extract each token from the record
	// and populates the Station object accordingly.
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;	// returns the remaining quantity of the current Station object
	void updateQuantity();				// subtracts 1 from the available quantity; should not go below 0.
	void display(std::ostream& os, bool full) const;
	// inserts the content of the current object into first parameter.
	// if the second parameter is false, this function inserts only the ID, nameand serial number in the format : [ID] Item : NAME[SERIAL]
	// if the second parameter if true, this function uses the following format : [ID] Item NAME[SERIAL] Quantity : QTY Description : DESCRIPTION
	// ID field will use 3 characters, the NAMEand QTY fields will use m_widthField characters, serial number field will use 6 characters; the DESCRIPTION has no formatting options
	// this function will terminate the printed message with an endline
	Station(Station&& src);
	Station&& operator=(Station&& src);
	~Station();
};

#endif