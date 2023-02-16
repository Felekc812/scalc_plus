#include <ctype.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <list>
#include <map>
#include <string>

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
    /*
    Node(const Node &other) = delete;
    Node(Node &&other) = delete;
    Node &operator=(Node &&other) = delete;
    ~Node() = default;
    */
  };
  Node *head;
  int Size;

  int num_priority(std::string t) {
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
      }
    }
    for (auto &t2 : num_2_priority) {
      if (t == t2) {
        rezalt = 2;
      }
    }
    for (auto &t3 : num_3_priority) {
      if (t == t3) {
        rezalt = 3;
      }
    }
    for (auto &t4 : num_4_priority) {
      if (t == t4) {
        rezalt = 4;
      }
    }
    for (auto &t5 : num_5_priority) {
      if (t == t5) {
        rezalt = 5;
      }
    }
    return rezalt;
  };

  void clear_end_array(char *buf, size_t size_step, size_t size_step_m) {
    for (size_t i = 0; i < size_step - size_step_m; ++i) {
      buf[i] = buf[i + size_step_m];
      // printf("buf %c  \n", buf[i]);
      // printf("-  i %ld       i + size_step_m %ld     size_step %ld\n", i,
      //      i + size_step_m, size_step);
    }
    for (size_t i = size_step - size_step_m; i < size_step; ++i) {
      buf[i] = 0;
    }
  };
  int back_priority() {
    Node *temp = head;
    while (temp->Next != nullptr) {
      temp = temp->Next;
    }
    return temp->priority;
  }
  std::string back_sign() {
    Node *temp = head;
    while (temp->Next != nullptr) {
      temp = temp->Next;
    }
    return temp->sign;
  }

  void pop_back() {
    Node *temp = head;
    while (temp->Next->Next != nullptr) {
      temp = temp->Next;
    }
    Node *temp_del = temp->Next;
    delete temp_del;
    temp->Next = nullptr;
    --Size;
  }

  // public:

  void validator(std::string hello) {
    //
    std::cout << hello << "\n";
  };
  void recognition(){};

  void in_polish() {
    calk temp;
    calk buf_sig;
    Node *current = head->Next;
    while (current != nullptr) {
      if (current->priority == 0) {
        temp.push_back(current->priority, current->num, current->sign);
      } else if (current->priority != 0 &&
                 current->priority >= buf_sig.back_priority()) {
        buf_sig.push_back(current->priority, current->num, current->sign);
      } else {
        while (buf_sig.Size != 0) {
          temp.push_back(buf_sig.back_priority(), 0, buf_sig.back_sign());
          buf_sig.pop_back();
        }
        buf_sig.push_back(current->priority, current->num, current->sign);
      }

      current = current->Next;
    }
    while (buf_sig.Size != 0) {
      temp.push_back(buf_sig.back_priority(), 0, buf_sig.back_sign());
      buf_sig.pop_back();
    }
    // printf("temp\n");
    // temp.print_list();
    // printf("buf_temp\n");
    // buf_sig.print_list();
    /////////
    buf_sig.clear();
    coop(temp);

    // temp.Size = -1;

    // printf("152 str  %d\n", temp.Size);
    // printf("coop+  %d\n", Size);
  };
  void coop(calk temp) {
    // temp.print_list();
    Node *previous_temp = temp.head;
    Node *previous_head = head;
    // clear();
    for (int i = 0; i < temp.Size + 1; i++) {
      previous_head->priority = previous_temp->priority;
      previous_head->num = previous_temp->num;
      previous_head->sign = previous_temp->sign;
      previous_head = previous_head->Next;
      previous_temp = previous_temp->Next;
    }
    // print_list();
    //
    // printf("coop+  %d  %d\n", Size, temp.Size);
    //  temp.clear();
    // printf("172 str  %d\n", temp.Size);
    // printf("coop\n");
    temp.Size = -1;
  };

  void pop_front() {
    Node *temp_del = head->Next;
    if (temp_del->Next != nullptr) {
      head->Next = temp_del->Next;
      temp_del->Next->Prev = head;
    } else {
      head->Next = nullptr;
    }
    delete temp_del;
    --head->priority;
    --Size;
  };

  void calculation() {
    Node *current = head->Next;
    while (current->Next != nullptr) {
      std::cout << "*********************\n";
      if (current->priority >= current->Next->priority &&
          current->priority != 0) {
        std::cout << current->sign << "  " << current->Prev->Prev->num << "  "
                  << current->Prev->num << "\n";
        current->num = binary_operators.at(current->sign)(
            current->Prev->Prev->num, current->Prev->num);
        current->sign = "null";
        std::cout << current->Prev->num << "\n";
        if (current->priority < 5) {
          pop_this(current->Prev->Prev);
        }
        pop_this(current->Prev);
        current->priority = 0;
        print_list();
        // current = current->Next;
      }
      current = current->Next;
    }
    std::cout << current->sign << "  " << current->Prev->Prev->num << "  "
              << current->Prev->num << "\n";
    current->num = binary_operators.at(current->sign)(current->Prev->Prev->num,
                                                      current->Prev->num);
    current->sign = "null";
    current->priority = 0;
    std::cout << "reza\n";
    print_list();
  };

  void pop_this(Node *current) {
    std::cout << "pop << " << current->priority << "\n";
    Node *del = current;
    current->Prev->Next = current->Next;
    current->Next->Prev = current->Prev;
    delete del;
    --Size;
  };

  std::map<std::string, double (*)(double, double)> binary_operators{
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

  void print_list() {
    Node *current = head;
    while (current != nullptr) {
      printf("priir %d      num %f     ", current->priority, current->num);
      std::cout << current->sign << "  znch \n";
      current = current->Next;
    }
  };
  void clear() {
    while (Size + 1 > 0) {
      // printf("cler  %d\n", Size);
      Node *temp = head;
      head = head->Next;
      if (head != nullptr) {
        head->Prev = nullptr;
      }
      delete temp;
      --Size;
    }
  };

  void push_back(int priority_pars, double num_pars, std::string sign_pars) {
    // std::cout << priority_pars << "  priority_pars ";
    // std::cout << num_pars << "  num_pars ";
    // std::cout << sign_pars << "  sign_pars \n";

    head->priority = 1 + Size;
    // if (head == nullptr) {
    //   head = new Node(priority_pars, num_pars, sign_pars);
    //   printf(">>>%d\n", head->priority);
    // } else {
    Node *current = this->head;
    while (current->Next != nullptr) {
      current = current->Next;
    }
    // printf(">>>%d   %f\n", priority_pars, num_pars);
    current->Next = new Node(priority_pars, num_pars, sign_pars);
    // printf(">>>%d   %f   ", current->Next->priority, current->Next->num);
    // std::cout << current->Next->sign << "  sign_pars \n\n";
    current->Next->Prev = current;
    //}
    ++Size;
  };

 public:
  double rezalt() {
    in_polish();
    calculation();
    Node *temp = head;
    while (temp->Next != nullptr) {
      temp = temp->Next;
    }
    return temp->num;
  }
  calk() {
    Size = 0;
    head = new Node(0, 0, "null");
    head->Prev = nullptr;
    head->Next = nullptr;
  }
  calk(std::string hello) : calk() {
    int priority_pars;
    double num_pars;
    std::string sign_pars;

    size_t size_step = strlen(hello.c_str());
    char buf[strlen(hello.c_str()) + 2];
    strcpy(buf, hello.c_str());
    static const std::string tokens[] = {
        "(",   ")",    "+",    "-",   "*",    "/",    "mod", "^",  "sin",
        "cos", "asin", "acos", "tan", "atan", "sqrt", "ln",  "log"};
    // int a = 0;
    while (size_step) {
      size_t size_step_m = 0;
      if (std::isdigit(*buf)) {
        sign_pars = "null";
        priority_pars = 0;
        num_pars = std::stof(buf, &size_step_m);
        // std::cout << num_pars << " num \n";
        //  std::cout << size_step_m << "sx \n";
      } else {
        for (auto &t : tokens) {
          if (strncmp(buf, t.c_str(), t.size()) == 0) {
            num_pars = 0;
            size_step_m = t.size();
            priority_pars = num_priority(t);
            sign_pars = t;
            //  std::cout << sign_pars << "  znch \n";
          }
        }
      }
      push_back(priority_pars, num_pars, sign_pars);
      clear_end_array(buf, size_step, size_step_m);

      // printf("size_step %ld      size_step_m %ld  \n", size_step,
      // size_step_m);

      size_step = size_step - size_step_m;
      // printf("----------------\n\n");
      //  a++;
    }
  }

  ~calk() { clear(); };
};

}  // namespace S21

int main() {
  S21::calk u1("9*8+6-cos5");
  std::cout << u1.rezalt() << "  rezalt \n";

  return 0;
}