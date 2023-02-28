#include "start.h"

void S21::calk::clear_end_array(char *buf, size_t size_step,
                                size_t size_step_m) {
  for (size_t i = 0; i < size_step - size_step_m; ++i) {
    buf[i] = buf[i + size_step_m];
    // printf("buf %c  \n", buf[i]);
    // printf("-  i %ld       i + size_step_m %ld     size_step %ld\n", i,
    //      i + size_step_m, size_step);
  }
  for (size_t i = size_step - size_step_m; i < size_step; ++i) {
    buf[i] = 0;
  }
}

int S21::calk::push_back_priority() {
  Node *temp = head;
  while (temp->Next != nullptr) {
    temp = temp->Next;
  }
  return temp->priority;
}

std::string S21::calk::push_back_sign() {
  Node *temp = head;
  while (temp->Next != nullptr) {
    temp = temp->Next;
  }
  return temp->sign;
}

void S21::calk::pop_back() {
  Node *temp = head;
  while (temp->Next->Next != nullptr) {
    temp = temp->Next;
  }
  Node *temp_del = temp->Next;
  delete temp_del;
  temp->Next = nullptr;
  --Size;
}

void S21::calk::bracket_to_up_priority() {
  int up_priority = 0;
  Node *current = head->Next;
  while (current != nullptr) {
    if (current->priority == 1) {
      // printf("!!!!!");
      Node *temp = current->Next;
      if (current->sign.compare("(") == 0) {
        up_priority = up_priority + 10;
        pop_this_cell(current);
      } else {
        up_priority = up_priority - 10;
        pop_this_cell(current);
      }
      current = temp;
    } else {
      if (current->priority != 0) {
        current->priority = current->priority + up_priority;
      }
      current = current->Next;
    }
  }
}

void S21::calk::in_polish_nation() {
  calk temp;
  calk buf_sig;
  Node *current = head->Next;
  while (current != nullptr) {
    if (current->priority == 0) {
      temp.push_back(current->priority, current->num, current->sign);
      //} else if (current->priority == 1) {
      //  if (current->sign.compare("(") == 0) {
      //    up_priority = up_priority + 10;
      //  } else {
      //    up_priority = up_priority - 10;
      //  }

    } else if (current->priority != 0 &&
               current->priority > buf_sig.push_back_priority()) {
      buf_sig.push_back(current->priority, current->num, current->sign);
    } else {
      // printf("^^^   %d    %d  \n", buf_sig.push_back_priority(),
      //      current->priority);
      while (buf_sig.push_back_priority() >= current->priority &&
             buf_sig.Size != 0) {
        // printf("%d    %d  \n", buf_sig.push_back_priority(),
        // current->priority);
        temp.push_back(buf_sig.push_back_priority(), 0,
                       buf_sig.push_back_sign());
        buf_sig.pop_back();
        // printf("SIZE %d\n", buf_sig.Size);
      }
      buf_sig.push_back(current->priority, current->num, current->sign);
    }

    current = current->Next;
  }
  while (buf_sig.Size != 0) {
    temp.push_back(buf_sig.push_back_priority(), 0, buf_sig.push_back_sign());
    buf_sig.pop_back();
  }
  // printf("temp\n");
  // temp.print_list();
  // printf("buf_temp\n");
  // buf_sig.print_list();
  /////////
  buf_sig.clear();
  array_copy_calk(temp);

  // temp.Size = -1;

  // printf("152 str  %d\n", temp.Size);
  // printf("array_copy_calk+  %d\n", Size);
}

void S21::calk::array_copy_calk(S21::calk temp) {  // temp.print_list();
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
  // printf("array_copy_calk+  %d  %d\n", Size, temp.Size);
  //  temp.clear();
  // printf("172 str  %d\n", temp.Size);
  // printf("array_copy_calk\n");
  temp.Size = -1;
}

void S21::calk::pop_front() {
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
}

void S21::calk::calculation() {
  Node *current = head->Next;
  while (current->Next != nullptr) {
    // std::cout << "*********************\n";
    if (current->priority >= current->Next->priority &&
        current->priority != 0) {
      // std::cout << current->sign << "  " << current->Prev->Prev->num << "  "
      //         << current->Prev->num << "\n";
      current->num = calculation_functions.at(current->sign)(
          current->Prev->Prev->num, current->Prev->num);

      // std::cout << current->Prev->num << "\n";
      if (operation_priority.at(current->sign)() < 4 ||
          operation_priority.at(current->sign)() == 5) {
        // std::cout << current->priority << current->sign <<
        // "&&&&&&&&&&&&&\n";
        pop_this_cell(current->Prev->Prev);
      }
      pop_this_cell(current->Prev);
      current->priority = 0;
      current->sign = "null";
      // print_list();
      // current = current->Next;
    }
    current = current->Next;
  }
  // std::cout << current->sign << "  " << current->Prev->Prev->num << "  "
  //         << current->Prev->num << "\n";
  current->num = calculation_functions.at(current->sign)(
      current->Prev->Prev->num, current->Prev->num);
  current->sign = "null";
  current->priority = 0;
  // std::cout << "reza\n";
  // print_list();
}

