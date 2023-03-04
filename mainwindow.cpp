#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(S21::Controller *controller, QWidget *parent) : QMainWindow(parent), controller(controller), ui(new Ui::MainWindow) {
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
  if (prohibition_duplication_bracket == false) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    prohibition_duplication_sign = false;
  }
}

void MainWindow::dot() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (prohibition_duplication_dot == false &&
      prohibition_duplication_sign == false) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    prohibition_duplication_sign = true;
    prohibition_duplication_dot = true;
  }
}

void MainWindow::bracket_up() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (prohibition_duplication_dot == false &&
      prohibition_duplication_sign == true) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    ++bracket;
    prohibition_duplication_sign = true;
  }
}

void MainWindow::bracket_don() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (prohibition_duplication_dot == false &&
      prohibition_duplication_sign == false && bracket > 0) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    --bracket;
    prohibition_duplication_bracket = true;
  }
}

void MainWindow::actions() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (prohibition_duplication_sign == false) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    prohibition_duplication_dot = false;
    prohibition_duplication_sign = true;
    prohibition_duplication_bracket = false;
  }
}

void MainWindow::sum_razn() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (prohibition_duplication_sign == false) {
    new_label = (ui->lineEdit->text() + button->text());
    ui->lineEdit->setText(new_label);
    prohibition_duplication_sign = true;
    prohibition_duplication_dot = false;
  } else {
    if (prohibition_duplication_dot == false) {
      new_label = (ui->lineEdit->text() + "(" + button->text());
      ui->lineEdit->setText(new_label);
    }
    ++bracket;
  }
  prohibition_duplication_bracket = false;
}

void MainWindow::triganmetr() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  if (prohibition_duplication_dot == false &&
      prohibition_duplication_sign == true) {
    new_label = (ui->lineEdit->text() + button->text() + "(");
    ui->lineEdit->setText(new_label);
    prohibition_duplication_sign = true;
    ++bracket;
    prohibition_duplication_dot = false;
    prohibition_duplication_bracket = false;
  }
}

void MainWindow::butten_x() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  new_label = (ui->lineEdit->text() + "(" + button->text() + ")");
  ui->lineEdit->setText(new_label);
  prohibition_duplication_sign = false;
  formula = true;
}

void MainWindow::on_Button_ac_clicked() {
  QString new_label;
  new_label = nullptr;
  ui->lineEdit->setText(new_label);
  prohibition_duplication_sign = true;
  prohibition_duplication_dot = false;
  prohibition_duplication_equality = false;
  prohibition_duplication_bracket = false;
  formula = false;
  bracket = 0;
}

void MainWindow::on_Button_funk_clicked() {
  QString new_label = (ui->lineEdit->text());
  if (bracket == false) {
      //prohibition_duplication_equality ==false
    if (prohibition_duplication_equality == false) {
      new_label = (ui->lineEdit->text() + "=");
      prohibition_duplication_equality = true;
    } else {
      new_label = (ui->lineEdit->text());
    }
    ui->lineEdit->setText(new_label);
    if (formula != false) {
      if (ui->checkBox_3->isChecked()) {
          std::cout << "Расчет с подстановкой Х" << std::endl;
          std::cout << new_label.toStdString() << std::endl;
        substitution_x( new_label);
      } else {
          std::cout << "Построение графика" << std::endl;
        build_graph( new_label);
      }
    } else {
        std::cout << "Расчет примера" << std::endl;
      double reza = controller->controller_calk( new_label.toStdString());
      ui->lineEdit_2->setText(QString::number(reza));
    }
  } else {
    ui->lineEdit_2->setText("ошибка ввода");
  }
}

void MainWindow::substitution_x( QString new_label) {
  std::vector<double> value_X;
  //S21::Controller controller;
  double new_x = (ui->substitution->text().toDouble());
  std::cout << "substitution " << new_label.toStdString() << std::endl;
  std::cout <<"substitution " << new_x << std::endl;
  std::vector<double> value_Y = controller->controller_formula(
      new_label.toStdString(), new_x, &value_X, 1);
  ui->lineEdit_2->setText(QString::number(value_Y[0]));
}

void MainWindow::build_graph(QString new_label) {
  std::vector<double> value_X;
  //S21::Controller controller;
  ui->widget->QCustomPlot ::clearGraphs();
  QVector<double> x, y;
  int mach_x = (ui->mach->text().toInt());
  ui->widget->xAxis->setRange(mach_x * -1, mach_x);
  ui->widget->yAxis->setRange(mach_x * -1, mach_x);
  std::vector<double> value_Y = controller->controller_formula(
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
