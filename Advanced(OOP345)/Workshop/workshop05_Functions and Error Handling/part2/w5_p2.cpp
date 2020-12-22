// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
//#include <vld.h>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

// The observer function for adding books to the collection:
// should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection, const Book& theBook){
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
// should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection, const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title() << "\" added to collection \"" 
		<< theCollection.name() << "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the book
	sdds::Collection<sdds::Book> library("Bestsellers");
	{
		// TODO: load the first 4 books from the file "argv[1]".
		//  - read one line at a time, and pass it to the Book constructor
		//  - store each book read into the collection "library" (use the += operator)
		//  - lines that start with "#" are considered comments and should be ignored

		size_t index = 0;
		// Process the file
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}

		std::string strBook;
		do
		{
			std::getline(file, strBook);	// read one line

			// if the previous operation failed, the "file" object is in error mode
			if (file)
			{
				// Check if this is a commented line.
				// In the input file, commented lines start with '#'
				if (strBook[0] != '#') {
					sdds::Book item(strBook);	// pass the line to the Book constructor
					library += item;			// add Book object("item") into the collection "library"
					++index;
				}
			}
		} while (index < 4);	// read first 4 books

		library.setObserver(bookAddedObserver);	// trigger function pointer to function bookAddedObserver

		// TODO: add the rest of the books from the file.
		do
		{
			std::getline(file, strBook);

			// if the previous operation failed, the "file" object is in error mode
			if (file)
			{
				// Check if this is a commented line.
				// In the input file, commented lines start with '#'
				if (strBook[0] != '#') {
					sdds::Book item(strBook);
					library += item;
					++index;
				}
			}
		} while(file);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: (from in-lab) create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto priceUpdate = [&](Book& b) -> double {
		if (b.country() == "US") {
			b.price() *= usdToCadRate;
		}
		else if ((b.country() == "UK") && (b.year() >= 1990) && (b.year() <= 1999)) {
			b.price() *= gbpToCadRate;
		}
		return b.price();
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// TODO (from in-lab): iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (size_t i = 0u; i < library.size(); i++) {
		priceUpdate(library.getArr(i));
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";


	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	{
		// TODO: load 5 movies from the file "argv[2]".
		//       - read one line at a time, and pass it to the Movie constructor
		//       - store each movie read into the array "movies"
		//       - lines that start with "#" are considered comments and should be ignored
		size_t index = 0;
		// Process the file
		std::ifstream file(argv[2]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[2] << "].\n";
			return 1;
		}

		std::string strMovie;
		do
		{
			std::getline(file, strMovie);

			// if the previous operation failed, the "file" object is in error mode
			if (file)
			{
				// Check if this is a commented line.
				// In the input file, commented lines start with '#'
				if (strMovie[0] != '#') {
					sdds::Movie item(strMovie);
					movies[index] = item;
					++index;
				}
			}
		} while (index < 5);

		std::cout << "-----------------------------------------\n";
		std::cout << "Testing addition and callback function\n";
		std::cout << "-----------------------------------------\n";
		// Add a few movies to collection; no observer is set
		((theCollection += movies[0]) += movies[1]) += movies[2];
		theCollection += movies[1];
		// add more movies; now we get a callback from the collection
		theCollection.setObserver(movieAddedObserver);	// trigger function pointer to function movieAddedObserver
		theCollection += movies[3];
		theCollection += movies[3];
		theCollection += movies[4];
		std::cout << "-----------------------------------------\n\n";

		std::cout << "-----------------------------------------\n";
		std::cout << "Testing exceptions and operator[]\n";
		std::cout << "-----------------------------------------\n";

		// TODO: The following loop can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.
		for (auto i = 0u; i < 10; ++i) {
			try {
				std::cout << theCollection[i];
			}
			catch (const std::out_of_range & oor) {
				std::cerr << "EXCEPTION: " << oor.what() << '\n';
				break;
			}
		}
		std::cout << "-----------------------------------------\n\n";
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3u; i <= 4u; ++i)
	{
		// TODO: The following statement can generate generate an exception
			//         write code to handle the exception
			//       If an exception occurs print a message in the following format
			//EXCEPTION: ERROR_MESSAGE<endl>
			//         where ERROR_MESSAGE is extracted from the exception object.
		try {
			SpellChecker sp(argv[i]);
			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);

			for (auto j = 0u; j < library.size(); ++j)
				library[j].fixSpelling(sp);
		}
		catch(const char* msg){
			std::cout << "EXCEPTION: " << msg << std::endl;
		}		
	}
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n\n";

	return 0;
}
