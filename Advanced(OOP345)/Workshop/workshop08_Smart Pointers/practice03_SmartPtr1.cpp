#include<string>
#include<iostream>
#include<vector>

struct Person2 {
	std::string name;
	char status;
	unsigned id;
};

class List2 {
	std::vector<Person2> pBook;
	void (*print)(std::ostream& os, const Person2& p) { nullptr };	// function pointer
public:
	List2& operator+=(const Person2& p) {
		pBook.push_back(p);
		print(std::cout, p);
		return *this;
	}
	void setPrint(void (*fp)(std::ostream& os, const Person2& p)) {
		print = fp;
	}
};

void printStudent(std::ostream& os, const Person2& p) {
	std::cout << "Student Name = " << p.name << std::endl;
	std::cout << "Student Id = " << p.id << std::endl;

	if (p.status == 'g')
		std::cout << "Student Status = GRAUATED " << std::endl;
	else if (p.status == 'd')
		std::cout << "Student Status = DROPPED " << std::endl;
	else
		std::cout << "Student Status = CURRENTLY ENROLLED " << std::endl;
}

void printEmployee(std::ostream& os, const Person2& p) {
	std::cout << "Employee Name = " << p.name << std::endl;
	std::cout << "Employee Id = " << p.id << std::endl;

	if (p.status == 'f')
		std::cout << "Employee Status = FULL-TIME " << std::endl;
	else
		std::cout << "Employee Status = PART-TIME " << std::endl;
}

Person2 students2[]{ {"David", 'g', 568902}, {"John", 'e', 968902}, {"George", 'd', 168902} };
Person2 employees2[]{ {"Sara", 'f', 1230987}, {"Mike", 'p', 34113}, {"Mary", 'f', 5902} };

int main() {
	std::unique_ptr<List2> studentList2(new List2);
	studentList2->setPrint(printStudent);

	std::unique_ptr<List2> employeeList2(new List2);
	employeeList2->setPrint(printEmployee);

	std::cout << "*******************************" << std::endl;
	std::cout << "*** Smart Pointers ***" << std::endl;
	std::cout << "*******************************" << std::endl;
	for (auto p : students2) {
		*studentList2 += p;
	}
	std::cout << "*******************************" << std::endl;
	for (auto p : employees2) {
		*employeeList2 += p;
	}
	std::cout << "*******************************" << std::endl;
	return 0;
}