void S21::calk::pop_this_cell(S21::calk::Node *current) {
  // std::cout << "pop << " << current->priority << "\n";
  Node *del = current;
  if (current->Next != 0) {
    current->Prev->Next = current->Next;
    current->Next->Prev = current->Prev;
  } else {
    current->Prev->Next = nullptr;
  }
  delete del;
  --Size;
}
/*
void S21::calk::print_list() {
  Node *current = head;
  while (current != nullptr) {
    printf("priir %d      num %f     ", current->priority, current->num);
    // std::cout << current->sign << "  znch \n";
    current = current->Next;
  }
}
*/
void S21::calk::clear() {
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
}

void S21::calk::push_back(
    int priority_pars, double num_pars,
    std::string
        sign_pars) {  // std::cout << priority_pars << "  priority_pars ";
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
}

void S21::calk::handling_unary_operations() {
  Node *current = head->Next;
  if (current->priority == 2) {
    push_this_zero(current);
    ++head->priority;
    //  std::cout << "NULLL\n";
  }
  while (current->Next != nullptr) {
    if (current->sign.compare("(") == 0 && current->Next->priority == 2) {
      current = current->Next;
      push_this_zero(current);
      ++head->priority;
      //   std::cout << "\nNULLL\n";
    }
    current = current->Next;
  }
}

void S21::calk::push_this_zero(S21::calk::Node *current) {
  // std::cout << "NULLLLLLLLLLLLL\n";
  Node *temp = new Node(0, 0, "null");
  current->Prev->Next = temp;
  temp->Next = current;
  temp->Next->Prev = temp;
  temp->Prev = current->Prev;
  /*//
  Node *temp = current;
  if (current->Next != 0) {
    current->Prev->Next = current->Next;
    current->Next->Prev = current->Prev;
  } else {
    current->Prev->Next = nullptr;
  }
  --Size;*/
  ++Size;
}

double S21::calk::example_calculation() {
  // std::cout << "KONSTRUKTIR\n";
  // print_list();
  //  degree_corrector();
  handling_unary_operations();
  // print_list();
  bracket_to_up_priority();
  // std::cout << "UP Prioritu\n";
  // print_list();
  in_polish_nation();
  // std::cout << "POLSKAIA\n";
  // print_list();
  calculation();
  Node *temp = head;
  while (temp->Next != nullptr) {
    temp = temp->Next;
  }
  return temp->num;
}

std::vector<double> S21::calk::function_calculation(
    double end_x, std::vector<double> *meaning_x, int calculation_option) {
  std::vector<double> v_rezalt;
  double x = 0;
  if (calculation_option == 0) {
    x = end_x * -1;
  } else {
    x = end_x;
  }
  calk calk_temp;
  while (x <= end_x) {
    Node *temp = head->Next;
    while (temp != nullptr) {
      calk_temp.push_back(temp->priority, temp->num, temp->sign);
      temp = temp->Next;
    }
    Node *current_calk_temp = calk_temp.head;
    while (current_calk_temp->Next != nullptr) {
      if (current_calk_temp->sign.compare("x") == 0) {
        current_calk_temp->sign = "null";
        current_calk_temp->priority = 0;
        current_calk_temp->num = x;
      }
      current_calk_temp = current_calk_temp->Next;
    }
    v_rezalt.push_back(calk_temp.example_calculation());
    meaning_x->push_back(x);
    x = x + step(end_x);
  }
  // std::cout << meaning_x[1] << "  x \n";
  return v_rezalt;
}

double S21::calk::step(int end_x) {
  double step_x = 0;
  if (end_x < 100 && end_x > 0) {
    step_x = 0.1;
  } else if (end_x >= 100 && end_x < 1000) {
    step_x = 1;
  } else if (end_x >= 1000 && end_x < 1000000) {
    step_x = 100;
  } else {
    step_x = 0;
  }
  return step_x;
}

S21::calk::calk() {
  Size = 0;
  head = new Node(0, 0, "null");
  head->Prev = nullptr;
  head->Next = nullptr;
}

S21::calk::calk(std::string str) : calk() {
  int priority_pars;
  double num_pars;
  std::string sign_pars;

  size_t size_step = strlen(str.c_str());
  char buf[strlen(str.c_str()) + 2];
  strcpy(buf, str.c_str());
  static const std::string tokens[] = {
      "(",   ")",    "+",    "-",   "*",    "/",    "mod", "^",   "sin",
      "cos", "asin", "acos", "tan", "atan", "sqrt", "ln",  "log", "x"};
  // int a = 0;
  while (size_step) {
    size_t size_step_m = 0;
    if (std::isdigit(*buf)) {
      sign_pars = "null";
      priority_pars = 0;
      num_pars = std::stof(buf, &size_step_m);
      // std::cout << num_pars << " num \n";
      // std::cout << size_step_m << "sx \n";
    } else {
      for (auto &t : tokens) {
        if (strncmp(buf, t.c_str(), t.size()) == 0) {
          num_pars = 0;
          size_step_m = t.size();
          priority_pars = operation_priority.at(t)();
          // priority_pars = num_priority(t);
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
/*
int main() {
  S21::calk u1("9*8+6-cos5");
  std::cout << u1.rezalt() << "  rezalt \n";

  return 0;
}
*/