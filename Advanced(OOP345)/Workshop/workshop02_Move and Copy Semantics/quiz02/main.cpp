//// Code 1.0
//#include<iostream>
//class A {
//	int xyz;
//public:
//	A() {
//		std::cout << "Class-A Default Constructor" << std::endl;
//	};
//	A(int num) : xyz(num) {};
//	A(const A& src) {
//		std::cout << "Class-A Copy Constructor - l-value" << std::endl;
//	};
//	A(const A&& src) {
//		std::cout << "Class-A Move Constructor - R-value" << std::endl;
//	};
//	A& operator=(const A& src) {
//		std::cout << "Class-A Copy Assignment - l-value" << std::endl;
//	};
//	A& operator=(const A&& src) {
//		std::cout << "Class-A Move Assignment - R-value" << std::endl;
//		return *this;
//	};
//};
//
//class X {
//	int ddd;
//public:
//	X(int num) : ddd(num) {};
//	X() {
//		std::cout << "Class-X Default Constructor" << std::endl;
//	};
//	X(const X& src) {
//		std::cout << "Class-X Copy Constructor - l-value" << std::endl;
//	};
//	X(const X&& src) {
//		std::cout << "Class-X Move Constructor - R-value" << std::endl;
//	};
//	X& operator=(const X& src) {
//		std::cout << "Class-X Copy Assignment - l-value" << std::endl;
//	};
//	X& operator=(const X&& src) {
//		std::cout << "Class-X Move Assignment - R-value" << std::endl;
//		return *this;
//	};
//	A bb;
//};
//
//A s;
//A b;
//
//A foo() {
//	return b;
//}
//
//A& bar() {
//	return s;
//}
//
//int main() {
//	std::cout << "********** [1] **********" << std::endl;
//	s = A(20);	// A(20)�� temporary object��. �׷��Ƿ� "="�� move assignment
//	
//	std::cout << "********** [2] **********" << std::endl;
//	s = foo();	
//	// foo()�� �̹� �����ϴ� object b(l-value, accessible memory�� �Ҵ�� object�̹Ƿ�)�� retrun type�� class A�� parameter�� ���޵Ǿ� object�� ����("A(b)")�ϴ� ���̹Ƿ� copy constructor
//	// ��� ���� return���� foo()�� ������� temporary object(�޸𸮿� ��������� �Ҵ�Ȱ��� �ƴϹǷ� ������ �Ұ��� r-value)�̹Ƿ� "="�� move assignment
//	
//	std::cout << "********** [3] **********" << std::endl;
//	A s2 = bar();
//	// bar()�� �̹� �����ϴ� object s(l-value, accessible memory�� �Ҵ�� object�̹Ƿ�)�� �ּҰ��� retrun type�� class A&�� ����(������ �ϴ� ���̹Ƿ�, copy/move �Ѵ� �ƴ�)
//	// ��� ���� return���� bar()�� �����(A&)�� object s2�� ������ parameter�� ���޵�. &�̹Ƿ� Copy constructor
//	
//	std::cout << "********** [4] **********" << std::endl;
//	s = X().bb;
//	// A bb�� ���� ����ǹǷ� "Class-A Default Constructor"��µǰ�,
//	// X()�� ���� "Class-X Default Constructor"�� ����Ǹ�,
//	// ��� ���� temporay object(R-value)�̹Ƿ� move assignment��
//
//	return 0;
//}





//// Code 2.0
//// Polymorphic Ojbects - Cloning
//// main.cpp
//#include<iostream>
//#include"Cube.h"
//#include"Sphere.h"
//
//void displayVolume(const Shape* shape) {
//	if (shape)
//		std::cout << shape->volume() << std::endl;
//	else
//		std::cout << "error" << std::endl;
//}
//
//Shape* select() {
//	Shape* shape;
//	double x;
//	char c;
//	std::cout << "s (sphere), c (cube) : ";
//	std::cin >> c;
//	if (c == 's') {
//		std::cout << "dimension : ";
//		std::cin >> x;
//		shape = new Sphere(x);
//	}
//	else if (c == 'C') {
//		std::cout << "dimension :";
//		std::cin >> x;
//		shape = new Cube(x);
//	}
//	else
//		shape = nullptr;
//	return shape;
//}
//
//int main() {
//	Shape* shape = select();
//	Shape* clone = shape->clone();
//	displayVolume(shape);
//	displayVolume(clone);
//	delete clone;
//	delete shape;
//}





