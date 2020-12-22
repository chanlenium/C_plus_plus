/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
//#include <vld.h>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") + string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);	// Sets the current position in the input stream to offset('0') from 'std::ios::end'
		nbytes = (int)input.tellg() + 1;// tellg(): Returns the position of the current character in the input stream.

		text = new char[nbytes];

		input.seekg(ios::beg);	// set the current position in the input stream to 'ios::beg'(begin)
		int i = 0;
		input >> noskipws;	// This flag reads the whitespaces in the input stream before the first non-whitespace character.
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads to encrypt/decrypt the text.
		//converter(text, key, nbytes, Cryptor());
		std::vector<std::thread> threads;	//create a vector of threads

		const size_t numOfThreads = 2;			// launch execution of each thread;
		for (size_t i = 0; i < numOfThreads; i++) {
			auto task = std::bind(converter, text+(nbytes/numOfThreads)*i, key, nbytes/numOfThreads, Cryptor());
			threads.push_back(std::thread(task));	
		}
		
		// synchronoze their execution here
		for (auto& thread : threads)
			thread.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			std::ofstream fileForWrite(file, std::ios::out | std::ios::binary | std::ios::trunc);
			if (!fileForWrite)
				throw string("\n***Failed to open file ");

			// TODO: write data into the binary file and close the file
			//fileForWrite.write(text, sizeof text - 1);
			fileForWrite.write(text, nbytes);
			fileForWrite.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::ifstream fileForRead(file, std::ios::in | std::ios::binary);
		if (!fileForRead)
			throw string("\n***Failed to open file ");

		// TODO: - allocate memory here for the file content
		if (text != nullptr) {
			delete[] text;
			text = nullptr;
		}
		text = new char[nbytes + 1];

		// TODO: - read the content of the binary file
		fileForRead.read(text, nbytes);
		text[nbytes] = '\0';
		/*while (fileForRead)
			fileForRead.read(text++, 1);
		*--text = '\0';*/

		fileForRead.close();

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
