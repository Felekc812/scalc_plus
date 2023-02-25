#include "controller_start.h"

double S21::Controller::controller_calk(std::string str) {
    std::cout << str << "  формула в контролеере \n";
  S21::calk u1(str);
  return u1.rezalt();
  //  return 88;
}
std::vector<double> S21::Controller::controller_formula(std::string str,
                                                        int end_x) {
  S21::calk u1(str);
  std::vector rezalt = u1.rezalt_func(end_x);
  return rezalt;
};
