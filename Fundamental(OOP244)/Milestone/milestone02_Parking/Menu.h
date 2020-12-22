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

#ifndef SDDS_MENU_H	// header guards
#define SDDS_MENU_H
#include <iostream>

namespace sdds
{
	class MenuItem
	{
		char* mItem;	// C-style character string with unknown length
	public:
		MenuItem();
		MenuItem(const char* menuInput);
		void display() const;
		MenuItem(const MenuItem&) = delete;	// copying
		MenuItem& operator=(const MenuItem&) = delete; // assignment
		~MenuItem();
		void setempty();
		void clearmemory();
		friend class Menu;
	};


	const int MAX_NO_OF_ITEMS = 10;

	class Menu
	{
		char* title;	// C-styles string with unknown size to hold the title of the menu
		MenuItem menuItem[MAX_NO_OF_ITEMS];
		int menuItemIndexState;	// variable to keep track of the number of added MenuItems to the Menu
		int indentation;
		bool valid = true;	// variable to check the object is valid or not
	public:
		Menu();
		Menu(const char* title, int indentation = 0);
		Menu(const Menu&);	// copy
		Menu& operator=(const Menu&);	// assignment
		Menu& operator=(const char* str);
		operator bool();
		bool isEmpty() const;
		void display() const;
		void add(const char* s);
		Menu& operator<<(const char* str);
		int run() const;
		~Menu();
		void clearmemory();
		void setempty();
		operator int();
		operator int() const;
		void copyAssignmentInit(const Menu& source);
		friend class Parking;
	};
}
#endif