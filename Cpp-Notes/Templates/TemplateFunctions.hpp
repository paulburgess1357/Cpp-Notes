#pragma once
#include <iostream>
#include "../Utility.hpp"

template<typename T>
T twice(T value) {
	return value * 2;
}

template<typename T>
T add(T n1, T n2) {
	T result = n1 + n2;
	return result;
}

template<typename T1, typename T2>
void print_values(const T1& val1, const T2& val2) {
	std::cout << val1 << std::endl;
	std::cout << val2 << std::endl;
}

template<typename T>
void print_value_force_type(const T& val) {
	std::cout << val << std::endl;
}

template<typename T>
void print_size() {
	std::cout << "Size of this type is: " << sizeof(T) << std::endl;
}

void run_template_functions() {
	int result = twice(10);
	print(result);
	spacer();

	result = add(1, 2);
	print(result);
	spacer();

	print_values(10, 23.45f);
	spacer();

	print_value_force_type<float>(10);
	spacer();

	print_size<int>();
}