#pragma once
#include "../Utility.hpp"

template <typename T>
class Item {

public:
	Item()
		:m_data(T()) {
	}

	void set_data(const T val) {
		m_data = val;
	}

	T get_data() const {
		return m_data;
	}

	void print_data() {
		print(m_data);
	}

private:
	T m_data = T();
};

void run_template_single_type_class() {
	Item<int> item1;
	item1.set_data(100);
	item1.print_data();
}