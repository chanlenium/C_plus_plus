/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SET_H	// header guards
#define _SET_H 
#include <string>

namespace sdds
{
    template <class T, int N>
    // T: the type of any element in the collection
    // N: the maximum number of elements in the collection

    class Set {
        T s[N];   // N: capacity of the collection
        int count = 0; // current number of elements stored in the collection
    public:
        Set() : count{ 0 } {}	// default constructor

        size_t size() const {   // return the current number of elements in the collection
            return count;
        }

        const T& operator[](size_t idx) const { // return the element at index idx of the statically allocated array 
            return s[idx];
        }

        void operator+=(const T& item) { // if the collection has capacity for another element, adds a copy of item to the collection
            if (count < N)
                s[count++] = item;
        }
    };
}
#endif
