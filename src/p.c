
#include "p.h"

int x_in_step(char *str) {
  int flag = 0;
  int kolvo_znak = 0;
  kolvo_znak = strlen(str);
  for (int i = 0; i < kolvo_znak - 1; i++) {
    if (*((char *)str + i) == 94 && *((char *)str + i - 1) == 120) {
      int b = 0;
      // printf("\n >>>> %s\n", str + i + 1);
      b = atoi(str + i + 1);
      if ((b % 2) == 0) {
        flag = 1;
      }
    }
  }
  return flag;
}

int prov_form(char *str) {
  int flag = 0;
  int ls = 0;
  int kol = 0;
  kol = strlen(str);
  for (int i = 0; i < kol; i++) {
    ls++;
    if (*((char *)str + i) == 120) {
      flag = ls;
    }
  }
  return flag;
}

int calc(char *str, double *reza) {
  char *loc = {"\0"};
  loc = setlocale(LC_ALL, "en_US.UTF-8");

  int y;
  for (y = 0;; y++) {
    if (*((char *)str + y + 1) == 61) {
      break;
    }
  }
  char str2[257];
  for (int i = 0; i < 257; i++) {
    *((char *)str2 + i) = 0;
  }
  for (int i = 0; i < y + 1; i++) {
    *((char *)str2 + i) = *((char *)str + i);
  }

  int x = validatir(str2);
  if (x == 0) {
    x = ident_formul(str2);
  }
  printf("\n%s\n", str2);
  if (x == 0) {
    struct parser A[255];
    *reza = raschet(str2, A);
  }
  return x;
}
void trans_formul(char *str, int x) {
  int kol = 0;
  kol = strlen(str);
  for (int i = 0; i < kol; i++) {
    if (*((char *)str + i) == 120) {
      *((char *)str + i) = x;
    }
  }
}

int ident_formul(char *str) {
  int reza = 0;
  int kol = 0;
  kol = strlen(str);
  for (int i = 0; i < kol; i++) {
    //
    if (*((char *)str + i) == 120) {
      reza = 80;
      break;
    }
  }
  return reza;
}

double raschet(char *str, struct parser A[255]) {
  struct parser par[255];
  int t = 0;
  t = parser(str, par);
  perebor(par, t, A);
  int cikl = 0;
  for (int z = 0; z < t; z++) {
    if (A[z].priorite > 0) {
      cikl++;
    }
  }
  Spisok *ls = create(A);
  pereklad(ls, A, t);
  double reza = 0;
  for (int i = 0; i < cikl; i++) {
    reza = func(ls);
  }
  clining(ls);
  return reza;
}

void clining(Spisok *ls) {
  if (ls) {
    clining(ls->next);
    free(ls);
  }
}

void pereklad(Spisok *ls, struct parser A[255], int t) {
  for (int i = 0; i < t; i++) {
    add_element_end(ls, A, i);
  }
}
double func(Spisok *ls) {
  Spisok *ls2 = ls;
  while (ls != NULL) {
    if (ls->priorite > 0) {
      if (ls->znach_char == 43) {
        double b = int_b(ls2);
        double a = int_b(ls2);
        printf("\n+\n");
        ls->znach_int = a + b;
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 45) {
        double b = int_b(ls2);
        double a = int_b(ls2);
        printf("\n-\n");
        ls->znach_int = a - b;
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 42) {
        double b = int_b(ls2);
        double a = int_b(ls2);
        ls->znach_int = a * b;
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 47) {
        double b = int_b(ls2);
        double a = int_b(ls2);
        ls->znach_int = a + b;
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 77) {
        int b = int_b(ls2);
        int a = int_b(ls2);
        ls->znach_int = a % b;
        // int g = 4 % b;
        ls->priorite = 0;
        break;
      }

      else if (ls->znach_char == 94) {
        double b = int_b(ls2);
        double a = int_b(ls2);
        if (a < 0 && (int)b % 2 == 0) {
          a = a * -1;
        }
        ls->znach_int = pow(a, b);
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 81) {
        double b = int_b(ls2);
        ls->znach_int = sin(b);
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 82) {
        double b = int_b(ls2);
        printf("\ncos\n");
        ls->znach_int = cos(b);
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 83) {
        double b = int_b(ls2);
        ls->znach_int = tan(b);
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 84) {
        double b = int_b(ls2);
        ls->znach_int = acos(b);
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 85) {
        double b = int_b(ls2);
        ls->znach_int = asin(b);
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 86) {
        double b = int_b(ls2);
        ls->znach_int = atan(b);
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 87) {
        double b = int_b(ls2);
        ls->znach_int = sqrt(b);
        ls->priorite = 0;
        break;
      } else if (ls->znach_char == 88) {
        double b = int_b(ls2);
        ls->znach_int = log(b);
        ls->priorite = 0;
        break;
      } else {
        double b = int_b(ls2);
        ls->znach_int = log10(b);
        ls->priorite = 0;
        break;
      }
    }
    ls = ls->next;
  }
  return ls->znach_int;
}

