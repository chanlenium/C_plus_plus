/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SPELLCHECKER_H
#define _SPELLCHECKER_H

#include <string>
#include <fstream>

namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[5] = { "" };		// an array with 5 misspelled words
		std::string m_goodWords[5] = { "" };	// an array with the correct spelling of those 5 words
	public:
		SpellChecker();
		SpellChecker(const char* filename);
		// receives the address of a C - style null - terminated string that holds the name of the file that contains the misspelled words.
		// If the file exists, this constructor loads its contents.
		// If the file is missing, this constructor throws an exception of type const char*, with the message "Bad file name!".
		// Each line in the file has the format BAD_WORD GOOD_WORD; the two fields can be separated by any number of spaces.

		void operator()(std::string& text) const;
		// this operator searches text and replaces any misspelled word with the correct version
	};
}
#endif
