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
  //if (flag == 1) {
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
  QString new_label;
  if (flag_rend == 0) {
    new_label = (ui->lineEdit->text() +
                 "");  ///////!!!!!!!!!!!!!!!!!!!!!! тут надо вернуть =
    flag_rend = 1;
  } else {
    new_label = (ui->lineEdit->text());
  }
  ui->lineEdit->setText(new_label);

  QByteArray input = new_label.toLocal8Bit();
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ////финальный расчет*****
  printf(">>>>>>>>%d \n", formula);
  /// вычесление формулы
  if (formula != 0) {
    std::vector<double> value_X;
    S21::Controller controller;
    if (ui->checkBox_3->isChecked()) {
     // printf("Счек бокс активен");
      // formula = 0;
      double new_x = (ui->substitution->text().toDouble());
      std::vector<double> value_Y = controller.controller_formula(
          new_label.toStdString(), new_x, &value_X, 1);
      //printf(">>>>>>>>>>%f\n",value_Y[0]);
      ui->lineEdit_2->setText(QString::number(value_Y[0]));
    } else {
build_graph(new_label);
    }
  }
  /////заканчиваеться вычесление формулы
  else {
    double reza = 0;
    S21::Controller control;
    //printf("Старт расчета\n");
   // std::cout << new_label.toStdString() << "  формула \n";
    reza = control.controller_calk(new_label.toStdString());
    ui->lineEdit_2->setText(QString::number(reza));
  }
  input.clear();
}

void MainWindow::build_graph (QString new_label) {
    std::vector<double> value_X;
    S21::Controller controller;
    ui->widget->QCustomPlot ::clearGraphs();
  //  double h, X;
    QVector<double> x, y;
    int mach_x = (ui->mach->text().toInt());
    ui->widget->xAxis->setRange(mach_x * -1, mach_x);
    ui->widget->yAxis->setRange(mach_x*-1, mach_x);
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

/*
void MainWindow::on_baton_cred_clicked() {
  double platesh_manf = 0;
  double all_platesh = 0;
  double pereplata = 0;
  double summ_kred = ui->summ_kred->text().toDouble();
  double manf = ui->manf->text().toDouble();
  double procent = ui->procent->text().toDouble();
  double baf2;

  if (ui->checkBox->isChecked()) {
    // printf("расчет креда ануитентно");
    platesh_manf = summ_kred * (procent / (12 * 100)) /
                   (1 - pow(1 + procent / (12 * 100), -manf));
    all_platesh = platesh_manf * manf;
    pereplata = all_platesh - summ_kred;
  }
  if (ui->checkBox_2->isChecked()) {
    double baf = summ_kred;
    platesh_manf = summ_kred / manf + summ_kred * procent / (12 * 100);
    all_platesh = platesh_manf;
    baf -= summ_kred / manf;
    for (int i = 1; i < manf; i++) {
      baf2 = baf / (manf - i) + baf * procent / (12 * 100);
      // printf(">>>>>>>> %f", baf2);
      all_platesh += baf2;
      baf -= summ_kred / manf;
    }
    pereplata = all_platesh - summ_kred;
  }
  if (platesh_manf < 0 || all_platesh < 0 || pereplata < 0) {
    ui->platesh_manf->setText("Упс отрицательный ответ");
    ui->all_platesh->setText("Упс отрицательный ответ");
    ui->pereplaa->setText("Упс отрицательный ответ");
  } else {
    if (ui->checkBox->isChecked()) {
      ui->platesh_manf->setText(QString::number(platesh_manf));
    }
    if (ui->checkBox_2->isChecked()) {
      ui->platesh_manf->setText(QString::number(platesh_manf) + "..." +
                                QString::number(baf2));
    }

    ui->all_platesh->setText(QString::number(all_platesh));
    ui->pereplaa->setText(QString::number(pereplata));
  }

  if ((ui->checkBox_2->isChecked()) && (ui->checkBox->isChecked()) ||
      !(ui->checkBox_2->isChecked()) && !(ui->checkBox->isChecked())) {
    ui->platesh_manf->setText("ошибка типа креда");
    ui->all_platesh->setText("ошибка типа креда");
    ui->pereplaa->setText("ошибка типа креда");
  }
}

void MainWindow::on_pushButton_result_clicked() {
  scan_data();
  if (CONDITION_DEPO) {
    if (ui->capital_proc->isChecked()) {
      calculate_deposit_with_cap();
      clean_deposit_data();
    } else {
      calculate_deposit_without_cap();
      clean_deposit_data();
    }
  } else {
    ui->out_all_sum->setText("(некорректны)");
    ui->out_all_tax->setText("(данные)");
    ui->out_salary_proc->setText("(введенные)");
  }
}

void MainWindow::scan_data() {
  d_sum = ui->input_sum->text().toDouble();
  d_month = ui->input_month->text().toInt();
  d_procent = ui->input_procent->text().toDouble();
  tax = ui->input_tax->text().toDouble();
  donat = ui->input_donat->text().toDouble();
  every = ui->input_every_month->text().toInt();
}

void MainWindow::calculate_deposit_without_cap() {
  double all_dividents = 0;
  for (int i = 0; i < d_month; i++) {
    all_dividents += d_sum * d_procent / 100 / 12;
    if (every != 0)
      if (i % every == 0) {
        d_sum += donat;
      }
  }
  d_sum = round(d_sum + all_dividents);
  double all_tax_money = round(all_dividents * tax / 100);
  all_dividents = round(all_dividents);
  ui->out_all_sum->setText(QString::number(d_sum));
  ui->out_all_tax->setText(QString::number(all_tax_money));
  ui->out_salary_proc->setText(QString::number(all_dividents));
}

void MainWindow::calculate_deposit_with_cap() {
  double sum_start = d_sum;
  for (int i = 0; i < d_month; i++) {
    double dividents_month = d_sum * d_procent / 100 / 12;
    d_sum += dividents_month;
    if (every != 0)
      if (i % every == 0) {
        d_sum += donat;
        sum_start += donat;
      }
  }
  d_sum = round(d_sum);
  double all_dividents = round(d_sum - sum_start);
  double all_tax_money = round(all_dividents * tax / 100);

  ui->out_all_sum->setText(QString::number(d_sum));
  ui->out_all_tax->setText(QString::number(all_tax_money));
  ui->out_salary_proc->setText(QString::number(all_dividents));
}

void MainWindow::clean_deposit_data() {
  d_sum = 0;
  d_month = 0;
  d_procent = 0;
  tax = 0;
  every = 0;
  donat = 0;
}
*/
