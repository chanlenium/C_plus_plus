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
	class Saiyan
	{
		char* m_name = nullptr;	// A C-style string holding the name of the Saiyan.
		int m_dob;	// An integer indicating the year in which the Saiyan was born (<= 2020)
		int m_power;	// An integer indicating the strength of the Saiyan (>= 0)
		bool m_super; // A Boolean value to indicate whether the Saiyan has the ability to evolve into a Super Saiyan
		int m_level; // an integer indicating the level of a Super Saiyan (>= 0)
	public:
		Saiyan();
		Saiyan(const char*, int, int);
		~Saiyan();
		void setempty();
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(Saiyan& other);
		void clearmemory();
	};
}
#endif