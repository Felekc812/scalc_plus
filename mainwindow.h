#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdio.h>
#include <stdlib.h>

#include <QDoubleValidator>
#include <QMainWindow>
#include <QScrollBar>
#include <QVector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "controller_start.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;

  int bracket = 0;
  bool prohibition_duplication_sign = true;
  bool prohibition_duplication_bracket = false;
  bool prohibition_duplication_dot = false;
  bool prohibition_duplication_equality = false;
  bool formula = false;

 private slots:
  void numbers();
  void triganmetr();
  void on_Button_ac_clicked();
  void actions();
  void on_Button_funk_clicked();
  void bracket_up();
  void bracket_don();
  void dot();
  void build_graph(QString new_label);
  void substitution_x(QString new_label);
  void sum_razn();
  void butten_x();

 signals:
  void signal();
};
#endif  // MAINWINDOW_H
