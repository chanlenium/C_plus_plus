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
#include <list>			// std::list

namespace sdds
{
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		int m_releaseYear;
		int m_lengthOfTheSong;
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

		void sort(std::string nameOfField);
		// receives as a parameter the name of the field used to sort the collection of songs in ascending order. 
		// The parameter can have one of the values "title", "album", or "length"

		void cleanAlbum();
		// removes the token[None] from the album field of the songs that do not have a valid album.

		bool inCollection(std::string nameOfArtist) const;
		// receives the name of an artist as a parameter
		// returns true if the collection contains any song by that artist.

		std::list<Song> getSongsForArtist(std::string nameOfArtist) const;
		// receives the name of an artist as a parameter 
		// returns the list of songs of that artist available in the collection.
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
	// inserts one song into the first parameter, using the following format
	// | TITLE(20) | ARTIST(15) | ALBUM(20) | YEAR(6) | LENGTH | PRICE |
}

#endif

