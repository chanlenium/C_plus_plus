/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _TIMEDEVENTS_H	// header guards
#define _TIMEDEVENTS_H
#include <chrono>
#include<iostream>
#include <iomanip>

//extern unsigned int g_sysClock;	// time of day as the number of seconds since midnight
// extern linkage declaration

namespace sdds
{
	const int maxNoRecordObjs = 7;	// the maximum number of record objects

	class TimedEvents
	{
		static size_t noOfRecords;	// the number of records(Objects) currently stored
		std::chrono::system_clock::time_point startTime;	// the start time for the current event
		std::chrono::system_clock::time_point endTime;	// the end time for the current event		
		struct { // an array of records of anonymous structure type 
			char* eventName;	// event name
			char* unitOfTime;	// predefined units of time
			std::chrono::steady_clock::duration durationOfEvent;	// duration of the recorded event
		} records[maxNoRecordObjs];
	public:
		TimedEvents();	// default constructor
		~TimedEvents(); // destructor
		void setEmpty();
		void clearMemory();

		void startClock();	// modifier that starts the timer for an event
		void stopClock();	// modifier that stops the timer for an event
		void recordEvent(const char* nameOfEvent);	// modifier that receives the address of a C-style null terminated string that holds the name of the event.
		// This function will update the next time-record in the array:
		// stores "nanoseconds" as the units of time
		// calculatesand stores the duration of the event(use std::chrono::duration_cast<std::chrono::nanoseconds>())

		void display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& s);
	};
}
#endif

