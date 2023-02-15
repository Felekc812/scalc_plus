#include <cmath>
#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, double (*)(double, double)> binary_operators{
      {"+", [](double v1, double v2) -> double { return v1 + v2; }},
      {"-", [](double v1, double v2) -> double { return v1 - v2; }},
      {"*", [](double v1, double v2) -> double { return v1 * v2; }},
      {"/", [](double v1, double v2) -> double { return v1 / v2; }},
      {"^", pow},
      {"mod", fmod}};
  std::map<std::string, double (*)(double)> functions{
      {"sin", sin}, {"cos", cos}, {"tan", tan}, {"ctg", [](double x) -> double {
                                                   return 1.0 / tan(x);
                                                 }}};
  std::cout << "Function (0) or binary operator (1)? ";
  bool f_or_b;
  std::cin >> f_or_b;
  std::string input;
  if (f_or_b) {
    double a, b;
    std::cout << "Enter two doubles: ";
    std::cin >> a >> b;
    std::cout << "Enter operator: ";
    std::cin >> input;
    std::cout << "Result: " << a << ' ' << input << ' ' << b << " = "
              << binary_operators.at(input)(a, b);
  } else {
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter function: ";
    std::cin >> input;
    std::cout << "Result: " << input << '(' << x
              << ") = " << functions.at(input)(x);
  }
  return 0;
}