#ifndef __DIV_HPP__
#define __DIV_HPP__
#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp" 
#include "binary_iterator.cpp" 
class Div : public Base{
	private:
	double valm;
	double valm1;
	std::string hold; 
	std::string hold2; 
	Base* one; 
	Base* two; 
	public:
	template<class v>
	Div(v value, v value2): Base(), valm(value->evaluate()), valm1(value2->evaluate()), hold(value->stringify()), hold2(value2->stringify()), one(value), two(value2){}

	template<class t, class t2>
	Div(t value, t2 value2): Base(), valm(value->evaluate()), valm1(value2->evaluate()), hold(value->stringify()), hold2(value2->stringify()), one(value), two(value2){}

	virtual double evaluate () {return valm/valm1;} //place holder op / op VALUE
	virtual std::string stringify() {return hold + "/" +hold2;} //op / op?
	virtual Iterator* create_iterator();
	virtual Base* get_left();
	virtual Base* get_right(); 

};
Iterator* Div::create_iterator(){
	BinaryIterator* newit = new BinaryIterator(this); 
	return newit; 
}

Base* Div::get_left(){
        return one;
}
Base* Div::get_right(){
        return two;
}

#endif// __DIV_HPP__+A
