/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _PAIR_H	// header guards
#define _PAIR_H 
#include<iostream>

namespace sdds
{
	template <class K, class V>
	class Pair {
		K mKey;
		V mValue;
	public:
		Pair() {};	// default constructor

		// Copy the values referred to by the parameters into the instance variables
		Pair(const K& k, const V& v) : mKey{ k }, mValue{ v } {	};

		const K& key() const {
			return mKey;	// return the key component of the pair
		}

		const V& value() const {
			return mValue;	// return the value component of the pair
		}

		// Insert into stream os the key and the value of the pair
		virtual void display(std::ostream& os) const {
			os << this->key() << " : " << this->value() << std::endl;
		}

		// free Helper
		friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
			pair.display(os);
			return os;
		}
	};
}
#endif