// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _UTILITIES_H
#define _UTILITIES_H

#include <string>	// std::string

class Utilities
{
	size_t m_widthField = 1u;					// specifying the length of the token extracted
	static char m_delimiter;					// separates the tokens from a given std::string
public:
	void setFieldWidth(size_t newWidth);			// sets the field width of the current object to the value of the parameter
	size_t getFieldWidth() const;					// returns the field width of the current object
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);	// sets the delimiter for this class to the character received
	static char getDelimiter();						// returns the delimiter character.
};
#endif

