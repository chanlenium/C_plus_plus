/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SAIYAN_H	// header guards
#define SDDS_SAIYAN_H

namespace sdds
{
	const int MAX_NAME = 32;

	class Saiyan
	{
		char m_name[MAX_NAME];	// A C-style string holding the name of the Saiyan.
		int m_dob;	// An integer indicating the year in which the Saiyan was born (<= 2020)
		int m_power;	// An integer indicating the strength of the Saiyan (>= 0)
		bool m_super; // A Boolean value to indicate whether the Saiyan has the ability to evolve into a Super Saiyan
	public:
		Saiyan();
		Saiyan(const char*, int, int);
		void setempty();
		void set(const char* name, int dob, int power, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(const Saiyan& other) const;
	};
}
#endif