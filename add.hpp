#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "base.hpp"
#include "op.hpp"
class Add : public Base{
	private:
	double  valm;
	double valm1;
	Base* one; 
	Base* two; 
	std::string hold;
	std::string hold2; 
	public:
	template<class T>
	Add(T value, T value2): Base(), valm(value->evaluate()), valm1(value2->evaluate()), hold(value->stringify()), hold2(value2->stringify()), one(value), two(value2){}
	
	template<class T2, class v>
	Add(T2 value, v value2): Base(), valm(value->evaluate()), valm1(value2->evaluate()), hold(value->stringify()), hold2(value2->stringify()), one(value), two(value2){}

	virtual double evaluate(){return valm + valm1;}
	virtual std::string stringify() {return hold + " + "+ hold2;}
	virtual Iterator* create_iterator(); 
	virtual Base* get_left(); 
	virtual Base* get_right(); 
};

Iterator* Add::create_iterator(){
	BinaryIterator* newit = new BinaryIterator(this); 
	return newit; 
}
Base* Add::get_left(){
	return one; 
}
Base* Add::get_right(){
	return two; 
}
	
#endif //__ADD_HPP__

