#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "iterator.hpp" 


class Rand : public Base {

   private:
       double val;
   public:
        /*Constructor*/
        Rand() : Base() {
		val = rand() % 100;
	 }

        /*Functions*/
        virtual double evaluate() { return val; }
       std::string stringify() { return std::to_string(val); }
	virtual Iterator* create_iterator(); 
	virtual Base* get_left(); 
	virtual Base* get_right(); 
};
Iterator* Rand::create_iterator(){
	NullIterator* newit = new NullIterator(this); 
	return newit; 

}
Base* Rand::get_left(){
	return nullptr; 
}
Base* Rand::get_right(){
	return nullptr;
}
#endif //__RAND_HPP__
