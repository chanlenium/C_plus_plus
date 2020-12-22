/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NFF
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _COLLECTION_H
#define _COLLECTION_H

#include <string>
#include <utility>
#include <stdexcept>      // std::out_of_range

namespace sdds {
	template <class T>
	class Collection
	{
		std::string nameOfCollection;	// the name of the collection
		T* arr;	// a dynamically allocated array of items T
		size_t sizeOfArray;	// the size of the array
		void (*ptrToFunction)(const Collection<T>& theCollection, const T& theBook) = nullptr;
		// This is the observer function (it observes an event): 
		// when an item has been added to the collection, 
		// the class Collection<T> will call this function informing the client about the addition.
	public:
		Collection() {};

		Collection(std::string name) {	// sets the name of the collection to the parameter and all other attributes to their default value
			nameOfCollection = name;
			arr = nullptr;
			sizeOfArray = 0u;
		}

		//Collection(Collection&& src) {	
		//	*this = std::move(src);
		//}

		//Collection&& operator=(Collection&& src) {
		//	if (this != &src) {
		//		//this->nameOfCollection = src.nameOfCollection;
		//		this->arr = src.arr;
		//	}
		//	return std::move(*this);
		//}

		~Collection() {
			delete[] arr;
		}

		T& getArr(const size_t i) const {	// a query that returns the i-th element of array.
			return arr[i];
		}

		const std::string& name() const{	// a query that returns the name of the collection.
			return nameOfCollection;
		}
		
		size_t size() const {	// a query that returns the number of items in the collection.
			return sizeOfArray;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
		// stores the address of the callback function(observer) into an attribute.
		// This parameter is a pointer to a function that returns void and accepts two parameters 
		// (a collection and an item that has just been added to the collection.)
		// This function is called when an item is added to the collection.
			ptrToFunction = observer;
		}

		Collection<T>& operator+=(const T& item) {
		// adds a copy of item to the collection, only if the collection doesn't contain an item with the same title 
		// (type T has a member function called title() that returns the title of the item). 
		// If item is already in the collection, this function does nothing. 
		// If the item is not yet in the collection, this function:
		// resizes the array of items to accommodate the new item
		// if an observer has been registered, 
		// calls the observer function passing the current object(*this) and the new item as arguments.		
			if (sizeOfArray == 0u) {
				arr = new T[sizeOfArray + 1];
				sizeOfArray++;
				arr[sizeOfArray - 1] = item;
			}
			else {
				bool found = false;
				for (size_t i = 0; !found && i < this->sizeOfArray; i++) {
					if (arr[i].title() == item.title()) {
						found = true;
					}
				}

				if (!found) {
					T* tempArr = new T[sizeOfArray + 1];
					for (size_t i = 0u; i < sizeOfArray; i++) {
						tempArr[i] = arr[i];
					}
					tempArr[sizeOfArray] = item;
					sizeOfArray++;
					delete[] arr;
					arr = tempArr;
					/*arr = nullptr;
					arr = std::move(tempArr);*/
					if (ptrToFunction != nullptr) {
						this->ptrToFunction(*this, arr[sizeOfArray - 1]);
					}
				}
			}

			return *this;
		}

		T& operator[](size_t idx) const {	// returns the item at index idx.
		// if the index is out of range, 
		// this function throws an exception of type std::out_of_range with the message Bad index[IDX].
		// Collection has[SIZE] items.
		// Use operator + to concatenate strings.
			size_t SIZE = this->size();
			if (idx >= SIZE) {
				//throw "ERROR: The index passed to the subscripting operator is out-of-bounds";
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(SIZE) + "] items.");
			}
			else {
				return arr[idx];
			}
		}
		
		T* operator[](std::string title) const {
		// returns the address of the item with the title title
		// (type T has a member function called title() that returns the title of the item).
		// If no such item exists, this function returns nullptr.
			bool found = false;
			size_t index = 0u;
			do {
				found = (this->arr[index].title() == title) ? true : false;
				index++;
			} while ((found == false) && (index < this->size()));
			
			if (found == true) {
				return &this->arr[index-1];
			}
			else {
				return nullptr;
			}			
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection& collection) {
			for (size_t i = 0u; i < collection.size(); i++) {
				collection.arr[i].display(os);
			}
			return os;
		}
	};
}



#endif

