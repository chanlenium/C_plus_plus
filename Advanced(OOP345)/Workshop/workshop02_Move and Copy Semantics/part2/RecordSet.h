/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

// manages a dynamically allocated array of elements of type std::string
#ifndef _RECORDSET_H	// header guards
#define _RECORDSET_H
#include <iostream> 

namespace sdds
{
	class RecordSet
	{
		size_t noOfRecords = 0u;
        std::string* record = nullptr;
	public:
		RecordSet();
        ~RecordSet();
        void setEmpty();
        void clearMemory();
		RecordSet(char* nameOfFile);
        RecordSet(const RecordSet& src) { *this = src; }    // Copy constructor
        RecordSet& operator=(const RecordSet& src) {
            if (this != &src) {
                delete[] this->record;
                this->record = new std::string[src.noOfRecords];
                for (unsigned i = 0u; i < src.noOfRecords; ++i)
                    this->record[i] = src.record[i];                 
                this->noOfRecords = src.noOfRecords;
            }
            return *this;
        }
        RecordSet(RecordSet&& src) { *this = std::move(src); } // Move constructor
        RecordSet&& operator=(RecordSet&& src) {
            if (this != &src) {
                this->record = src.record;
                this->noOfRecords = src.noOfRecords;
                src.record = nullptr;
                src.noOfRecords = 0;            
            }
            return std::move(*this);
        }
        size_t size(); // query that returns the number of records stored in the current object.

        std::string getRecord(size_t i);
        //a query that returns the record at the index received as the function parameter in an object of type std::string.
        //If the index is invalid, this function should return an empty string.
    };
}
#endif


