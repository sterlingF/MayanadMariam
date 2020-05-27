#ifndef __POW_HPP__
#define __POW_HPP__
#include "base.hpp"
#include "op.hpp" 
#include <cmath>
#include "iterator.hpp"
#include "binary_iterator.cpp" 
class Pow : public Base{
	private: 
	double valm;
	double valm1;
	std::string hold;
	std::string hold2; 
	Base* one; 
	Base* two; 
	public:
	template <class v>
	Pow(v value, v value2): Base(), valm(value->evaluate()), valm1(value2->evaluate()), hold(value->stringify()),hold2(value2->stringify()), one(value), two(value2){}

	template<class v2, class T>
	Pow(v2 value, T value2):Base(), valm(value->evaluate()), valm1(value2->evaluate()), hold(value->stringify()), hold2(value2->stringify()), one(value), two(value2){}

	double hold3 = pow(valm, valm1);
	virtual double evaluate(){return hold3;}
	virtual std::string stringify(){return hold + "**" + hold2;}
	virtual Iterator* create_iterator();
	virtual Base* get_left();
	virtual Base* get_right(); 
};
Iterator* Pow::create_iterator(){
	BinaryIterator* newit = new BinaryIterator(this); 
	return newit; 
}

Base* Pow::get_left(){
      
        return one;
}
Base* Pow::get_right(){
      
        return two;
}

#endif //__POW_HPP__
