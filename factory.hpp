#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__
#include "base.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "add.hpp" 
#include "pow.hpp" 
#include "div.hpp" 
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

 
class Factory{

        public:
                Factory(){};
                Base* parse(char** input, int length);

};

Base* Factory::parse(char** input, int length){

	std::vector<std::string> tree;
	std::string num = "";
	std::string symb = "";

	std::string s = input[1];	

	for(int i = 0; i < s.size(); i++) {
		if(s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*' || s.at(i) == '/'){
			if(s.at(i) == '*' && s.at(i+1) == '*') {
				symb = "**";
				s.erase(i+1,1);
			}
			else {
				symb = s.at(i);	
			}

			tree.push_back(num);
			tree.push_back(symb);	
			num = "";
		}
		else {
			num = num + s.at(i); 
		}
		
	}
	tree.push_back(num);

	Base* lhs = new Op(std::stod(tree.at(0)));
	Base* rhs = new Op(std::stod(tree.at(2)));

	if(tree.size() >= 3) {
		if(tree.at(1) == "-") {
			Sub* sub = new Sub(lhs, rhs);
			lhs = sub;
		}
		if(tree.at(1) == "+") {
                        Add* add = new Add(lhs, rhs);
                        lhs = add;
                }
		if(tree.at(1) == "*") {
                        Mult* mult = new Mult(lhs, rhs);
                        lhs =  mult;
                }
		if(tree.at(1) == "/") {
                        Div* div = new Div(lhs, rhs);
                        lhs = div;
                }
		if(tree.at(1) == "**") {
                        Pow* pow = new Pow(lhs, rhs);
                        lhs = pow;
               } 
		
		for(int j = 0; j < 3; j++) {
			tree.erase(tree.begin());
		}		
	}
	
	Base* imsad;	
	while(tree.size()!=0) {	
		imsad = new Op(std::stod(tree.at(1)));
		 if(tree.at(0) == "-") {		
                 	Sub* sub = new Sub(lhs, imsad);
                        lhs = sub;
                }
                if(tree.at(0) == "+") {
                        Add* add = new Add(lhs, imsad);
                        lhs = add;
                }
                if(tree.at(0) == "*") {
                        Mult* mult = new Mult(lhs, imsad);
                        lhs =  mult;
                }
                if(tree.at(0) == "/") {
                        Div* div = new Div(lhs, imsad);
                        lhs = div;
                }
              if(tree.at(0) == "**") {
                     	Base* pow = new Pow(lhs, imsad);
                        lhs = pow;               
                 } 
               for(int j = 0; j < 2; j++) {
                        tree.erase(tree.begin());
                }
             			
	
	}
	
	return lhs;	 
	

}
#endif
