#ifndef CONTROLLER_START_H
#define CONTROLLER_START_H

#include "start.h"
namespace S21 {

class Controller {
 private:
  calk *model;

 public:
  double controller_calk(std::string str);
  std::vector<double> controller_formula(std::string str, int end_x,
                                         std::vector<double> *meaning_x);
};
}  // namespace S21

#endif