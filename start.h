#ifndef START_H
#define START_H

#include <ctype.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

namespace S21 {

class calk {
 private:
  // template <typename T_Node>
  class Node {
   public:
    Node *Next, *Prev;
    double num;
    std::string sign;
    int priority;

    Node(int priority = int(), double num = double(),
         std::string sign = std::string(), Node *Next = nullptr,
         Node *Prev = nullptr) {
      this->priority = priority;
      this->num = num;
      this->sign = sign;
      this->Next = Next;
      this->Prev = Prev;
    };
    Node(const Node &other) = delete;
    Node(Node &&other) = delete;
    Node &operator=(Node &&other) = delete;
    ~Node() = default;
  };
  Node *head;
  int Size;

  void clear_end_array(char *buf, size_t size_step, size_t size_step_m);
  int push_back_priority();
  std::string push_back_sign();
  void pop_back();
  void bracket_to_up_priority();
  void in_polish_nation();
  void array_copy_calk(calk temp);
  void pop_front();
  void calculation();
  void pop_this_cell(Node *current);
  void print_list();
  void clear();
  void push_back(int priority_pars, double num_pars, std::string sign_pars);
  void handling_unary_operations();
  void push_this_zero(Node *current);
  double step(int end_x);

  std::map<std::string, double (*)(double, double)> calculation_functions{
      {"+", [](double v1, double v2) -> double { return v1 + v2; }},
      {"-", [](double v1, double v2) -> double { return v1 - v2; }},
      {"*", [](double v1, double v2) -> double { return v1 * v2; }},
      {"/", [](double v1, double v2) -> double { return v1 / v2; }},
      {"^", [](double v1, double v2) -> double { return pow(v1, v2); }},
      {"mod", [](double v1, double v2) -> double { return fmod(v1, v2); }},
      {"sin", [](double v1, double v2) -> double { return sin(v2); }},
      {"cos", [](double v1, double v2) -> double { return cos(v2); }},
      {"asin", [](double v1, double v2) -> double { return asin(v2); }},
      {"acos", [](double v1, double v2) -> double { return acos(v2); }},
      {"tan", [](double v1, double v2) -> double { return tan(v2); }},
      {"atan", [](double v1, double v2) -> double { return atan(v2); }},
      {"sqrt", [](double v1, double v2) -> double { return sqrt(v2); }},
      {"ln", [](double v1, double v2) -> double { return log(v2); }},
      {"log", [](double v1, double v2) -> double { return log10(v2); }},
  };

  std::map<std::string, int (*)()> operation_priority{
      {"(", []() -> int { return 1; }},    {")", []() -> int { return 1; }},
      {"-", []() -> int { return 2; }},    {"+", []() -> int { return 2; }},
      {"/", []() -> int { return 3; }},    {"*", []() -> int { return 3; }},
      {"mod", []() -> int { return 3; }},  {"^", []() -> int { return 5; }},
      {"sin", []() -> int { return 4; }},  {"cos", []() -> int { return 4; }},
      {"tan", []() -> int { return 4; }},  {"sqrt", []() -> int { return 4; }},
      {"ln", []() -> int { return 4; }},   {"log", []() -> int { return 4; }},
      {"asin", []() -> int { return 4; }}, {"acos", []() -> int { return 4; }},
      {"atan", []() -> int { return 4; }}, {"x", []() -> int { return 0; }},
  };
  /*
     void validator(std::string str) {
       std::cout << str << "\n";
     };

   void recognition(){};
 */
  /*
   void degree_corrector() {
     Node *current = head->Next->Next;
     int cycle = 1;
     while (current->Next != nullptr) {
       //
       if (current->priority == 9 && current->Prev->Prev->priority == 9) {
         current->priority = current->priority - cycle;
         --cycle;
       }
       current = current->Next;
     }
   }*/

 public:
  double example_calculation();
  std::vector<double> function_calculation(double end_x,
                                           std::vector<double> *meaning_x,
                                           int calculation_option);
  calk();
  calk(std::string str);
  ~calk() { clear(); };
};

}  // namespace S21

#endif