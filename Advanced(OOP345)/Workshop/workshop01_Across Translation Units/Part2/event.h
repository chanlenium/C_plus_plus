/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _EVENT_H	// header guards
#define _EVENT_H

extern unsigned int g_sysClock;	// time of day as the number of seconds since midnight
// extern linkage declaration

namespace sdds
{
	class Event {
		char* description;
		unsigned int eventStartTime;
	public:
		Event();
		Event(const Event& currentEvent);
		~Event();
		void display() const;
		void setDescription(const char* bufferStr);
		void setEmpty();
		Event& operator=(const Event& src);
		bool isEmpty() const;
		void clearMemory();
	};
}

#endif

