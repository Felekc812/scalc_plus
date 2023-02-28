#include "mainwindow.h"

#include "ui_mainwindow.h"

/*#define CONDITION_DEPO \
  d_sum >= 100 && d_procent >= 0 && d_month >= 1 && tax >= 0 && donat >= 0 && \
      every >= 0*/

// double d_sum;
// int d_month;
// double d_procent;
// double tax;
// double donat;
// int every;

int bracket = 0;
int flag = 1;
int flag_dot = 0;
int flag_rend = 0;
int formula = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->Button_0, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_1, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_2, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_3, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_4, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_5, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_6, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_7, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_8, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_9, SIGNAL(clicked()), this, SLOT(numbers()));

  connect(ui->Button_dot, SIGNAL(clicked()), this, SLOT(dot()));

  connect(ui->Button_x, SIGNAL(clicked()), this, SLOT(butten_x()));

  connect(ui->Button_skob_don, SIGNAL(clicked()), this, SLOT(bracket_don()));
  connect(ui->Button_skob_up, SIGNAL(clicked()), this, SLOT(bracket_up()));

  connect(ui->Button_min, SIGNAL(clicked()), this, SLOT(sum_razn()));
  connect(ui->Button_sum, SIGNAL(clicked()), this, SLOT(sum_razn()));

  connect(ui->Button_dil, SIGNAL(clicked()), this, SLOT(actions()));
  connect(ui->Button_mod, SIGNAL(clicked()), this, SLOT(actions()));
  connect(ui->Button_umn, SIGNAL(clicked()), this, SLOT(actions()));
  connect(ui->Button_step, SIGNAL(clicked()), this, SLOT(actions()));

  connect(ui->Button_acos, SIGNAL(clicked()), this, SLOT(triganmetr()));
  connect(ui->Button_asin, SIGNAL(clicked()), this, SLOT(triganmetr()));
  connect(ui->Button_atan, SIGNAL(clicked()), this, SLOT(triganmetr()));
  connect(ui->Button_cos, SIGNAL(clicked()), this, SLOT(triganmetr()));
  connect(ui->Button_ln, SIGNAL(clicked()), this, SLOT(triganmetr()));
  connect(ui->Button_log, SIGNAL(clicked()), this, SLOT(triganmetr()));
  connect(ui->Button_sin, SIGNAL(clicked()), this, SLOT(triganmetr()));
  connect(ui->Button_sprt, SIGNAL(clicked()), this, SLOT(triganmetr()));
  connect(ui->Button_tan, SIGNAL(clicked()), this, SLOT(triganmetr()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  // if (flag == 1) {
  new_label = (ui->lineEdit->text() + button->text());
  ui->lineEdit->setText(new_label);
  flag = 0;
  // flag_dot = 0;
  //}
}

void MainWindow::dot() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (flag_dot == 0 && flag == 0) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    flag = 1;
    flag_dot = 1;
  }
}

void MainWindow::bracket_up() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (flag_dot == 0) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    ++bracket;
    flag = 1;
  }
}

void MainWindow::bracket_don() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (flag_dot == 0 && flag == 0 && bracket > 0) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    --bracket;
    // flag = 0;
  }
}

void MainWindow::actions() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (flag == 0) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    flag_dot = 0;
    flag = 1;
  }
}
void MainWindow::sum_razn() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (flag == 0) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    flag = 1;
    flag_dot = 0;
  } else {
    if (flag_dot == 0) {
      new_label = (ui->lineEdit->text() + "(" + button->text());
      ui->lineEdit->setText(new_label);
    }
    ++bracket;
  }
}

void MainWindow::triganmetr() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (flag_dot == 0 && flag == 1) {
    new_label = (ui->lineEdit->text() + button->text() + "(");
    ui->lineEdit->setText(new_label);
    flag = 1;
    ++bracket;
    flag_dot = 0;
  }
}
void MainWindow::butten_x() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  new_label = (ui->lineEdit->text() + "(" + button->text() + ")");
  ui->lineEdit->setText(new_label);
  flag = 0;
  formula = 1;
}

void MainWindow::on_Button_ac_clicked() {
  QString new_label;
  new_label = nullptr;
  ui->lineEdit->setText(new_label);
  flag = 1;
  flag_dot = 0;
  flag_rend = 0;
}

void MainWindow::on_Button_funk_clicked() {
  // flag = 1;
  //// ресование Э=Э
  QString new_label;
  if (flag_rend == 0) {
    new_label = (ui->lineEdit->text() +
                 "");  ///////!!!!!!!!!!!!!!!!!!!!!! тут надо вернуть =
    flag_rend = 1;
  } else {
    new_label = (ui->lineEdit->text());
  }
  ui->lineEdit->setText(new_label);

  // QByteArray input = new_label.toLocal8Bit();
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ////финальный расчет*****
  printf(">>>>>>>>%d \n", formula);
  /// вычесление формулы
  if (formula != 0) {
    std::vector<double> value_X;
    S21::Controller controller;
    if (ui->checkBox_3->isChecked()) {
      /*// printf("Счек бокс активен");
      // formula = 0;
      double new_x = (ui->substitution->text().toDouble());
      std::vector<double> value_Y = controller.controller_formula(
          new_label.toStdString(), new_x, &value_X, 1);
      // printf(">>>>>>>>>>%f\n",value_Y[0]);
      ui->lineEdit_2->setText(QString::number(value_Y[0]));*/
      substitution_x(new_label);
    } else {
      build_graph(new_label);
    }
  }
  /////заканчиваеться вычесление формулы
  else {
    // double reza = 0;
    S21::Controller control;
    // printf("Старт расчета\n");
    // std::cout << new_label.toStdString() << "  формула \n";
    double reza = control.controller_calk(new_label.toStdString());
    ui->lineEdit_2->setText(QString::number(reza));
  }
  input.clear();
}

void MainWindow::substitution_x(QString new_label) {
  std::vector<double> value_X;
  S21::Controller controller;
  // printf("Счек бокс активен");
  // formula = 0;
  double new_x = (ui->substitution->text().toDouble());
  std::vector<double> value_Y = controller.controller_formula(
      new_label.toStdString(), new_x, &value_X, 1);
  // printf(">>>>>>>>>>%f\n",value_Y[0]);
  ui->lineEdit_2->setText(QString::number(value_Y[0]));
}

void MainWindow::build_graph(QString new_label) {
  std::vector<double> value_X;
  S21::Controller controller;
  ui->widget->QCustomPlot ::clearGraphs();
  //  double h, X;
  QVector<double> x, y;
  int mach_x = (ui->mach->text().toInt());
  ui->widget->xAxis->setRange(mach_x * -1, mach_x);
  ui->widget->yAxis->setRange(mach_x * -1, mach_x);
  // std::vector<double> value_X;
  std::vector<double> value_Y = controller.controller_formula(
      new_label.toStdString(), mach_x, &value_X, 0);
  for (size_t i = 0; i < value_Y.size(); ++i) {
    x.push_back(value_X[i]);
    y.push_back(value_Y[i]);
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");
  x.clear();
  y.clear();
  x.squeeze();
  y.squeeze();
  ui->widget->replot();
  ui->lineEdit_2->setText("formula");
}
