/* Citation and Sources...
Final Project Milestone 4
Module: ReadWritable
Filename: ReadWritable.h
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/17 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_READWRITABLE_H	// header guards
#define SDDS_READWRITABLE_H
#include <iostream>
using namespace std;

namespace sdds
{
	class ReadWritable
	{
		bool commaSeparatedValuesFlag;
	public:
		ReadWritable();
		virtual ~ReadWritable();
		bool isCsv()const;
		void setCsv(bool value);
		virtual std::istream& read(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr) const;
	};
	std::istream& operator>>(std::istream& is, ReadWritable& rw);
	std::ostream& operator<<(std::ostream& os, const ReadWritable& rw);
}
#endif