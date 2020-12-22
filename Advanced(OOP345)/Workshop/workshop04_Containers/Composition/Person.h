//// Composition - SubObject Version
//#include "Name.h"
//
//class Person
//{
//	Name name; // subobject
//	int age;
//public:
//	Person(const char*, int);
//	void display()const;
//	void set(const char*);
//};





// Composition - Pointer Version
class Name;
class Person {
	Name* name = nullptr;	// pointer
	int age;
public:
	Person(const char*, int);
	Person(const Person&);
	Person& operator = (const Person&);
	~Person();
	void display() const;
	void set(const char*);
};