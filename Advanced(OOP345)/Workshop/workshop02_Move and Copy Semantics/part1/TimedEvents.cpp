/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include <cstring>

namespace sdds {
	size_t TimedEvents::noOfRecords = 0;

	TimedEvents::TimedEvents() {
		this->setEmpty();
	}

	void TimedEvents::setEmpty() {
		this->noOfRecords = 0u;
		for (size_t i = 0u; i < this->noOfRecords; i++) {
			this->records[i].eventName = nullptr;
			this->records[i].unitOfTime = nullptr;
		}
	}

	TimedEvents::~TimedEvents() {
		this->clearMemory();
	}
	
	void TimedEvents::clearMemory() {
		for (size_t i = 0; i < this->noOfRecords; i++) {
			delete[] this->records[i].eventName;
			delete[] this->records[i].unitOfTime;
		}
	}

	void TimedEvents::startClock() {	
		this->startTime = std::chrono::system_clock::now();
	}
	void TimedEvents::stopClock() {	
		this->endTime = std::chrono::system_clock::now();
	}

	void TimedEvents::recordEvent(const char* nameOfEvent) {
		// stores the name of file
		int len = strlen(nameOfEvent);
		this->records[this->noOfRecords].eventName = new char[len + 1];
		strncpy(this->records[this->noOfRecords].eventName, nameOfEvent, len);
		this->records[this->noOfRecords].eventName[len] = '\0';
		
		// stores "nanoseconds" as the units of time
		len = strlen("nanoseconds");
		this->records[this->noOfRecords].unitOfTime = new char[len+1];
		strncpy(this->records[this->noOfRecords].unitOfTime, "nanoseconds", len);
		this->records[this->noOfRecords].unitOfTime[len] = '\0';
		
		// stores the duration of the event
		this->records[this->noOfRecords].durationOfEvent = std::chrono::duration_cast<std::chrono::nanoseconds>(this->endTime - this->startTime);
		this->noOfRecords++;
	}

	void TimedEvents::display(std::ostream& os) const {
		std::cout << "--------------------------" << std::endl;
		std::cout << "Execution Times:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		for (size_t i = 0u; i < this->noOfRecords; i++) {
			std::cout.setf(std::ios::left);
			std::cout.fill(' ');
			std::cout << std::setw(20) << this->records[i].eventName;
			std::cout.setf(std::ios::right);
			std::cout.fill(' ');
			std::cout << std::setw(12) << this->records[i].durationOfEvent.count();
			std::cout << std::setw(12) << this->records[i].unitOfTime << std::endl;
			std::cout.unsetf(std::ios::right);
		}
		std::cout << "--------------------------" << std::endl;
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& t) {
		t.display(os);
		return os;
	};
}