#pragma once

template<typename T1, typename T2>
struct Point {

	// Default Constructor
	Point()
		:first(T1()),
		second(T2()) {
	}

	// Constructor w/ Parameters
	Point(const T1& t1, const T2& t2)
		:first(t1),
		second(t2) {
	}

	// Copy Constructor
	Point(const Point<T1, T2>& rhs)
		:first(rhs.first),
		second(rhs.second) {
	}

	// Overloaded Assignment
	bool operator==(const Point<T1, T2>& rhs) const {
		return this->first == rhs.first && this->second == rhs.second;
	}

	T1 first;
	T2 second;
};

void run_template_multiple_types_class() {
	Point<int, float> point1;
	point1.first = 10;
	point1.second = 10.01f;

	Point<int, int> point2(12, 40);
	Point<int, int> point3(point2);
}