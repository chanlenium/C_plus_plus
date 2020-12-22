/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>		// std::string, std::stoi
#include <algorithm>	// erase, sort
#include <iomanip>      // std::setw
#include <iostream>     // std::cout
#include <fstream>		// std::getline
#include <list>			// std::list
#include <numeric>		// std::accumulate
#include <cstring>		// strcmp
//#include <vld.h>
#include "SongCollection.h"

namespace sdds {
	SongCollection::SongCollection(const std::string filename) {
		std::ifstream source(filename);
		if (!source) {
			throw std::string("Unable to open [") + filename + "] file.";
		}
		else {
			std::string record, tempStr;
			size_t sPos, ePos;
			Song singeSong;
			while (!source.eof())
			{
				std::getline(source, record);
				
				tempStr = record.substr(0, 25);
				sPos = 0u;
				while (tempStr[sPos] == ' ')
					sPos++;
				ePos = tempStr.length();
				while (tempStr[ePos - 1] == ' ')
					ePos--;
				singeSong.m_title = tempStr.substr(sPos, ePos-sPos);
				
				tempStr = record.substr(25, 25);
				sPos = 0u;
				while (tempStr[sPos] == ' ')
					sPos++;
				ePos = tempStr.length();
				while (tempStr[ePos - 1] == ' ')
					ePos--;
				singeSong.m_artist = tempStr.substr(sPos, ePos - sPos);

				tempStr = record.substr(50, 25);
				sPos = 0u;
				while (tempStr[sPos] == ' ')
					sPos++;
				ePos = tempStr.length();
				while (tempStr[ePos - 1] == ' ')
					ePos--;
				singeSong.m_album = tempStr.substr(sPos, ePos - sPos);

				tempStr = record.substr(75, 5);
				tempStr.erase(remove(tempStr.begin(), tempStr.end(), ' '), tempStr.end());
				if (tempStr == "") {
					singeSong.m_releaseYear = 0;
				}
				else {
					singeSong.m_releaseYear = std::stoi(tempStr);
				}
				
				tempStr = record.substr(80, 5);
				tempStr.erase(remove(tempStr.begin(), tempStr.end(), ' '), tempStr.end());
				singeSong.m_lengthOfTheSong = std::stoi(tempStr);

				tempStr = record.substr(85, 5);
				tempStr.erase(remove(tempStr.begin(), tempStr.end(), ' '), tempStr.end());
				singeSong.m_price = std::stod(tempStr);

				song.push_back(singeSong);
			}
		}

		source.close();
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::setw(20) << std::left << theSong.m_title
			<< " | " << std::setw(15) << std::left << theSong.m_artist
			<< " | " << std::setw(20) << std::left << theSong.m_album;
		if (theSong.m_releaseYear == 0) {
			out << " | " << std::setw(6) << std::right << "      ";
		}
		else {
			out << " | " << std::setw(6) << std::right << theSong.m_releaseYear;
		}
		
		out << " | " << (theSong.m_lengthOfTheSong)/60 << ":" << std::setw(2) << std::setfill('0') << (theSong.m_lengthOfTheSong) % 60 << std::setfill(' ')
			<< " | " << theSong.m_price
			<< " |";

		return out;
	}

	size_t runningTime = 0u;
	void SongCollection::display(std::ostream& out) const {
		std::for_each(song.begin(), song.end(), [=](Song singleSong) {std::cout << singleSong << std::endl; });
		
		runningTime = 0u;
		std::for_each(song.begin(), song.end(), [=](Song singleSong) {
			runningTime += singleSong.m_lengthOfTheSong;
		});
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::right << std::setw(77) << "Total Listening Time: "
			<< runningTime/3600
			<< ":" << (runningTime-3600)/60 
			<< ":" << (runningTime - 3600) % 60 
			<< std::right << " |\n";
	}

	void SongCollection::sort(std::string nameOfField) {
		if (nameOfField == "length") {
			std::sort(song.begin(), song.end(), [](Song i, Song j) -> bool {
				return (i.m_lengthOfTheSong < j.m_lengthOfTheSong); });
		}else if(nameOfField == "title" ) {
			std::sort(song.begin(), song.end(), [](Song i, Song j) -> bool {
				return ( strcmp(i.m_title.c_str(), j.m_title.c_str()) < 0 ? true : false ); });
		}
		else if (nameOfField == "album") {
			std::sort(song.begin(), song.end(), [](Song i, Song j) -> bool {
				return ( strcmp(i.m_album.c_str(), j.m_album.c_str()) < 0 ? true : false ); });
		}
	}

	void SongCollection::cleanAlbum() {
		std::for_each(song.begin(), song.end(), [&](Song& singleSong) {
			if (singleSong.m_album == "[None]") {
				singleSong.m_album = "";
			}});
	}

	bool SongCollection::inCollection(std::string nameOfArtist) const {
		auto s = std::find_if(song.begin(), song.end(), [=](const Song& singleSong) {return singleSong.m_artist == nameOfArtist; });
		if (s != song.end()) {
			return true;
		}
		else {
			return false;
		}
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string nameOfArtist) const {
		std::list<Song> myList;
		myList.insert(myList.begin(), std::make_move_iterator(song.begin()), std::make_move_iterator(song.end()));
		
		myList.erase(
			std::remove_if(myList.begin(), myList.end(),
				[=](const Song& singleSong) { return singleSong.m_artist != nameOfArtist; }),
			myList.end());

		return myList;
	}
}