/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "RecordSet.h"
#include <iostream>
#include <fstream>

namespace sdds {
	RecordSet::RecordSet() {
        this->setEmpty();
	}

    RecordSet::~RecordSet() {
        this->clearMemory();
    }

    void RecordSet::setEmpty() {
        this->noOfRecords = 0u;
        this->record = nullptr;
    }

    void RecordSet::clearMemory() {
        delete[] this->record;
        this->record = nullptr;
    }

    RecordSet::RecordSet(char* nameOfFile) {
        std::ifstream fin(nameOfFile);
        fin.seekg(0, std::ios::beg); //bring position of file pointer to begining of file
        while (!fin.eof())
        {
            char ch;
            fin.get(ch);
            // reads the file to count the number of records present(the record delimiter should be a single space ' ')
            if (ch == ' ')
                this->noOfRecords++;
        }
        this->noOfRecords++;    // Increase number for the last word.
        fin.close(); //closing file

        this->record = new std::string[this->noOfRecords];  // allocates memory for that number of records in the array

        std::ifstream Refin(nameOfFile);
        Refin.seekg(0, std::ios::beg); //bring position of file pointer to begining of file
        size_t recordIdx = 0;
        std::string str;
        while (!Refin.eof())
        {
            char ch;
            Refin.get(ch);
            if (ch == ' ') {
                this->record[recordIdx] = str;
                recordIdx++;
                str.clear();
            }
            else {
                str += ch;
            }
        }
        this->record[recordIdx] = str.substr(0, str.length()-1);
        Refin.close(); //closing file
    }

    std::string RecordSet::getRecord(size_t i) {
        std::string returnStr="";
        if (this->record != nullptr) {
            returnStr = this->record[i];
        }
        return returnStr;
    }  

    size_t RecordSet::size() { 
        return noOfRecords;
    }
}



