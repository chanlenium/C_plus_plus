/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>		// std::string, std::stoi
#include <algorithm>	// erase
#include <iomanip>      // std::setw
#include <iostream>     // std::cout
#include <fstream>		// std::getline
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
				singeSong.title = tempStr.substr(sPos, ePos-sPos);
				
				tempStr = record.substr(25, 25);
				sPos = 0u;
				while (tempStr[sPos] == ' ')
					sPos++;
				ePos = tempStr.length();
				while (tempStr[ePos - 1] == ' ')
					ePos--;
				singeSong.artist = tempStr.substr(sPos, ePos - sPos);

				tempStr = record.substr(50, 25);
				sPos = 0u;
				while (tempStr[sPos] == ' ')
					sPos++;
				ePos = tempStr.length();
				while (tempStr[ePos - 1] == ' ')
					ePos--;
				singeSong.album = tempStr.substr(sPos, ePos - sPos);

				tempStr = record.substr(75, 5);
				tempStr.erase(remove(tempStr.begin(), tempStr.end(), ' '), tempStr.end());
				if (tempStr == "") {
					singeSong.releaseYear = 0;
				}
				else {
					singeSong.releaseYear = std::stoi(tempStr);
				}
				
				tempStr = record.substr(80, 5);
				tempStr.erase(remove(tempStr.begin(), tempStr.end(), ' '), tempStr.end());
				singeSong.lengthOfTheSong = std::stoi(tempStr);

				tempStr = record.substr(85, 5);
				tempStr.erase(remove(tempStr.begin(), tempStr.end(), ' '), tempStr.end());
				singeSong.price = std::stod(tempStr);

				song.push_back(singeSong);
			}
		}

		source.close();
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::setw(20) << std::left << theSong.title
			<< " | " << std::setw(15) << std::left << theSong.artist
			<< " | " << std::setw(20) << std::left << theSong.album;
		if (theSong.releaseYear == 0) {
			out << " | " << std::setw(6) << std::right << "      ";
		}
		else {
			out << " | " << std::setw(6) << std::right << theSong.releaseYear;
		}
		
		out << " | " << (theSong.lengthOfTheSong)/60 << ":" << std::setw(2) << std::setfill('0') << (theSong.lengthOfTheSong) % 60 << std::setfill(' ')
			<< " | " << theSong.price
			<< " | " << std::endl;
		return out;
	}

	void SongCollection::display(std::ostream& out) const {
		std::for_each(song.begin(), song.end(), [=](Song singleSong) {std::cout << singleSong;});
	}
}