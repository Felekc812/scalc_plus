#ifndef CONTROLLER_START_H
#define CONTROLLER_START_H

#include "start.h"
namespace S21 {

class Controller {
 private:
 calk *model;

 public:
 Controller(calk *model ) :model(model){};
  double controller_calk(std::string str);
  std::vector<double> controller_formula(std::string str, int end_x,
                                         std::vector<double> *meaning_x,
                                         int calculation_option);
};
}  // namespace S21

#endif
