/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _MOVIE_H
#define _MOVIE_H

#include <string>
#include <iostream>
#include "SpellChecker.h"

namespace sdds
{
	class Movie
	{
		std::string titleOfMovie = "";	// the title of movie
		size_t yearOfRelease = 0u;		// the year of release
		std::string description = "";	// the description
	public:
		Movie() : titleOfMovie{ "" }, yearOfRelease{ 0u }, description{ "" } {};	// default constructor

		const std::string& title() const {	// a query that returns the title of the movie
			return titleOfMovie;
		}

		Movie(const std::string& strMovie);
		// receives the movie through a reference to a string.
		// This constructor extracts the information about the movie from the string and stores it in the instance's attributes. 
		// The received string always has the following format: "TITLE,YEAR,DESCRIPTION"

		std::string parseStr(std::string& recivedStr, const char delimiter);

		Movie& operator=(const Movie& src);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(this->titleOfMovie);	// instance spellChecker
			spellChecker(this->description);
		}
		// This function calls the overloaded operator() on instance spellChecker, passing to it the movie title and description.
		// In this design, type T must have an overload of the operator() that accepts a string as a parameter.

		void display(std::ostream& os) const;

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}
#endif