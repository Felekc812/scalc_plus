#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 250
#define MASS = 20;
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
typedef int T;
typedef int T2;

struct trig {
  int bias;
  int letter1;
  int letter2;
  int err;
};

struct parser {
  int pp;
  int priorite;
  double znach_int;
  char znach_char;
};

struct A {
  int priorite;
  double znach_int;
  char znach_char;
};

struct B {
  int priorite;
  double znach_int;
  char znach_char;
};

typedef struct Node {
  int priorite;
  double znach_int;
  char znach_char;
  struct Node *next;
} Spisok;

int validatir(char *str);
void dot(char *str, int kolvo_znak);
int valod_after_znk(char *str, int kolvo_znak);
int valod_after_uni(char *str, int kolvo_znak);
int valod_skobki(char *str, int kolvo_znak);
void one_null(char *str);
double raschet(char *str, struct parser A[255]);
int parser(char *str, struct parser par[255]);
int perebor(struct parser par[255], int t, struct parser A[255]);
void peregruz(struct parser A[255], struct parser B[255], int iA, int iB,
              int corect);
void print_peregruz(struct parser A[255], int iA, int iB);
double schet(struct parser A[255], int t);
Spisok *create();
void add_element_end(Spisok *head, struct parser A[255], int i);
double int_b(Spisok *ls);
void str_print(Spisok *ls);
double func(Spisok *ls);
void pereklad(Spisok *ls, struct parser A[255], int t);
void clining(Spisok *ls);
int calc(char *str, double *reza);
void unar(char *str);
void skobka_unar(char *str);
int ident_formul(char *str);
void trans_formul(char *str, int x);
int prov_form(char *str);
void null_treg_skob(char *str);
int dot_dot(char *str, int kolvo_znak);
int number_skobka(char *str, int kolvo_znak);
int dev_nul(char *str, int kolvo_znak);
int x_in_step(char *str);

#endif  // SRC_CALC_H_
