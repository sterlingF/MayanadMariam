#ifndef __CEIL_HPP__
#define __CEIL_HPP__
#include "base.hpp"
#include "dec.hpp"
#include <math.h>
	class Ceil : public Dec{
		public:
		double val;
		Base* one;  
		Ceil(Base* b) : Dec(), val(b->evaluate()), one(b) {}
		virtual double ceil(){
			return (std::ceil(val)); 
		}
		virtual Iterator* create_iterator(); 
		virtual Base* get_left(); 
		virtual Base* get_right(); 

};
Iterator* Ceil::create_iterator(){
	UnaryIterator* newit = new UnaryIterator(this); 
	return newit; 
}

Base* Ceil::get_left(){
	return one; 



}
Base* Ceil::get_right(){
	return nullptr; 
}



#endif //__CEIL_HPP__
