// Function Pointers
// array function pointers
#include <iostream>

// ascending order comparison
template <typename T>
bool ascending(T a, T b) {
	return a > b;
}

// dscending order comparison
template <typename T>
bool descending(T a, T b) {
	return a < b;
}

// bubble sort
template <typename T>
void sort(T* a, int n, bool (*comp)(T, T)) {
	// return-type (*identifier)(parameter-type-list) = fn;
	// return-type : return type of function
	// identifier : name of pointer to the function
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (comp(a[j], a[j + 1])) {
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

template<typename T>
void display(T* a, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
}

int main() {
	int a[] = { 1,5,2,3,6,7,2 };
	// If several functions share the same return types and the same ordered set of parameter types,
	// we may store their(functions') address in an array of pointers to functions.
	// Each element of such an array points to one of the functions in the set ( or to nullptr address)

	// return-type (*identifier[n])(parameter-type-list) = { initialization-list }
	bool (*criterion[2])(int, int) = { ascending, descending };
	int n = sizeof a / sizeof(int);
	for (int i = 0; i < 2; i++) {
		sort(a, n, criterion[i]);
		display(a, n);
	}

}