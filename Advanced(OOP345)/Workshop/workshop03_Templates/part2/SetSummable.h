/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SETSUMMABLE_H	// header guards
#define _SETSUMMABLE_H 
#define _CRT_SECURE_NO_WARNINGS
#include"Set.h"
#include <typeinfo> // for typeid

namespace sdds
{
	template <class T, int N> // N: the maximum number of elements
	// T: the type of any element in the collection
	// N : the maximum number of elements in the collection(an integer without sign)
	
	class SetSummable : public Set<T, N> {
	public:
		SetSummable() {}	// default constructor
		T accumulate(const std::string& filter) const {
			// initialize the accumulator by calling the one-argument constructor for a local T object that satisfies filter
			// Type T is <PairSummable> when it is called from "products" in w3_p2.cpp, 
			// so it calls constructor in "PairSummable.h"  
			T localObj(filter);		

			// this->size : It calls function size() in Base class (i.e., Set.h) 
			for (size_t i = 0; i < this->size(); i++) {
				//localObj += this[i];
				localObj += ((Set<T, N>&) * this)[i];
				//std::cout << typeid(this[i]).name() << std::endl;
				//std::cout << typeid(localObj).name() << std::endl;
				//std::cout << typeid(((Set<T, N>&) * this)[i]).name() << std::endl;
			}
			return localObj;
		}
	};
}
#endif