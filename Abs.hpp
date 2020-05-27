#ifndef __ABS_HPP__
#define __ABS_HPP__
#include "base.hpp"
#include "dec.hpp"
#include <math.h>
        class Abs : public Dec{
                public:
                double val;
		Base* one;
                Abs(Base* b) : Dec(), val(std::abs(b->evaluate())), one(b) {}
                virtual double abs(){
                        return val;
                }
		virtual Iterator* create_iterator();
                virtual Base* get_left();
                virtual Base* get_right();

};
Iterator* Abs::create_iterator(){
        UnaryIterator* newit = new UnaryIterator(this);
        return newit;
}

Base* Abs::get_left(){
        return one;



}
Base* Abs::get_right(){
	return nullptr;
}

#endif //__ABS_HPP__
