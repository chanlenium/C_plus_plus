/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _BOOK_H
#define _BOOK_H

#include <string>
#include "SpellChecker.h"

namespace sdds
{
	class Book
	{
		std::string authorOfBook;
		std::string titleOfBook;
		std::string countryOfPublication;	// the country of publication
		size_t yearOfPublicaion;	// the year of publication;
		double priceOftheBook;	// the price of the book;
		std::string description;	// the description : a short summary of the book
	public:
		// default constructor
		Book() : authorOfBook{ "" }, titleOfBook{ "" }, countryOfPublication{ "" }, yearOfPublicaion{ 0u }, priceOftheBook{ 0 }, description{ "" } {};	// default constructor

		const std::string& author() const {
			return authorOfBook;
		}

		const std::string& title() const {
			return titleOfBook;
		}; // query that returns the title of the book
		
		const std::string& country() const {
			return countryOfPublication;
		}; // query that returns the publication country
		
		const size_t& year() const {
			return yearOfPublicaion;
		};	// query that returns the publication year		
		
		double& price() {
			return priceOftheBook;
		};	// function that returns the price by reference, allowing the client code to update the price
		
		Book(const std::string& strBook); // constructor that receives a reference to an unmodifiable string that contains information about the book; 
		// this constructor extracts the information about the book from the string by parsing it and stores the information in the object's attributes. 
		
		std::string parseStr(std::string& recivedStr, const char delimiter);	// parse string
		
		Book(const Book& src) {
			*this = src;
		}

		Book& operator=(const Book& src);	// copy assignment

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(this->description);	// instance spellChecker
		};
		// this function calls the overloaded operator() on the instance spellChecker, passing to it the book description.
		// In this design, type T must have an overload of the operator() that accepts a string as a parameter.

		void display(std::ostream& os) const;

		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};
}

#endif

