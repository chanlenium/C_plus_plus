/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Basket.h"
using namespace std;

namespace sdds
{
	void Basket::clearmemory() {
		delete[] this->m_fruits;
	}
	
	void Basket::setEmpty() {
		this->m_cnt = 0;
		this->m_price = 0;
		this->m_fruits = nullptr;
	}


	Basket::Basket() {
		this->setEmpty();
	}


	Basket::~Basket() {
		this->clearmemory();
	}


	Basket::Basket(const Fruit* fruit, int cnt, double price){
		if (fruit != nullptr && cnt >= 0 && price >= 0) {
			this->m_cnt = cnt;
			this->m_price = price;
			this->m_fruits = new Fruit[cnt];
			for (int i = 0; i < cnt; i++) {
				strcpy(this->m_fruits[i].m_name, fruit[i].m_name);
				this->m_fruits[i].m_qty = fruit[i].m_qty;
			}
		}
		else {
			this->setEmpty();
		}
	}


	void Basket::init(const Basket& basket) {
		if (basket.m_fruits != nullptr && basket.m_cnt >= 0 && basket.m_price >= 0) {
			this->m_cnt = basket.m_cnt;
			this->m_price = basket.m_price;
			this->m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < basket.m_cnt; i++) {
				strcpy(this->m_fruits[i].m_name, basket.m_fruits[i].m_name);
				this->m_fruits[i].m_qty = basket.m_fruits[i].m_qty;
			}
		}
		else {
			this->setEmpty();
		}
	}

	Basket::Basket(const Basket& basket) {
		this->init(basket);
	}


	Basket& Basket::operator=(const Basket& basket) {
		if (this != &basket) {
			this->clearmemory();
			this->init(basket);
		}
		return *this;
	}


	std::ostream& operator<<(std::ostream& os, const Basket& basket) {
		if (basket.m_cnt == 0) {
			cout << "The basket is empty!" << endl;
		}
		else {
			cout << "Basket Content:" << endl;
			for (int i = 0; i < basket.m_cnt; i++) {
				cout.width(10);
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << basket.m_fruits[i].m_name << ": " << basket.m_fruits[i].m_qty << "kg" << endl;
			}
			cout << "Price: " << basket.m_price << endl;
		}
		return os;
	}


	Basket& Basket::operator +=(const Fruit& fruit) {
		Fruit* tempFruit;
		int resize = this->m_cnt + 1;
		tempFruit = new Fruit[resize];
		for (int i = 0; i < resize - 1; i++) {
			strcpy(tempFruit[i].m_name, this->m_fruits[i].m_name);
			tempFruit[i].m_qty = this->m_fruits[i].m_qty;
		}
		strcpy(tempFruit[resize - 1].m_name, fruit.m_name);
		tempFruit[resize - 1].m_qty = fruit.m_qty;

		this->clearmemory();
		this->m_fruits = nullptr;

		this->m_fruits = new Fruit[resize];
		for (int i = 0; i < resize; i++) {
			strcpy(this->m_fruits[i].m_name, tempFruit[i].m_name);
			this->m_fruits[i].m_qty = tempFruit[i].m_qty;
		}
		delete[] tempFruit;
		tempFruit = nullptr;

		this->m_cnt++;

		return *this;
	}


	void Basket::setPrice(double price) {
		if (price >= 0) {
			this->m_price = price;
		}
		else {
			this->clearmemory();
			this->setEmpty();
		}
	}
}
