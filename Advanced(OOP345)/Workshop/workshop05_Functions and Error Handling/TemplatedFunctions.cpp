// Template Functions
// decltype with templates

# include <iostream>

template<typename T, typename U>
auto add(const T& t, const U& u) -> decltype(t + u) { 
	return t + u; 
}

int main() {
	int i = 3, j = 6;
	double x = 4.5;
	std::cout << add(i, j) << std::endl;
	std::cout << add(i, x) << std::endl;
}