//// Code 3.0
//#include <iostream>
//#include <exception>
//using namespace std;
//class Base {
//	virtual void dummy() {}
//};
//class Derived : public Base { int a; };
//class DerivedSecond : public Base { int b; };
//int main() {
//	try {
//		Base* pba = new Derived;
//		Base* pbc = new DerivedSecond;
//		Base* pbb = new Base;
//
//		Derived* pd;
//		Base* pbase;
//
//		pd = dynamic_cast<Derived*>(pba);
//		if (pd == 0)
//			cout << "Null pointer on first type-cast\n";
//
//		pd = dynamic_cast<Derived*>(pbc);
//		if (pd == 0)
//			cout << "Null pointer on second type-cast\n";
//
//		pd = dynamic_cast<Derived*>(pbb);
//		if (pd == 0)
//			cout << "Null pointer on third type-cast\n";
//
//		pbase = dynamic_cast<Base*>(pba);
//		if (pbase == 0)
//			cout << "Null pointer on fourth type-cast\n";
//	}
//	catch (exception & e) {
//		cout << "Exception: " << e.what();
//	}
//	return 0;
//}





//// code 4.0
//// Polymorphic Ojbects - RTTI
//// main.cpp
//#include<typeinfo>
//#include<iostream>
//class A {
//	int x;
//public:
//	A(int a) : x(a) {};
//	virtual void display() const {
//		std::cout << x << std::endl;
//	}
//};
//class B : public A {
//	int y;
//public:
//	B(int a = 5, int b = 6) : A(a), y(b) {}
//	void display() const {
//		A::display();
//		std::cout << y << std::endl;
//	}
//};
//class C : public B {
//	int z;
//public:
//	C(int a = 4, int b = 6, int c = 7) : B(a,b), z(c) {}
//	void display() const {
//		B::display();
//		std::cout << z << std::endl;
//	}
//};
//// Show calls display() on all types except C
////
//void show(const A* a) {
//	C cref;
//	if (typeid(*a) != typeid(cref)) {
//		a->display();
//	}
//	else {
//		std::cout << typeid(cref).name()
//			<< " Objects are private" << std::endl;
//	}
//}
//int main() {
//	A* a[3];
//	a[0] = new A(3);
//	a[1] = new B(2, 5);
//	a[2] = new C(4, 6, 7);
//	for (int i = 0; i < 3; i++)
//		show(a[i]);
//	for (int i = 0; i < 3; i++)
//		std::cout << typeid(a[i]).name() << std::endl;
//	for (int i = 0; i < 3; i++)
//		delete a[i];
//	return 0;
//}





//// code 5.0
//#include<iostream>
//#include"array.h"
//int main() {
//	Array<> s, t;
//	Array<int, 50> a, b;
//	Array<double> u, z;
//	Array<int, 40> v;
//	//std::cout << Array<>::cnt() << std::endl;
//	std::cout << Array<double, 50>::cnt() << std::endl;
//	//std::cout << Array<int, 40>::cnt() << std::endl;
//	//std::cout << Array<double>::cnt() << std::endl;
//	//std::cout << Array<int, 50>::cnt() << std::endl;
//}





// code 6.0
#include <iostream>
using namespace std;
template<class T> void f(T x, T y) { cout << " A-A" << endl; }
template<class T, class V> void f(T x, V y) { cout << " A-B" << endl; }
template<class T, class V, class D> void f(T x, V y, D z) { cout << " A-C" << endl; }
void f(int w, int z) { cout << " C-C" << endl; }
void f(int w, double z) { cout << " C-D" << endl; }
int main() {
	f(1, 2);
	//f('a', 'b');
	//f(1, 3.5);
	//f(3.5, 1);
}