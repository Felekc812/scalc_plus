#include <ctype.h>
#include <string.h>

#include <functional>
#include <iostream>
#include <list>
#include <string>

void sum() { printf("++++++\n"); };
void raz() { printf("----\n"); };
void cos() { printf("cos\n"); };
void del() { printf("////\n"); };
void mod() { printf("mod\n"); };
void step() { printf("^^^^\n"); };
void sin() { printf("sin\n"); };
void mult() { printf("mult\n"); };

int main() {
  std::string hellou = "-";
  /*
  static const std::string tokens[] = {
      "(",   ")",    "+",    "-",   "*",    "/",    "mod", "^",  "sin",
      "cos", "asin", "acos", "tan", "atan", "sqrt", "ln",  "log"};
*/
  // for (auto &t1 : tokens) {
  if (hellou.compare("cos") == 0) {
    cos();
  };
  if (hellou.compare("+") == 0) {
    sum();
  };
  if (hellou.compare("-") == 0) {
    raz();
  };
  if (hellou.compare("/") == 0) {
    del();
  };
  if (hellou.compare("*") == 0) {
    mult();
  };
  if (hellou.compare("mod") == 0) {
    mod();
  };
  if (hellou.compare("^") == 0) {
    step();
  };
  if (hellou.compare("sin") == 0) {
    sin();
  };
  //...........
  //}

  return 0;
}