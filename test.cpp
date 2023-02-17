#include <iostream>
using namespace std;

int main() {
  string str_inp1("Python");
  string str_inp2("Python");

  cout << "String 1:" << str_inp1 << endl;
  cout << "String 2:" << str_inp2 << endl;
  int res = str_inp1.compare(str_inp2);

  if (res == 0)
    cout << "\nBoth the input strings are equal." << endl;
  else if (res < 0)
    cout << "String 1 is smaller as compared to String 2\n.";
  else
    cout << "String 1 is greater as compared to String 2\n.";
}