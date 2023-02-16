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

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}