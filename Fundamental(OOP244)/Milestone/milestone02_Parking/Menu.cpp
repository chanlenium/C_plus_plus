/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author Dongchan Oh
Revision History
-----------------------------------------------------------
Date Reason
2020/7/7 Preliminary release(draft 1.0)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	// MenuItem Constructor without argument
	MenuItem::MenuItem() {
		this->setempty();
	}

	// MenuItem Constructor with 1-argument
	MenuItem::MenuItem(const char* mItem) {
		if (mItem != nullptr) {
			int len = strlen(mItem);
			this->mItem = new char[len + 1];
			strncpy(this->mItem, mItem, len);
			this->mItem[len] = '\0';
		}
		else {
			this->setempty();
		}
	}

	void MenuItem::display() const {
		if (this->mItem != nullptr) {
			cout << this->mItem << endl;
		}
	}

	// MenuItem Deconstructor 
	MenuItem::~MenuItem() {
		this->clearmemory();
	}

	// MenuItem safe empty
	void MenuItem::setempty() {
		this->mItem = nullptr;
	}

	// MenuItem clearmeomry
	void MenuItem::clearmemory() {
		delete[] this->mItem;
		this->setempty();
	}


	// Menu constructor without argument
	Menu::Menu() {
		this->setempty();
	}

	// Menu constructor with arguments
	Menu::Menu(const char* title, int indentation) {
		if (title != nullptr && indentation >= 0) {
			int len = strlen(title);
			this->title = new char[len + 1];
			strncpy(this->title, title, len);
			this->title[len] = '\0';
			this->indentation = indentation;
			this->menuItemIndexState = 0;
		}
		else {
			this->setempty();
		}
	}

	// Menu setEmpty
	void Menu::setempty() {
		this->menuItemIndexState = 0;
		this->title = nullptr;
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
			this->menuItem[i].mItem = nullptr;
		}
	}

	// Menu clearmemory
	void Menu::clearmemory() {
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
			delete[] this->menuItem[i].mItem;
			this->menuItem[i].mItem = nullptr;
		}
		delete[] this->title;
		this->setempty();
	}

	// copy&assignment init function
	void Menu::copyAssignmentInit(const Menu& source) {
		// shallow copy
		this->indentation = source.indentation;
		this->menuItemIndexState = source.menuItemIndexState;
		this->valid = source.valid;

		//deep copy
		if (source.title != nullptr) {
			int len = strlen(source.title);
			this->title = new char[len + 1];
			strncpy(this->title, source.title, len);
			this->title[len] = '\0';
			for (int i = 0; i < source.menuItemIndexState; i++) {
				int len2 = strlen(source.menuItem[i].mItem);
				this->menuItem[i].mItem = new char[len2 + 1];
				strncpy(this->menuItem[i].mItem, source.menuItem[i].mItem, len2);
				this->menuItem[i].mItem[len2] = '\0';
			}
		}
		else {
			this->clearmemory();
		}
	}

	// copy
	Menu::Menu(const Menu& source) {
		this->copyAssignmentInit(source);
	}

	// assignment
	Menu& Menu::operator=(const Menu& source) {
		if (this != &source) {
			this->clearmemory();
			this->setempty();
			this->copyAssignmentInit(source);
		}
		return *this;
	}

	// bool cast overload
	Menu::operator bool() {
		return !(this->isEmpty());
	}

	// isEmpty() function
	bool Menu::isEmpty() const {
		return (this->title == nullptr);
	}

	// display function
	void Menu::display() const {
		if (this->isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}
		else if (this->menuItemIndexState == 0) {
			cout << std::string(this->indentation * 4, ' ') << this->title << endl;
			cout << "No Items to display!" << endl;
		}
		else {
			cout << std::string(this->indentation * 4, ' ') << this->title << endl;
			for (int i = 0; i < this->menuItemIndexState; i++) {
				cout << std::string(this->indentation * 4, ' ') << i + 1 << "- " << this->menuItem[i].mItem << endl;
			}
			cout << std::string(this->indentation * 4, ' ') << "> ";
		}
	}

	// Assign a constant character C-string to Menu
	Menu& Menu::operator=(const char* str) {
		if (str != nullptr) {
			this->clearmemory();
			this->setempty();
			int len = strlen(str);
			this->title = new char[len + 1];
			strncpy(this->title, str, len);
			this->title[len] = '\0';
		}
		else {
			this->clearmemory();
			this->setempty();
		}
		return *this;
	}

	// add function
	void Menu::add(const char* str) {
		if (this->isEmpty() != true && this->valid == true && str != nullptr) {
			if (this->menuItemIndexState <= MAX_NO_OF_ITEMS) {
				int len = strlen(str);
				this->menuItem[this->menuItemIndexState].mItem = new char[len + 1];
				strncpy(this->menuItem[this->menuItemIndexState].mItem, str, len);
				this->menuItem[this->menuItemIndexState].mItem[len] = '\0';
				this->menuItemIndexState++;
			}
			else {
				this->valid = false;
			}
		}
		else {
			this->valid = false;
			this->clearmemory();
			this->setempty();
		}
	}

	// Insertion operator overload (воб╞<<воб╛)
	Menu& Menu::operator<<(const char* inputStr) {
		this->add(inputStr);
		return *this;
	}

	// run function
	int Menu::run() const {
		this->display();
		int returnVal = 0;
		if (this->menuItemIndexState != 0) {
			returnVal = getPosInt(this->menuItemIndexState);
		}
		return returnVal;
	}

	// Integer cast overload
	Menu::operator int() {
		int number = this->run();
		return number;
	}

	// Integer cast overload (const ver)
	Menu::operator int() const {
		int number = this->run();
		return number;
	}

	// Menu destructor
	Menu::~Menu() {
		this->clearmemory();
	}
}

