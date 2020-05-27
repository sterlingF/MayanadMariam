#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp" 
class Op : public Base {
   

    public:
	double val;
        Op(double value) : Base(), val(value) { }
        virtual double evaluate() {return val;}
	std::string stringval = std::to_string(val);
        virtual std::string stringify() { return stringval; }
	virtual Iterator* create_iterator();
	virtual Base* get_left(); 
	virtual Base* get_right(); 
};

Iterator* Op::create_iterator(){
	NullIterator* newit = new NullIterator(this); 
	return newit; 
}

Base* Op::get_left(){
	return nullptr; 
}
Base* Op::get_right(){
	return nullptr;
}

#endif //__OP_HPP__
