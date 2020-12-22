#include<string>
#include<iostream>
#include<vector>

struct Person {
	std::string name;
	char status;
	unsigned id;
};

class List {
	std::vector<Person> pBook;
	void (*print)(std::ostream& os, const Person& p) { nullptr };	// function pointer
public:
	List& operator+=(const Person& p) {
		pBook.push_back(p);
		print(std::cout, p);
		return *this;
	}
	void setPrint(void (*fp)(std::ostream& os, const Person& p)) {
		print = fp;
	}
};

void printStudent(std::ostream& os, const Person& p) {
	std::cout << "Student Name = " << p.name << std::endl;
	std::cout << "Student Id = " << p.id << std::endl;

	if (p.status == 'g')
		std::cout << "Student Status = GRAUATED " << std::endl;
	else if(p.status == 'd')
		std::cout << "Student Status = DROPPED " << std::endl;
	else
		std::cout << "Student Status = CURRENTLY ENROLLED " << std::endl;
}

void printEmployee(std::ostream& os, const Person& p) {
	std::cout << "Employee Name = " << p.name << std::endl;
	std::cout << "Employee Id = " << p.id << std::endl;

	if (p.status == 'f')
		std::cout << "Employee Status = FULL-TIME " << std::endl;
	else
		std::cout << "Employee Status = PART-TIME " << std::endl;
}

Person students[]{ {"David", 'g', 568902}, {"John", 'e', 968902}, {"George", 'd', 168902} };
Person employees[]{ {"Sara", 'f', 1230987}, {"Mike", 'p', 34113}, {"Mary", 'f', 5902} };

int main() {
	List studentList;
	studentList.setPrint(printStudent);

	List employeeList;
	employeeList.setPrint(printEmployee);

	std::cout << "*******************************" << std::endl;
	for (auto p : students) {
		studentList += p;
	}
	std::cout << "*******************************" << std::endl;
	for (auto p : employees) {
		employeeList += p;
	}
	std::cout << "*******************************" << std::endl;
	return 0;
}