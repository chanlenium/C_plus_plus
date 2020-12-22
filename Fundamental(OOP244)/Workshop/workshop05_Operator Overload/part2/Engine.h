/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ENGINE_H	// header guards
#define SDDS_ENGINE_H

namespace sdds
{
	const int TYPE_MAX_SIZE = 30;

	class Engine
	{
		double m_size;	// the size of an engine
		char m_type[TYPE_MAX_SIZE + 1];	// the engine model type, as an array of characters of size TYPE_MAX_SIZE
	public:
		Engine();
		Engine(const char*, double); // custom constructor that receives as parameters the engine type and the size
		double get() const; // query that returns the size of the engine
		void display() const; // a query that prints to the screen the content of an object
		friend class Ship;
	};
}
#endif
