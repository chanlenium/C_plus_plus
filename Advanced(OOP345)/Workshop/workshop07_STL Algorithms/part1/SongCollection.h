/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <vector>       // std::vector

namespace sdds
{
	struct Song
	{
		std::string artist;
		std::string title;
		std::string album;
		double price;
		int releaseYear;
		int lengthOfTheSong;
	};

	class SongCollection
	{
		std::vector<Song> song;
	public:
		SongCollection(const std::string filename);
		// a custom constructor that receives as a parameter the name of the file containing the information
		// about the songs to be added to the collection. 
		// This function should load into the attributes all the songs in the file.

		void display(std::ostream& out) const;
		// print the content of the collection into the parameter (one song / line). 
		// Use the insertion operator (see below). DO NOT USE MANUAL LOOPS!
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
	// inserts one song into the first parameter, using the following format
	// | TITLE(20) | ARTIST(15) | ALBUM(20) | YEAR(6) | LENGTH | PRICE |
}

#endif

