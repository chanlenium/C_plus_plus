/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"

unsigned int g_sysClock = 0;	// global variable definition

namespace sdds {
	static unsigned int COUNTER {0};

	Event::Event() {
		setEmpty();
	}

	Event::Event(Event* currentEvent) {
		this->eventStartTime = currentEvent->eventStartTime;
		int len = strlen(currentEvent->description);
		strncpy(this->description, currentEvent->description, len);
		this->description[len] = '\0';
	}

	void Event::setEmpty() {
		this->description[0] = '\0';
		this->eventStartTime = 0;
	}

	void Event::setDescription(const char* bufferStr) {
		if (bufferStr == nullptr || bufferStr[0] == '\0') {
			this->setEmpty();
		}
		else {
			this->eventStartTime = ::g_sysClock;
			int len = strlen(bufferStr);
			strncpy(this->description, bufferStr, len);
			this->description[len] = '\0';
		}
	}

	void Event::display() const {
		if (this->isEmpty()) {
			std::cout.fill(' ');
			std::cout.width(3);
			std::cout << std::right << ++COUNTER << ". ";
			std::cout << "[ No Event ]" << std::endl;
		}
		else {
			unsigned int HH = this->eventStartTime / (60u * 60u);
			unsigned int MM = (this->eventStartTime - HH * 60u * 60u) / 60u;
			unsigned int SS = (this->eventStartTime - HH * 60u * 60u) % 60u;
			std::cout.fill(' ');
			std::cout.width(3);
			std::cout << std::right << ++COUNTER << ". ";
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << HH << ":";
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << MM << ":";
			std::cout.fill('0');
			std::cout.width(2);
			std::cout << SS;
			std::cout << " -> " << this->description << std::endl;
		}
	}

	Event& Event::operator=(const Event& src) {
		if (this != &src) {
			this->eventStartTime = src.eventStartTime;
			int len = strlen(src.description);
			strncpy(this->description, src.description, len);
			this->description[len] = '\0';
		}
		return *this;
	}

	bool Event::isEmpty()  const {
		bool returnVal = false;
		if (this->eventStartTime == 0 && this->description[0] == '\0') {
			returnVal = true;
		}
		return returnVal;
	}
}