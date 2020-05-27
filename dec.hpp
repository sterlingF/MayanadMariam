#ifndef __DEC_HPP__
#define __DEC_HPP__

#include "base.hpp"
#include <string>
#include "iterator.hpp" 
#include "binary_iterator.cpp" 
class Dec: public Base {
    public:
        
	Dec () {};

	Base* base;

        virtual double evaluate() {
		return base->evaluate();
	}
        virtual std::string stringify() {
		return base->stringify();
	}

};

#endif //__DEC_HPP__
