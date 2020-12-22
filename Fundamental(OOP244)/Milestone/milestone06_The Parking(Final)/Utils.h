/* Citation and Sources...
Final Project Milestone 6
Module: Utils
Filename: Utils.h
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/23 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_UTILS_H	// header guards
#define SDDS_UTILS_H

namespace sdds
{
	int getPosInt(int max, int min = 0);
	bool yesNo();
	void convertLicencePlateUppercase(char* str);
}
#endif