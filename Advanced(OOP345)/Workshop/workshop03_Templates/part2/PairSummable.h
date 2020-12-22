/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _PAIRSUMMABLE_H	// header guards
#define _PAIRSUMMABLE_H 
#include"Pair.h"
#include<iostream>
#include<utility>

namespace sdds
{
	template <class K, class V>
	// K: the type of the key
	// V : the type of the value
	
	class PairSummable : public Pair<K, V> {
		static V initial;	// varies with the type of the value in the key-value pair 
		static size_t minFieldWidth;
	public:
		PairSummable() {};	// default constructor
		PairSummable(const K& key, const V& value = initial) : Pair<K, V>(key, value){
			this->minFieldWidth = (this->minFieldWidth < key.size()) ? key.size() : this->minFieldWidth;
		}

		PairSummable<K,V>& operator+=(const PairSummable<K, V>& ps) {
			if (this->key() == ps.key()) {
				PairSummable<K, V> tempObj(this->key(), this->value() + ps.value());
				*this = tempObj;
			}
			return *this;
		}
		
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(minFieldWidth);
			Pair<K,V>::display(os);
		}
	};

	// Initialie the class variable in the out of class PairSummable<K, V>
	template <class K, class V>
	size_t PairSummable<K, V>::minFieldWidth = 0u;
	
	// Explicit specialization of PairSummable<std::string, std::string>
	template<> std::string PairSummable<std::string, std::string>::initial = "";

	// Explicit specialization of PairSummable<std::string, int>
	template<> int PairSummable<std::string, int>::initial = 0;

	// Specification for PairSummable<std::string, std::string> type
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string> &ps) {
		if (this->key() == ps.key()) {
			if (this->value() == "") {
				PairSummable<std::string, std::string> tempObj(this->key(), (this->value() + ps.value()));
				*this = tempObj;
			}else{
				PairSummable<std::string, std::string> tempObj(this->key(), (this->value() + ", " + ps.value()));
				*this = tempObj;
			}
		}
		return *this;
	}
}
#endif
