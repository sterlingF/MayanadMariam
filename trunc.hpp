#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include <iostream>
#include "dec.hpp"
#include "base.hpp"
#include "op.hpp"
#include <string>
#include "iterator.hpp" 
#include "unary_iterator.cpp" 
#include <iostream>

class Trunc : public Dec {
   
   private:
        double op1;
        std::string hold;
	Base* one; 
   public:
        /*Constructor*/
        template<class t>
        Trunc(t operand1) : Dec(), op1(operand1->evaluate()), one(operand1) {}
	virtual Iterator* create_iterator(); 
	virtual Base* get_left(); 
	virtual Base* get_right(); 
        std::string stringify() {return std::to_string(op1); }
	

};
Iterator* Trunc::create_iterator(){
	UnaryIterator* newit = new UnaryIterator(this); 
	return newit; 
}

Base* Trunc::get_left(){
       
        return one;
}
Base* Trunc::get_right(){
        return nullptr;
}

#endif //__TRUNC_HPP__                    
