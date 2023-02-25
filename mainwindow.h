  #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controller_start.h"
/*
#ifdef __cplusplus
extern "C" {
#endif

#include "p.h"
#ifdef __cplusplus
}
#endif
*/

#include <QMainWindow>
#include <QVector>
#include <QDoubleValidator>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <QScrollBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

private slots:
    void numbers();
    void triganmetr();
    void on_Button_ac_clicked();
    void actions();
    void on_Button_funk_clicked();
    void bracket_up();
    void bracket_don();
    void dot();
    /*void on_baton_cred_clicked();
    void on_pushButton_result_clicked();
    void scan_data();
    void calculate_deposit_without_cap();
    void calculate_deposit_with_cap();
    void clean_deposit_data();*/
    void sum_razn();
    void butten_x();

signals:
    void signal();
 };
#endif // MAINWINDOW_H
