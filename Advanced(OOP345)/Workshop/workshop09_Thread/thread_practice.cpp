/******** Practice01 ***********/
//#include <iostream>
//#include <thread>
//
//void task() {
//	std::cout << "Task says Hi" << std::endl;
//}
//
//int main() {
//	std::thread t1(task);
//	std::thread t2(task);
//	std::cout << "main says Hi" << std::endl;
//
//	t2.join();
//	t1.join();
//	return 0;
//}

/******** Practice02 (Get Thread ID) ***********/
//#include<iostream>
//#include<thread>
//#include<vector>
//const int NT = 10;
//void task(){
//	std::cout << "Thread id = " << std::this_thread::get_id() << std::endl;
//}
//int main() {
//	//create a vector of threads
//	std::vector<std::thread> threads;
//	//launch execution of each thread
//	for (int i = 0; i < NT; i++)
//		threads.push_back(std::thread(task));
//	//synchronize their execution here
//	for (auto& thread : threads)
//		thread.join();
//	return 0;
//}

/******** Practice03 (Template constructor) ***********/
//#include <iostream>
//#include <thread>
//#include <vector>
//const int NT = 10;
//void task(int i) {
//	std::cout << i << " Thread id = " << std::this_thread::get_id() << std::endl;
//}
//int main() {
//	//create a vector of non-joinable threads
//	std::vector<std::thread> mythreads;
//	//launch execution of each thread
//	for (int i = 0; i < NT; i++)
//		mythreads.push_back(std::thread(task, i));
//	// synchronize their execution here
//	for (auto& thread : mythreads)
//		thread.join();
//	return 0;
//}

/******** Practice04 (Function Object) ***********/
//#include <iostream>
//#include <thread>
//#include <vector>
//const int NT = 10;
//class Task {
//public:
//	Task() {};
//	void operator()(int i) {
//		std::cout << i << " Thread id = " << std::this_thread::get_id() << std::endl;
//	}
//};
//int main() {
//	//create a vector of non-joinable threads
//	std::vector<std::thread> threads;
//	//launch execution of each thread
//	for (int i = 0; i < NT; i++)
//		threads.push_back(std::thread(Task(), i));
//	// synchronize their execution here
//	for (auto& thread : threads)
//		thread.join();
//	return 0;
//}

/******** Practice05 (Lambda Expression) ***********/
//#include <iostream>
//#include <thread>
//#include <vector>
//const int NT = 10;
//int main() {
//	//create a vector of non-joinable threads
//	std::vector<std::thread> threads;
//	//launch execution of each thread
//	for (int i = 0; i < NT; i++)
//		threads.push_back(std::thread([=]() {
//			std::cout << i << " Thread id = " << std::this_thread::get_id() << std::endl;
//		}));
//	// synchronize their execution here
//	for (auto& thread : threads)
//		thread.join();
//	return 0;
//}

/******** Practice06 (Promise - Future) ***********/
//#include <iostream>
//#include <thread>
//#include <future>
//void task(std::promise<double>& p) {
//	p.set_value(12.34);
//}
//int main() {
//	std::promise<double> p;
//	std::future<double> f = p.get_future();
//	std::thread t(task, std::ref(p));
//	std::cout << "Value = " << f.get() << std::endl;
//	t.join();
//	return 0;
//}

/******** Practice07 (Future - Promise) ***********/
//#include <iostream>
//#include <thread>
//#include <future>
//void task(std::future<double>& f) {
//	double x = f.get();
//	std::cout << "Value = " << x << std::endl;
//}
//int main() {
//	std::promise<double> p;
//	std::future<double> f = p.get_future();
//	std::thread t(task, std::ref(f));
//	p.set_value(12.34);
//	t.join();
//	return 0;
//}

/******** Practice08 (Package Task) ***********/
//#include <iostream>
//#include <thread>
//#include <future>
//double task(double x) {
//	return x * 2;
//}
//int main() {
//	std::packaged_task<double(double)> pt(task);
//	auto f = pt.get_future();
//	pt(10);
//	double r = f.get();
//	std::cout << "Result = " << r << std::endl;
//	return 0;
//}

/******** Practice09 (async) ***********/
//#include <iostream>
//#include <thread>
//#include <future>
//double task(double x) {return x * 2;}
//int main() {
//	std::future<double> f = std::async(task, 10);
//	double r = f.get();
//	std::cout << "Result = " << r << std::endl;
//	return 0;
//}

/******** Practice10 (Future Class Template) ***********/
//#include <iostream>
//#include <future>
//double get() { return 12.34; }
//int main() {
//	std::future<double> f; // default ctor
//	std::future<double> g = std::async(get);	// move-ctor
//
//	std::cout << "After Construction" << std::endl;
//	std::cout << (f.valid() ? "f is valid" : "f is not valid") << std::endl;
//	std::cout << (g.valid() ? "g is valid" : "g is not valid") << std::endl;
//
//	f = std::move(g);
//	std::cout << "After Assignment" << std::endl;
//	std::cout << (f.valid() ? "f is valid" : "f is not valid") << std::endl;
//	std::cout << (g.valid() ? "g is valid" : "g is not valid") << std::endl;
//
//	double a = f.get();	// retrive shared value
//	std::cout << "After Retrieval" << std::endl;
//	std::cout << (f.valid() ? "f is valid" : "f is not valid") << std::endl;
//	std::cout << (g.valid() ? "g is valid" : "g is not valid") << std::endl;
//
//	std::cout << "Return Value = " << a << std::endl;
//	return 0;
//}

/******** Practice11 (Thread Local Storage) ***********/
#include<iostream>
#include<thread>
__declspec(thread) int k = 0;
void show() {
	std::cout << k << " at " << &k << std::endl;
}
void task(int i) {
	k = i;
	show();
}
int main() {
	k = 10;
	std::thread t1(task, 15);
	std::thread t2(task, 20);
	t1.join();
	t2.join();
	show();
	return 0;
}