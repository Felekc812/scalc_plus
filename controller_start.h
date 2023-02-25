#ifndef CONTROLLER_START_H
#define CONTROLLER_START_H

#include "start.h"
namespace S21 {

class Controller {
 private:
  calk *model;

 public:
  double controller_calk(std::string str);
  std::vector<double> controller_formula(std::string str, int end_x);  //{
  //  S21::calk u1(str);
  // std::vector rezalt = u1.rezalt_func(end_x);
  //  return rezalt;
  // };
};
}  // namespace S21

#endif