double int_b(Spisok *ls) {
  Spisok *addres;
  Spisok *del;
  double b = 0;
  Spisok *ls2 = ls;
  while (ls != NULL) {
    if (ls->priorite > -1) {
      if (ls->priorite == 0) {
        b = ls->znach_int;
        del = ls;
        addres = ls->next;
      } else {
        break;
      }
    }
    ls = ls->next;
  }
  while (ls2 != NULL) {
    if (ls2->next == del) {
      free(del);
      ls2->next = addres;
    }
    ls2 = ls2->next;
  }

  return b;
}

Spisok *create() {
  Spisok *tmp = (Spisok *)malloc(sizeof(Spisok));
  tmp->priorite = -1;
  tmp->znach_char = 65;
  tmp->znach_int = 0;
  tmp->next = NULL;
  return (tmp);
}

void add_element_end(Spisok *head, struct parser A[255], int i) {
  Spisok *tmp = (Spisok *)malloc(sizeof(Spisok));
  tmp->priorite = A[i].priorite;
  tmp->znach_char = A[i].znach_char;
  tmp->znach_int = A[i].znach_int;
  tmp->next = NULL;
  Spisok *p = head;
  while (p->next != NULL) p = p->next;
  p->next = tmp;
}

int perebor(struct parser par[255], int t, struct parser A[255]) {
  struct parser B[255];
  for (int i = 0; i < 226; i++) {
    B[i].priorite = 0;
  }
  for (int i = 0; i < 226; i++) {
    A[i].priorite = -1;
  }
  int iA = 0;
  int iB = 0;
  // int flag = 0;
  int baff = 0;

  for (int j = 0; j < t; j++) {
    if (par[j].priorite == 0) {
      A[iA].priorite = par[j].priorite;
      A[iA].znach_int = par[j].znach_int;
      iA++;
    } else {
      if (iB - 1 > -1) {
        if ((par[j].priorite + baff > B[iB - 1].priorite &&
             par[j].priorite != 5)) {
          B[iB].priorite = par[j].priorite + baff;
          B[iB].znach_char = par[j].znach_char;
          iB++;
        } else if (par[j].priorite == 5) {
          if (par[j].znach_char == 40) {
            baff = baff + 10;
          }
          if (par[j].znach_char == 41) {
            baff = baff - 10;
          }

        } else {
          int corect = 0;
          for (int u = iB; u > 0; u--) {
            corect++;
            if (B[iB - 1].priorite > B[iB].priorite) {
              break;
            }
          }
          peregruz(A, B, iA, iB, corect);
          iA = iA + corect;
          iB = iB - corect;
          B[iB].priorite = par[j].priorite;
          B[iB].znach_char = par[j].znach_char;
          iB++;
        }
      } else {
        B[iB].priorite = par[j].priorite;
        B[iB].znach_char = par[j].znach_char;
        iB++;
      }
    }
  }

  peregruz(A, B, iA, iB, iB);

  return 0;
}

