#include<string>
#include<iostream>
#include<vector>
#include<memory>

struct Person3 {
	std::string name;
	unsigned salary;
	float bonus;
};

class List3 {
public:
	std::vector<Person3> pBook;
	List3& operator+=(const Person3& p) {
		pBook.push_back(p);
		return *this;
	}
};

void printBonus(std::ostream& os, std::vector<Person3>::iterator begin, std::vector<Person3>::iterator end) {
	for (auto i = begin; i != end; ++i) {
		std::cout << "Employee Name = " << i->name << std::endl;
		std::cout << "Employee Salary = " << i->salary << std::endl;
		std::cout << "Employee Bonus = " << (i->salary)*(1+i->bonus) << std::endl;
	}
}

Person3 employee3[]{
	{"Sara", 50000, 0.01},
	{"Mike", 100000, 0.05},
	{"Mary", 200000, 0.10},
	{"David", 300000, 0.2},
	{"John", 400000, 0.25},
	{"George", 500000, 0.30},
};

int main() {
	std::unique_ptr<List3> employeeList3(new List3);
	for (auto p : employee3) {
		*employeeList3 += p;
	}
	
	printBonus(std::cout, employeeList3->pBook.begin(), employeeList3->pBook.end());
	return 0;
}