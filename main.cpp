#include "gtest/gtest.h"
#include "op.hpp"
#include "base.hpp" 
#include "iterator.hpp"
#include "binary_iterator.cpp"
#include "unary_iterator.cpp"
#include "add.hpp"
#include "rand.hpp"
#include "div.hpp" 
#include "mult.hpp"
#include "Floor.hpp"
#include "sub.hpp"
#include "pow.hpp" 
#include "Ceil.hpp" 
#include "paren.hpp" 
#include "Abs.hpp" 
#include "trunc.hpp" 
TEST(Partone, one){
	Op* seven = new Op(7); 
	EXPECT_EQ(seven->get_left(), nullptr); 
	EXPECT_EQ(seven->get_right(), nullptr); 
	
}
TEST(CEILTEST, one){

        Op* seven = new Op(7);
	Ceil* newc = new Ceil(seven); 
        EXPECT_EQ(newc->get_left(), seven);
        EXPECT_EQ(newc->get_right(), nullptr);

}


TEST(Paren, one){

        Op* seven = new Op(7);
        Paren* newc = new Paren(seven);
        EXPECT_EQ(newc->get_left(), seven);
        EXPECT_EQ(newc->get_right(), nullptr);

}


TEST(TRUNCTEST, one){

        Op* seven = new Op(7);
        Trunc* newc = new Trunc(seven);
        EXPECT_EQ(newc->get_left(), seven);
        EXPECT_EQ(newc->get_right(), nullptr);

}



TEST(FLOORTEST, one){

        Op* seven = new Op(7);
        Floor* newc = new Floor(seven);
        EXPECT_EQ(newc->get_left(), seven);
        EXPECT_EQ(newc->get_right(), nullptr);

}

TEST(POWTEST, one){
        Op* seven = new Op(7);
        Op* two = new Op(2);
        Pow* nine = new Pow(seven, two); 
        EXPECT_EQ(nine->get_left(), seven);
        EXPECT_EQ(nine->get_right(), two);

}

TEST(SUBTEST, one){
        Op* seven = new Op(7);
        Op* two = new Op(2);
        Sub* nine = new Sub(seven, two);
        EXPECT_EQ(nine->get_left(), seven);
        EXPECT_EQ(nine->get_right(), two);

}

TEST(Parttwo, one){
        Op* seven = new Op(7);
	Op* two = new Op(2); 
	Add* nine = new Add(seven,two); 
        EXPECT_EQ(nine->get_left(), seven);
        EXPECT_EQ(nine->get_right(), two);

}

TEST(DIVTEST, one){
        Op* eight = new Op(8);
        Op* two = new Op(2);
        Div* nine = new Div(eight,two);
        EXPECT_EQ(nine->get_left(), eight);
        EXPECT_EQ(nine->get_right(), two);

}

TEST(MULTTEST, one){
        Op* eight = new Op(8);
        Op* two = new Op(2);
        Mult* sixt = new Mult(eight,two);
        EXPECT_EQ(sixt->get_left(), eight);
        EXPECT_EQ(sixt->get_right(), two);

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
