#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "p.h"

START_TEST(calc_2) {
  char str[100] = "sin(21+23+99)=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = -0.99834536087;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_4) {
  char str[100] = "15-sin(5+2)=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 14.3430134013;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_5) {
  char str[100] = "15++26=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 41;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_6) {
  char str[100] = "15+26+sin+2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 2);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_7) {
  char str[100] = "15+acossin26+sin2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 3);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_8) {
  char str[100] = "15+asin26+tansin2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 4);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_9) {
  char str[100] = "15+cos26+sqrt+2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 5);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_10) {
  char str[100] = "15+cos26+ln+2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 6);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_11) {
  char str[100] = "15+cos26+log+2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 7);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_12) {
  char str[100] = "15+cos26+log+2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 7);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_13) {
  char str[100] = "5+cos3=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 4.0100075034;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_14) {
  char str[100] = "5+tan3=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 4.857453456926;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_16) {
  char str[100] = "5+acos0.3=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 6.2661036727795;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_17) {
  char str[100] = "5+sqrt3=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 6.7320508075688773;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_18) {
  char str[100] = "5+ln3=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 6.09861228866811;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_20) {
  char str[100] = "1+(1-6)+5=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 1;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_21) {
  char str[100] = "(5-6)+5=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 4;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_21_1) {
  char str[100] = "(-6)+5=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = -1;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_21_2) {
  char str[100] = "-6+5=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = -1;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_22) {
  char str[100] = "1-(6+2)*10=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = -79;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_23) {
  char str[100] = "10*(6+2)=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 80;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_24) {
  char str[100] = "(5+2)*10+(6+8)*10=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 210;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_25) {
  char str[100] = "5mod2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 1;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_27) {
  char str[100] = "10*(0.6+0.4)=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 10;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_28) {
  char str[100] = "5.2+3.1=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 8.3;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_29) {
  char str[100] = "5+x+3=";
  int reza = 0;
  reza = prov_form(str);
  int res = 3;
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_30) {
  char str[100] = "5-+5=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST
START_TEST(calc_31) {
  char str[100] = "5--5=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 10;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_32) {
  char str[100] = "5++5=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 10;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_33) {
  char str[100] = "5+-5=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_34) {
  char str[100] = "5.5.3+3.3=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 2);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_35) {
  char str[100] = "5(3+2)=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 9);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_36) {
  char str[100] = "5--5=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 10;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_37) {
  char str[100] = "5/0+1=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 8);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_38) {
  char str[100] = "5/0=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0;
  ck_assert_float_eq(err, 8);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_39) {
  char str[100] = "x^2=";
  int reza = 0;
  reza = x_in_step(str);
  double res = 1;
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_40) {
  char str[100] = "x^3=";
  int reza = 0;
  reza = x_in_step(str);
  double res = 0;
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_41) {
  char str[100] = "(-1)^2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 1;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_42) {
  char str[100] = "2^(-2)=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 0.25;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_43) {
  char str[100] = "(-2)^3=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = -8;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_44) {
  char str[100] = "(-2)^2=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 4;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

START_TEST(calc_45) {
  char str[100] = "(-2)^2*3=";
  double reza = 0;
  int err = calc(str, &reza);
  double res = 12;
  ck_assert_float_eq(err, 0);
  ck_assert_float_eq(reza, res);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_calc");
  TCase *s21_calc_test = tcase_create("s21_calc_comparativeTest");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, s21_calc_test);

  tcase_add_test(s21_calc_test, calc_2);

  tcase_add_test(s21_calc_test, calc_4);
  tcase_add_test(s21_calc_test, calc_5);
  tcase_add_test(s21_calc_test, calc_6);
  tcase_add_test(s21_calc_test, calc_7);
  tcase_add_test(s21_calc_test, calc_8);
  tcase_add_test(s21_calc_test, calc_9);
  tcase_add_test(s21_calc_test, calc_10);
  tcase_add_test(s21_calc_test, calc_11);
  tcase_add_test(s21_calc_test, calc_12);
  tcase_add_test(s21_calc_test, calc_13);
  tcase_add_test(s21_calc_test, calc_14);
  tcase_add_test(s21_calc_test, calc_16);
  tcase_add_test(s21_calc_test, calc_17);
  tcase_add_test(s21_calc_test, calc_18);
  tcase_add_test(s21_calc_test, calc_20);
  tcase_add_test(s21_calc_test, calc_21);
  tcase_add_test(s21_calc_test, calc_21_1);
  tcase_add_test(s21_calc_test, calc_21_2);
  tcase_add_test(s21_calc_test, calc_22);
  tcase_add_test(s21_calc_test, calc_23);
  tcase_add_test(s21_calc_test, calc_24);
  tcase_add_test(s21_calc_test, calc_25);
  tcase_add_test(s21_calc_test, calc_27);
  tcase_add_test(s21_calc_test, calc_28);
  tcase_add_test(s21_calc_test, calc_29);
  tcase_add_test(s21_calc_test, calc_30);
  tcase_add_test(s21_calc_test, calc_31);
  tcase_add_test(s21_calc_test, calc_32);
  tcase_add_test(s21_calc_test, calc_33);
  tcase_add_test(s21_calc_test, calc_34);
  tcase_add_test(s21_calc_test, calc_35);
  tcase_add_test(s21_calc_test, calc_36);
  tcase_add_test(s21_calc_test, calc_37);
  tcase_add_test(s21_calc_test, calc_38);
  tcase_add_test(s21_calc_test, calc_39);
  tcase_add_test(s21_calc_test, calc_40);
  tcase_add_test(s21_calc_test, calc_42);
  tcase_add_test(s21_calc_test, calc_43);
  tcase_add_test(s21_calc_test, calc_44);

  tcase_add_test(s21_calc_test, calc_45);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
