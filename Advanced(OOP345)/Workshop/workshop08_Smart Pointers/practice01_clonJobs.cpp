#include<string>
#include<iostream>

struct CronJobs {
	std::string label;
	void (*job)(std::string data);	// function pointer
};

void add(std::string s) {
	std::string d = "Original Data augmented with + ";
	d += s;
	std::cout << d << std::endl;
}

void update(std::string s) {
	std::string d = "Original Data updated with + ";
	d += s;
	std::cout << d << std::endl;
}

void create(std::string s) {
	std::string d = "New Data created with + ";
	d += s;
	std::cout << d << std::endl;
}

CronJobs task[]{{"argumnet", add}, {"modify", update}, {"produce", create}};

int main() {
	for (auto p : task) {
		p.job(p.label);
	}
	return 0;
}