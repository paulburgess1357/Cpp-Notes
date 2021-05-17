#pragma once
#include "CastTestClass.hpp"
#include "../Utility.hpp"

// Static Cast
// Implicity Casts (e.g. short -> int; float -> double; etc)
// Performs the inverse cast as well (double -> float)
// Derived Class PTR -> Base Class PTR
// Base Class PTR -> Derived Class PTR (**No Checks Performed**)
// Derived Class -> Base Class

void run_static_cast(){
	float my_float = 3.14f;
	double my_double = static_cast<double>(my_float);

	double another_double{ 3.124578 };
	int my_int = static_cast<int>(another_double);

	// Derived ptr back to base
	Derived* my_derived_ptr = new Derived;
	Base* my_base_ptr = static_cast<Base*>(my_derived_ptr);

	// Base ptr to derived
	Base* my_new_base_ptr = new Base;
	Derived* my_new_derived_ptr = static_cast<Derived*>(my_new_base_ptr);

	// Derived to base
	Derived my_derived;
	Base my_base = static_cast<Base>(my_derived);

	// Base to derived (not allowed)
	Base my_base_test;
	// Derived my_derived_test = static_cast<Derived>(my_base_test);
}

// Dynamic Cast
// Used exclusively with pointers and references
// Type casting that are implicit or the inverse (Runtime checks)
// *** Performs check to make sure the operation is valid ***
//     - This check will check if a complete object will be returned
//     - If a complete type cannot be returned, nullptr is returned instead
// If type casting is to a reference type and the cast is not possible, an
// exception of 'bad_cast' is thrown

void run_dynamic_cast(){

	// Base class ptr looking at derived class converted to: Derived class ptr
	Base* my_base_ptr = new Derived;
	Derived* my_derived_ptr = dynamic_cast<Derived*>(my_base_ptr);

	// Bad (Returns nullptr)
	// Base class ptr looking at base class converted to: Derived class ptr
	Base* another_base_ptr = new Base;
	Derived* another_derived_ptr = dynamic_cast<Derived*>(another_base_ptr);
	if(another_derived_ptr == nullptr){
		print("Nullptr returned");
	}

	// Derived reference to base reference
	Derived derived_test;
	Derived& derived_test_ref = derived_test;
	Base& new_base_ref = dynamic_cast<Base&>(derived_test_ref);

	// Bad (Bad cast exception thrown)
	// Base reference to derived reference
	Base base_test;
	Base& base_test_ref = base_test;
	try {
		Derived& new_derived_ref = dynamic_cast<Derived&>(base_test_ref);
	}
	catch(std::bad_cast& bad_cast_exception){
		std::cerr << bad_cast_exception.what() << std::endl;
	}
	
}

// Const Cast
// ** You cannot use const cast on variable that are actually const.  This
//    results in undefined behavior **
// Const cast is used to remove const-ness from references and pointers that
// refer to something that is NOT const

void run_const_cast(){

	// This is allowed because 'my_integer' is actually not const.  The cast
	// removes the const-ness from the reference and ptr
	int my_integer = 0;
	const int& ref_to_my_integer = my_integer;
	const int* ptr_to_my_integer = &my_integer;

	const_cast<int&>(ref_to_my_integer) = 3;
	print(ref_to_my_integer);
	*const_cast<int*>(ptr_to_my_integer) = 4;
	print(*ptr_to_my_integer);

	// ** This will compile, BUT, the behavior is undefined **
	// my_other_integer is const, but I removed the const-ness and modify it.
	// The code will compile, but the behavior is undefined - meaning it
	// anything such as 'this might work' or the program will crash.
	const int my_other_integer = 0;
	const int& ref_to_my_other_integer = my_other_integer;
	const int* ptr_to_my_other_integer = &my_other_integer;
	const_cast<int&>(ref_to_my_other_integer) = 100;
	print(ref_to_my_other_integer);
	*const_cast<int*>(ptr_to_my_other_integer) = 200;
	print(*ptr_to_my_other_integer);
	
}

// Reinterpret Cast
// Casts a pointer to any other type of pointer (i.e. even non-related classes)
// Allows casting from a pointer to an interger type as well (and vice versa)
// There are no checks
void run_reinterpret_cast(){
	Base* my_base = new Base;	
	Other* my_other = reinterpret_cast<Other*>(my_base);
}