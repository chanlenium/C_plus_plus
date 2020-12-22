/* Citation and Sources...
Final Project Milestone 6
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/17 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "ReadWritable.h"

namespace sdds
{
	ReadWritable::ReadWritable() {
		this->commaSeparatedValuesFlag = false;
	}

	ReadWritable::~ReadWritable() {
		// Create an empty virtual destructor for ReadWritable Class.
	}

	bool ReadWritable::isCsv() const {
		return this->commaSeparatedValuesFlag;
	}

	void ReadWritable::setCsv(bool value) {
		this->commaSeparatedValuesFlag = value;
	}

	std::istream& ReadWritable::read(istream& istr) {
		return istr;
	}

	std::ostream& ReadWritable::write(ostream& ostr) const {
		return ostr;
	}

	std::ostream& operator<<(ostream& ostr, const ReadWritable& rw) {
		rw.write(ostr);
		return ostr;
	}

	std::istream& operator>>(istream& istr, ReadWritable& rw) {
		rw.read(istr);
		return istr;
	}
}