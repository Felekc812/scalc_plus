#include <gtest/gtest.h>

#include <list>
#include <queue>
#include <stack>

#include "start.h"

TEST(create_check, test1) {
  S21::calk u1("9*8+6-cos5");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 77.716337814536772);
}
TEST(create_check, test2) {
  S21::calk u1("cos5");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 0.28366218546322625);
}

TEST(create_check, test3) {
  S21::calk u1("5^4");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 625);
}

TEST(create_check, test4) {
  S21::calk u1("sin4+cos8+8*4-tan3");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 31.240244013957735);
}

TEST(create_check, test5) {
  S21::calk u1("10*5/5*9/2");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 45);
}

TEST(create_check, test6) {
  S21::calk u1("10+5-5+9-2");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 17);
}
TEST(create_check, test7) {
  S21::calk u2("5+5*2");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u2.rezalt(), 15);
}

TEST(create_check, test8) {
  S21::calk u1("5+2^3*5");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 45);
}

TEST(create_check, test9) {
  S21::calk u1("5+cos5*5");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 6.4183109273161314);
}

TEST(create_check, test10) {
  S21::calk u1("(5+5)*2");

  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 20);
}

TEST(create_check, test11) {
  S21::calk u1("2*(5+5)");

  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 20);
}

TEST(create_check, test12) {
  // S21::calk u1("2*sin(5+5)+(5+2)*3");
  S21::calk u1("2*sin(5+5)");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), -1.0880422217787395);
}

TEST(create_check, test13) {
  S21::calk u1("2*sin(5+5)+5");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 3.9119577782212605);
}
TEST(create_check, test14) {
  S21::calk u1("sin(5+5)+cos6");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 0.41614917576099619);
}
TEST(create_check, test15) {
  S21::calk u1("sin(5+5)+cos(5+5)");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), -1.3830926399658221);
}

TEST(create_check, test16) {
  S21::calk u1("sin(5+5)-cos(5+5)");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 0.29505041818708266);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}