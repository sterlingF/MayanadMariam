#ifndef __PAREN_HPP__
#define __PAREN_HPP__

#include <iostream>
#include "dec.hpp"
#include "base.hpp"
#include "op.hpp"
#include "iterator" 
#include "unary_iterator.cpp" 


class Paren : public Dec {

   private:
       std::string hold;
	double val; 
	Base* one; 
   public:
        /*Constructor*/
        template<class t>
        Paren(t operand1) : Dec(), hold(operand1->stringify()), val(operand1->evaluate()), one(operand1) {}

	virtual Iterator* create_iterator(); 
        virtual std::string stringify() {return "(" + hold + ")" ;}
	virtual Base* get_left(); 
	virtual Base* get_right(); 

};
Iterator* Paren::create_iterator(){
	UnaryIterator* newit = new UnaryIterator(this); 
	return newit; 
}

Base* Paren::get_left(){
        return one;
}
Base* Paren::get_right(){
        return nullptr;
}

#endif //__PAREN_HPP__  
