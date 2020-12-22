// Name: DONG CHAN OH
// Seneca Student ID: 128975190
// Seneca email: dcoh@myseneca.ca
// Date of completion: Nov 14
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#include<iostream>
#include "Utilities.h"

char Utilities::m_delimiter = '\0';

char Utilities::getDelimiter() {	// returns the delimiter character.
	return m_delimiter;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	next_pos = str.find(m_delimiter) + 1;
	if (next_pos != std::string::npos) {	// if delimiter is found
		if (str[next_pos] == m_delimiter) {	// there are two delimiters with no token between them
			more = false;
			throw("Error: there are two delimiters with no token between them");
		}
		else {
			more = true;
			// updates the current object's m_widthField data member
			if ((next_pos - 1) > getFieldWidth()) {
				setFieldWidth(next_pos - 1);
			}
			return str.substr(0, next_pos - 1);
		}
	}
	else {
		more = false;
		return "";
	}
}
