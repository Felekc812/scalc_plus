#include <gtest/gtest.h>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "controller_start.h"
// #include "exampleController.h"
// #include "start.h"

TEST(create_check_func, test1) {
  std::vector<double> meaning_x;
  std::string str = "x+2";
  S21::Controller k;
  std::vector rezalt = k.controller_formula(str, 10, &meaning_x);
  // std::cout << meaning_x.size() << "  meaning_x.size()  \n";
  int x = -8;
  for (int i = 0; i < rezalt.size(); i++) {
    // std::cout << rezalt[i] << "  rezalt[i] \n";
    // std::cout << meaning_x[i] + 2 << "  meaning_x[i] \n";
    //  std::cout << meaning_x[i] << "  x \n";
    ASSERT_DOUBLE_EQ(rezalt[i], meaning_x[i] + 2);
  }
}

TEST(create_check_increased_complexity, test1) {
  std::string str = "2^0";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 1);
}

TEST(create_check_increased_complexity, test2) {
  // S21::calk u1("0^2");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 0);

  std::string str = "0^2";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 0);
}

TEST(create_check_increased_complexity, test3) {
  S21::calk u1("2^(-2)");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 0.25);
}

TEST(create_check_increased_complexity, test4) {
  std::string str = "sin2^3";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 0.98935824662338179);

  // S21::calk u1("sin2^3");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 0.98935824662338179);
}

TEST(create_check, test1) {
  std::string str = "9*8+6-cos5";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 77.716337814536772);

  // S21::calk u1("9*8+6-cos5");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 77.716337814536772);
}

TEST(create_check, test2) {
  std::string str = "cos5";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 0.28366218546322625);

  // S21::calk u1("cos5");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 0.28366218546322625);
}

TEST(create_check, test3) {
  std::string str = "5^4";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 625);

  // S21::calk u1("5^4");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 625);
}

TEST(create_check, test4) {
  std::string str = "sin4+cos8+8*4-tan3";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 31.240244013957735);

  // S21::calk u1("sin4+cos8+8*4-tan3");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 31.240244013957735);
}

TEST(create_check, test5) {
  std::string str = "10*5/5*9/2";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 45);

  // S21::calk u1("10*5/5*9/2");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 45);
}

TEST(create_check, test6) {
  std::string str = "10+5-5+9-2";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 17);

  // S21::calk u1("10+5-5+9-2");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 17);
}
TEST(create_check, test7) {
  std::string str = "5+5*2";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 15);

  // S21::calk u2("5+5*2");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u2.rezalt(), 15);
}

TEST(create_check, test8) {
  std::string str = "5+2^3*5";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 45);

  // S21::calk u1("5+2^3*5");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 45);
}

TEST(create_check, test9) {
  std::string str = "5+cos5*5";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 6.4183109273161314);

  // S21::calk u1("5+cos5*5");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 6.4183109273161314);
}

TEST(create_check, test10) {
  std::string str = "(5+5)*2";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 20);

  // S21::calk u1("(5+5)*2");
  // std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 20);
}

TEST(create_check, test11) {
  std::string str = "2*(5+5)";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 20);

  // S21::calk u1("2*(5+5)");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 20);
}

TEST(create_check, test12) {
  std::string str = "2*sin(5+5)";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, -1.0880422217787395);

  // S21::calk u1("2*sin(5+5)+(5+2)*3");
  // S21::calk u1("2*sin(5+5)");
  // std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), -1.0880422217787395);
}

TEST(create_check, test13) {
  std::string str = "2*sin(5+5)+5";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 3.9119577782212605);

  // S21::calk u1("2*sin(5+5)+5");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 3.9119577782212605);
}
TEST(create_check, test14) {
  std::string str = "sin(5+5)+cos6";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 0.41614917576099619);

  // S21::calk u1("sin(5+5)+cos6");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 0.41614917576099619);
}
TEST(create_check, test15) {
  std::string str = "sin(5+5)+cos(5+5)";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, -1.3830926399658221);

  // S21::calk u1("sin(5+5)+cos(5+5)");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), -1.3830926399658221);
}

TEST(create_check, test16) {
  std::string str = "sin(5+5)-cos(5+5)";
  S21::Controller k;
  double rezalt = k.controller_calk(str);
  ASSERT_DOUBLE_EQ(rezalt, 0.29505041818708266);

  // S21::calk u1("sin(5+5)-cos(5+5)");
  //  std::cout << u1.rezalt() << "  rezalt \n";
  // ASSERT_DOUBLE_EQ(u1.rezalt(), 0.29505041818708266);
}

TEST(create_check, test17) {
  S21::calk u1("5-(-5)");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 10);
}

TEST(create_check, test18) {
  S21::calk u1("5+(-5)");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 0);
}

TEST(create_check, test19) {
  S21::calk u1("-5+5");
  // std::cout << u1.rezalt() << "  rezalt \n";
  ASSERT_DOUBLE_EQ(u1.rezalt(), 0);
}

///*/
int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}