void peregruz(struct parser A[255], struct parser B[255], int iA, int iB,
              int corect) {
  int j = iB - 1;
  for (int i = iA; i < iA + corect; i++) {
    A[i].priorite = B[j].priorite;
    A[i].znach_char = B[j].znach_char;
    j--;
  }
}

int parser(char *str, struct parser par[255]) {
  int t = 0;
  int flag = 0;
  int kolvo_znak = strlen(str);
  for (int i = 0; i < kolvo_znak; i++) {
    if (*((char *)str + i) > 47 && *((char *)str + i) < 58 && flag == 0) {
      double x = atof(str + i);
      flag = 1;
      par[t].pp = i;
      par[t].priorite = 0;
      par[t].znach_int = x;
      t++;
    }
    if (*((char *)str + i) == 40) {
      par[t].pp = i;
      par[t].priorite = 5;
      par[t].znach_char = 40;
      flag = 0;
      t++;
    } else if (*((char *)str + i) == 41) {
      par[t].pp = i;
      par[t].priorite = 5;
      par[t].znach_char = 41;
      flag = 0;
      t++;
    } else if (*((char *)str + i) == 42) {
      par[t].pp = i;
      par[t].priorite = 2;
      par[t].znach_char = 42;
      flag = 0;
      t++;
    } else if (*((char *)str + i) == 43) {
      par[t].pp = i;
      par[t].priorite = 1;
      par[t].znach_char = 43;
      flag = 0;
      t++;
    } else if (*((char *)str + i) == 45) {
      par[t].pp = i;
      par[t].priorite = 1;
      par[t].znach_char = 45;
      flag = 0;
      t++;
    } else if (*((char *)str + i) == 47) {
      par[t].pp = i;
      par[t].priorite = 2;
      par[t].znach_char = 47;
      flag = 0;
      t++;
    } else if (*((char *)str + i) == 109) {
      par[t].pp = i;
      par[t].priorite = 2;
      par[t].znach_char = 77;
      flag = 0;
      t++;
    } else if (*((char *)str + i) == 94) {
      par[t].pp = i;
      par[t].priorite = 3;

      par[t].znach_char = 94;
      flag = 0;
      t++;
    } else if ((*((char *)str + i) == 115) && (*((char *)str + i + 1) == 105) &&
               (*((char *)str + i - 1) != 97)) {
      // sin
      par[t].pp = i;
      par[t].priorite = 4;

      par[t].znach_char = 81;
      flag = 0;
      t++;
    } else if ((*((char *)str + i) == 99) && (*((char *)str + i + 1) == 111) &&
               (*((char *)str + i - 1) != 97)) {
      // cos
      par[t].pp = i;
      par[t].priorite = 4;

      par[t].znach_char = 82;
      flag = 0;
      t++;
    } else if ((*((char *)str + i) == 116) && (*((char *)str + i + 1) == 97) &&
               (*((char *)str + i - 1) != 97)) {
      // tan
      par[t].pp = i;
      par[t].priorite = 4;

      par[t].znach_char = 83;
      flag = 0;
      t++;
    } else if ((*((char *)str + i) == 115) && (*((char *)str + i + 1) == 105) &&
               (*((char *)str + i - 1) == 97)) {
      // asin
      par[t].pp = i;
      par[t].priorite = 4;
      par[t].znach_char = 85;
      flag = 0;
      t++;
    } else if ((*((char *)str + i) == 99) && (*((char *)str + i + 1) == 111) &&
               (*((char *)str + i - 1) == 97)) {
      // acos
      par[t].pp = i;
      par[t].priorite = 4;
      par[t].znach_char = 84;
      flag = 0;
      t++;
    } else if ((*((char *)str + i) == 116) && (*((char *)str + i + 1) == 97) &&
               (*((char *)str + i - 1) == 97)) {
      // atan
      par[t].pp = i;
      par[t].priorite = 4;
      par[t].znach_char = 86;
      flag = 0;
      t++;
    } else if ((*((char *)str + i) == 115) && (*((char *)str + i + 1) == 113)) {
      // sqrt
      par[t].pp = i;
      par[t].priorite = 4;
      par[t].znach_char = 87;
      flag = 0;
      t++;
    } else if ((*((char *)str + i) == 108) && (*((char *)str + i + 1) == 110)) {
      // ln
      par[t].pp = i;
      par[t].priorite = 4;
      par[t].znach_char = 88;
      flag = 0;
      t++;
    } else if ((*((char *)str + i) == 108) && (*((char *)str + i + 1) == 111)) {
      // log
      par[t].pp = i;
      par[t].priorite = 4;
      par[t].znach_char = 89;
      flag = 0;
      t++;
    }
  }
  return t;
}

