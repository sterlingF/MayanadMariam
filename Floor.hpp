#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__
#include "base.hpp"
#include "dec.hpp"
#include <math.h>
        class Floor : public Dec{
                public:
                double val;
		Base* one; 
                Floor(Base* b) : Dec(), val(std::floor(b->evaluate())), one(b) {}
                virtual double floor(){
                        return val;
                }
		virtual Iterator* create_iterator(); 
		virtual Base* get_left(); 
		virtual Base* get_right(); 
};
Iterator* Floor::create_iterator(){
        UnaryIterator* newit = new UnaryIterator(this);
        return newit;
}

Base* Floor::get_left(){
        return one;



}
Base* Floor::get_right(){
        return nullptr;
}

#endif //__FLOOR_HPP__
