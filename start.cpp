#include <ctype.h>
#include <string.h>

#include <iostream>
#include <list>
#include <string>

namespace S21 {

class calk {
 private:
  // template <typename T_Node>
  class Node {
   public:
    Node *Next, *Prev;
    float num;
    std::string sign;
    int priority;

    Node(int priority = int(), float num = float(),
         std::string sign = std::string(), Node *Next = nullptr,
         Node *Prev = nullptr) {
      this->num = num;
      this->sign = sign;
      this->Next = Next;
      this->Prev = Prev;
    };
    /*
    Node(const Node &other) = delete;
    Node(Node &&other) = delete;
    Node &operator=(Node &&other) = delete;
    ~Node() = default;
    */
  };
  Node *head;
  size_t Size;

  int num_priority(std::string t, size_t *size_tokens) {
    int rezalt = 0;
    static const std::string num_1_priority[] = {"(", ")"};
    static const std::string num_2_priority[] = {"+", "-"};
    static const std::string num_3_priority[] = {"*", "/", "mod"};
    static const std::string num_4_priority[] = {"^"};
    static const std::string num_5_priority[] = {
        "sin", "cos", "asin", "acos", "tan", "atan", "sqrt", "ln", "log",
    };
    for (auto &t1 : num_1_priority) {
      if (t == t1) {
        rezalt = 1;
        *size_tokens = t.size();
        // std::cout << t.size() << "znch \n";
      }
    }
    for (auto &t2 : num_2_priority) {
      if (t == t2) {
        rezalt = 2;
        *size_tokens = t.size();
        // std::cout << t.size() << "znch \n";
      }
    }
    for (auto &t3 : num_3_priority) {
      if (t == t3) {
        rezalt = 3;
        *size_tokens = t.size();
        // std::cout << t.size() << "znch \n";
      }
    }
    for (auto &t4 : num_4_priority) {
      if (t == t4) {
        rezalt = 4;
        *size_tokens = t.size();
        // std::cout << t.size() << "znch \n";
      }
    }
    for (auto &t5 : num_5_priority) {
      if (t == t5) {
        rezalt = 5;
        *size_tokens = t.size();
        // std::cout << t.size() << "znch \n";
      }
    }
    return rezalt;
  };

 public:
  void corrector(){};
  void validator(std::string hello) {
    //
    std::cout << hello << "\n";
  };
  void recognition(){};
  void in_Polish(){};
  void calculation(){};
  void clear() {
    while (Size + 1) {
      Node *temp = head;
      head = head->Next;
      if (head != nullptr) {
        head->Prev = nullptr;
      }
      delete temp;
      --Size;
    }
  };

  void push_back(int priority_pars, int num_pars, std::string sign_pars) {
    head->priority = 1 + Size;
    if (head == nullptr) {
      head = new Node(priority_pars, num_pars, sign_pars);
    } else {
      Node *current = this->head;
      while (current->Next != nullptr) {
        current = current->Next;
      }

      current->Next = new Node(priority_pars, num_pars, sign_pars);
      current->Next->Prev = current;
    }
    ++Size;
  };

  calk() {
    Size = 0;
    head = new Node(0);
    head->Prev = nullptr;
    head->Next = nullptr;
  }

  calk(std::string hello) : calk() {
    int priority_pars;
    float num_pars;
    std::string sign_pars;

    size_t size_step = strlen(hello.c_str());
    char buf[strlen(hello.c_str()) + 2];
    strcpy(buf, hello.c_str());
    static const std::string tokens[] = {
        "+",   "-",    "*",    "/",  "mod", "sin", "cos", "asin", "acos",
        "tan", "atan", "sqrt", "ln", "log", "(",   ")",   "^"};
    // int a = 0;
    while (size_step) {
      size_t size_step_m = 0;
      if (std::isdigit(*buf)) {
        sign_pars = "null";
        priority_pars = 0;
        num_pars = std::stof(buf, &size_step_m);
        std::cout << num_pars << " num \n";
        // std::cout << size_step_m << "sx \n";
      } else {
        for (auto &t : tokens) {
          if (strncmp(buf, t.c_str(), t.size()) == 0) {
            num_pars = 0;
            priority_pars = num_priority(t, &size_step_m);
            sign_pars = t;
            std::cout << sign_pars << "  znch \n";
          }
        }
      }

      push_back(priority_pars, num_pars, sign_pars);
      // std::cout << size_step << " -- size_step\n";
      // std::cout << size_step_m << "  -- size_step_m\n\n";
      //  std::cout << strlen(hello.c_str()) - size_step_m + 2 <<
      //"jacor\n";
      printf("%ld\n", size_step - size_step_m);
      if (size_step - size_step_m > 0) {
        for (size_t i = 0; i < size_step - size_step_m; i++) {
          buf[i] = buf[i + size_step_m];
          printf("-  %ld       %ld     %ld\n", i, i + size_step_m, size_step);
          // printf("z  %d       %d     %d\n", buf[i], buf[i + size_step_m],
          //      buf[size_step]);
        }
        size_step = size_step - size_step_m;
      }
    }

    // std::cout << *((char *)buf + 5) << "iol\n";
    //
  };
  ~calk() { clear(); };
};
/*
calk::calk() {}

calk::~calk() {}
*/
}  // namespace S21

int main() {
  std::string hello = "636+21";
  // const char *c_inp = hello.c_str();
  //  int res = atoi(c_inp);
  // char c_inp2 = c_inp;

  // char *c_inp = "(2+3)-1*67";

  S21::calk u1(hello);

  // std::cout << hello << "\n";

  return 0;
}