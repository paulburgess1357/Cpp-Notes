#pragma once

class Base{
public:
	virtual ~Base() = default;
	virtual void simple_function(){
		
	}
};

class Derived : public Base{
public:
};

class Other{
	
};