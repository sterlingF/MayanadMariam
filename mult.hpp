#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "op.hpp"
#include "base.hpp"
#include "iterator.hpp" 
#include "binary_iterator.cpp" 

class Mult : public Base {

   private:
	double op1;
	double op2;
	std::string hold;
	std::string hold2; 
	Base* one; 
	Base* two; 
   public:
        /*Constructor*/
	template<class t>
        Mult(t operand1, t operand2) : Base(), op1(operand1->evaluate()), op2(operand2->evaluate()), hold(operand1->stringify()), hold2(operand2->stringify()), one(operand1), two(operand2) {}


	template<class v1, class v2>
	Mult(v1 operand1, v2 operand2): Base(), op1(operand1->evaluate()), op2(operand2->evaluate()), hold(operand1->stringify()), hold2(operand2->stringify()), one(operand1), two(operand2){}
	
       
        /*Functions*/
        virtual double  evaluate() { return op1*op2; }
	virtual Iterator* create_iterator(); 
	virtual std::string stringify() {return hold+" * "+ hold2; }
	virtual Base* get_left(); 
	virtual Base* get_right(); 
};
Iterator* Mult::create_iterator(){
	BinaryIterator* newit = new BinaryIterator(this); 
	return newit; 


}


Base* Mult::get_left(){
     
        return one;
}
Base* Mult::get_right(){
       
        return two;
}

#endif //__MULT_HPP__
