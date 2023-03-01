#include "controller_start.h"

double S21::Controller::controller_calk(std::string str) {
  S21::calk u1(str);
  return u1.example_calculation();
}
std::vector<double> S21::Controller::controller_formula(
    std::string str, int end_x, std::vector<double> *meaning_x,
    int calculation_option) {
  S21::calk u1(str);
  std::vector rezalt =
      u1.function_calculation(end_x, meaning_x, calculation_option);
  return rezalt;
};
