#ifndef __SUB_HPP__
#define __SUB_HPP__
#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp" 
#include "binary_iterator.cpp" 

class Sub : public Base{
	private:
	double valm;
	double valm1;
	std::string hold; 
	std::string hold2; 
	Base* one; 
	Base* two;
	public:

	template<class v>
	Sub(v value, v value2): Base(), valm(value->evaluate()), valm1(value2->evaluate()),hold(value->stringify()), hold2(value2->stringify()), one(value), two(value2){}

	template<class v2, class T>
	Sub(v2 value, T value2): Base(), valm(value->evaluate()), valm1(value2->evaluate()), hold(value->stringify()), hold2(value2->stringify()), one(value), two(value2){}

	virtual double evaluate(){return valm-valm1;}
	virtual std::string stringify(){return hold + " - " + hold2;}
	virtual Iterator* create_iterator(); 
	virtual Base* get_left(); 
	virtual Base* get_right(); 
}; 
Iterator* Sub::create_iterator(){
	BinaryIterator* newit = new BinaryIterator(this); 
	return newit; 
}

Base* Sub::get_left(){
     
        return one;
}
Base* Sub::get_right(){
       
        return two;
}

#endif //__SUB_HPP__
