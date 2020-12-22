// Lambda Expression
// [capture-list] (parameter-delaration-clause) -> optional-return-tye{
//    function body
//}
// capture-list : comma seperated list of the capture specfications for the non-local variables accessed by the function body
// parameter-delaration-clause : comma separated list of the parameters that receive values of local variables within the scope of the function body

#include <iostream>

//// Empty list
//int main() {
//	// lambda expressions
//	auto hello = []() {
//		return "Hello world";
//	};
//
//	auto add4 = [](int i) {
//		return i + 4; 
//	};
//
//	auto sub4 = [](int i) {
//		return i - 4;
//	};
//
//	// calls on the lambda expressions
//	std::cout << hello() << std::endl;
//	std::cout << add4(10) << std::endl;
//	std::cout << sub4(10) << std::endl;
//}


//// Capture-by-Value
//// each lambda expression captures the non-local variable "k" by value
//template<typename Func>
//int add(int i, Func func) {
//	return func(i);
//}
//
//template<typename Func>
//int sub(int i, Func func) {
//	return func(i);
//}
//
//int main() {
//	int k = 4;
//	std::cout << add(10, [=](int i) {
//		return i + k;
//		}) << std::endl;
//	std::cout << sub(10, [=](int i) {
//		return i - k;
//		}) << std::endl;
//}



// Capture-by-Reference
// each lambda expression captures the non-local variable "k" by reference
// which enables a change to its value
template<typename Func>
int add(int a, Func func) {
	return func(a);
}

template<typename Func>
int sub(int a, Func func) {
	return func(a);
}

int main() {
	int k = 4;
	std::cout << add(10, [&](int i) {
		return i + k++;
		}) << std::endl;
	std::cout << "k = " << k << std::endl;

	std::cout << sub(10, [&](int i) {
		return i - k++;
		}) << std::endl;
	std::cout << "k = " << k << std::endl;
}