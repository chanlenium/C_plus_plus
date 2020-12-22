/********************************************************* /
* Student ID : 128975190
* Seneca email : dcoh@myseneca.ca
* Section: NFF
* *********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "SpellChecker.h"

namespace sdds {
	SpellChecker::SpellChecker() {};

	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file)
		{
			throw "Bad file name!";
		}
		else {
			std::string strLine = "";
			int cnt = 0;
			do
			{
				std::getline(file, strLine);
				if (strLine.length() > 0) {
					m_badWords[cnt] = strLine.substr(0, strLine.find(' '));
					strLine = strLine.substr(strLine.find(' '));
					size_t i = 0u;
					for (i = 0u; i < strLine.length() && strLine[i] == ' '; i++);
					strLine = strLine.substr(i);
					m_goodWords[cnt] = strLine;
					cnt++;
				}
			} while (file);
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		std::string::size_type n;
		for (size_t i = 0u; i < 5; i++) {
			n = text.find(this->m_badWords[i]);
			while (n != std::string::npos) {
				size_t sPos = n;
				size_t ePos = m_badWords[i].length();
				text.replace(sPos, ePos, this->m_goodWords[i]);
				n = text.find(this->m_badWords[i]);
			}
		}
	}
}