void null_treg_skob(char *str) {
  int kol = 0;
  // char dest[258];
  kol = strlen(str);
  // int flag = 0;
  for (int i = 0, j = 0; i < kol; i++, j++) {
    if ((*((char *)str + i) == 45) && (*((char *)str + i + 1) == 45)) {
      *((char *)str + i) = 43;
      *((char *)str + i + 1) = 43;
    }
    if ((*((char *)str + i) == 45) && (*((char *)str + i + 1) == 43)) {
      *((char *)str + i) = 45;
      *((char *)str + i + 1) = 45;
    }
  }
}

int dot_dot(char *str, int kolvo_znak) {
  int flag = 0;
  for (int i = 0; i < kolvo_znak; i++) {
    if (*((char *)str + i) == 46) {
      flag++;
    }
    if (flag == 2) {
      break;
    }
    if (*((char *)str + i) == 47 || *((char *)str + i) == 42 ||
        *((char *)str + i) == 43 || *((char *)str + i) == 45 ||
        *((char *)str + i) == 94) {
      flag = 0;
    }
  }
  if (flag == 1) {
    flag = 0;
  }
  return flag;
}

int number_skobka(char *str, int kolvo_znak) {
  int flag = 0;
  for (int i = 0; i < kolvo_znak; i++) {
    if (*((char *)str + i) == 40 &&
        (*((char *)str + i - 1) > 47 && *((char *)str + i - 1) < 58)) {
      flag = 9;
    }
  }
  return flag;
}
int dev_nul(char *str, int kolvo_znak) {
  int flag = 0;
  for (int i = 0; i < kolvo_znak; i++) {
    if (*((char *)str + i) == 47 &&
        (*((char *)str + i + 1) == 48 && *((char *)str + i + 2) != 46)) {
      flag = 8;
    }
  }
  return flag;
}

int validatir(char *str) {
  int error = 0;
  int kolvo_znak = strlen(str);
  dot(str, kolvo_znak);
  null_treg_skob(str);
  one_null(str);
  unar(str);
  skobka_unar(str);
  kolvo_znak = strlen(str);
  if (error == 0) {
    error = number_skobka(str, kolvo_znak);
  }
  if (error == 0) {
    error = dev_nul(str, kolvo_znak);
  }
  if (error == 0) {
    error = dot_dot(str, kolvo_znak);
  }
  if (error == 0) {
    error = valod_after_znk(str, kolvo_znak);
  }
  if (error == 0) {
    error = valod_after_uni(str, kolvo_znak);
    //ошика:sin-2, cos-3, tan-4, sq-5, ln-6, log -7
  }
  if (error == 0) {
    error = valod_skobki(str, kolvo_znak);
    //ошибка: 8
  }

  return error;
}
void one_null(char *str) {
  char dest[258] = "0+";
  strcat(dest, str);
  strcpy(str, dest);
}

