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
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;

	struct Wrapping
	{
		char* m_pattern;
	};

	struct Gift
	{
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;

		Wrapping* m_wrap;
		int m_wrapLayers;
	};

	bool wrap(Gift&);
	bool unwrap(Gift&);
	void gifting(char*);
	void gifting(double&);
	void gifting(int&);
	void gifting(Gift&);
	void display(const Gift&);
	double userInput();
}

#endif
