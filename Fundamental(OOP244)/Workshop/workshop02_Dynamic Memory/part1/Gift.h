/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_GIFT_H	// header guards
#define SDDS_GIFT_H

namespace sdds
{
	#define MAX_DESC 15
	#define MAX_PRICE 999.999
	struct Gift
	{
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;
	};

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);
}

#endif

/*
m_description: a statically allocated array of characters that will store the description of the gift.The array should have MAX_DESC characters, not counting the null byte.

m_price : a floating point number in double precision that will hold the price of the gift.At minimum, the price can be 0 and the maximum will be MAX_PRICE.

m_units : a integer that will hold the number of units / copies of the Gift.For example, 2 concert - tickets, 3 gift - cards or 1 cake.The number of units has to be at least 1.
*/