int valod_skobki(char *str, int kolvo_znak) {
  //проверка на наличие ( и )
  int k = 0;
  for (int i = 0; i < kolvo_znak; i++) {
    if (*((char *)str + i) == 40) {
      k++;
    }
    if (k != 0 && *((char *)str + i) == 41) {
      k--;
    }
  }
  return k;
}

int valod_after_uni(char *str, int kolvo_znak) {  //провер
  struct trig st[6] = {{3, 115, 105, 2}, {3, 99, 111, 3},  {3, 116, 97, 4},
                       {4, 115, 113, 5}, {2, 108, 110, 6}, {3, 108, 111, 7}};

  int k = 0;
  for (int j = 0; j < 6 && k == 0; j++) {
    for (int i = 0; i < kolvo_znak; i++) {
      {
        if (*((char *)str + i) == st[j].letter1 &&
            *((char *)str + i + 1) == st[j].letter2) {
          if ((*((char *)str + i + st[j].bias) > 47 &&
               *((char *)str + i + st[j].bias) < 58) ||
              *((char *)str + i + st[j].bias) == 40) {
            k = 0;
          } else {
            k = st[j].err;
            break;
          }
        }
      }
    }
  }
  return k;
}

void dot(char *str, int kolvo_znak) {
  //замена запятой на точку
  for (int i = 0; i < kolvo_znak; i++) {
    if (*((char *)str + i) == 44) {
      *((char *)str + i) = 46;
    }
  }
}

void unar(char *str) {
  //обработка унарного оператора
  char dest[258];
  int j = 0;
  int kol = 0;
  kol = strlen(str);
  // printf("\n+++ %d\n", kol);
  for (int i = 0; i < kol; i++) {
    if ((*((char *)str + i) == 45 || *((char *)str + i) == 43) &&
        (*((char *)str + i + 1) == 45 || *((char *)str + i + 1) == 43)) {
      *((char *)dest + i + j) = *((char *)str + i);
      j++;
      *((char *)dest + i + j) = 48;
    } else {
      *((char *)dest + i + j) = *((char *)str + i);
    }
  }
  // printf("\n--- %s\n", dest);
  for (int i = 0; i < kol + j; i++) {
    *((char *)str + i) = *((char *)dest + i);
  }
}

void skobka_unar(char *str) {
  //унарник когда скобки
  char dest[258];
  int j = 0;
  int kol = 0;
  kol = strlen(str);
  for (int i = 0; i < kol; i++) {
    if ((*((char *)str + i) == 40) &&
        (*((char *)str + i + 1) == 45 || *((char *)str + i + 1) == 43)) {
      *((char *)dest + i + j) = *((char *)str + i);
      j++;
      *((char *)dest + i + j) = 48;
    } else {
      *((char *)dest + i + j) = *((char *)str + i);
    }
  }
  for (int i = 0; i < kol + j; i++) {
    *((char *)str + i) = *((char *)dest + i);
  }
}

int valod_after_znk(char *str, int kolvo_znak) {
  //  проверка на двойной знак (допускает трегонометрические символы)
  int k = 0;
  for (int i = 0; i < kolvo_znak; i++) {
    if (*((char *)str + i) > 41 && *((char *)str + i) < 48) {
      if (*((char *)str + i + 1) > 47 && *((char *)str + i + 1) < 58) {
        k = 0;
      } else if (*((char *)str + i + 1) == 108) {
        k = 0;
      } else if (*((char *)str + i + 1) == 116) {
        k = 0;
      } else if (*((char *)str + i + 1) == 97) {
        k = 0;
      } else if (*((char *)str + i + 1) == 99) {
        k = 0;
      } else if (*((char *)str + i + 1) == 115) {
        k = 0;
      } else if (*((char *)str + i + 1) == 40) {
        k = 0;
      } else {
        k = 1;
        break;
      }
    }
  }
  return k;
}
