#include "controller_start.h"

double S21::Controller::controller_calk(std::string str) {
    model->сreating_calculated_array(str);
  //S21::calk u1(str);
  return model->example_calculation();
}
std::vector<double> S21::Controller::controller_formula(
    std::string str, int end_x, std::vector<double> *meaning_x,
    int calculation_option) {
  model->сreating_calculated_array(str);
    //S21::calk u1(str);
  std::vector rezalt =
      model->function_calculation(end_x, meaning_x, calculation_option);
  return rezalt;
};
