#pragma once
#include <iostream>

template<typename T>
void print(T value) {
	std::cout << value << std::endl;
}

void spacer() {
	print("====================================\n");
}