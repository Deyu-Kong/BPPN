/**
 * @file planwindow.h
 * @author 孔德昱，杜忠璠
 * @date 2023/3/3     20:00
 * @brief
 */
#ifndef PLAN_H
#define PLAN_H

#include <QWidget>
#include "mainwindow.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDate>
#include<QDebug>
#include<QString>
#include<QListWidgetItem>
#include<method.h>
#include<result.h>
namespace Ui {
class PlanWindow;
}

class PlanWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PlanWindow(QWidget *parent = nullptr);
    ~PlanWindow();
    void setText1(QString nb);//设置下一个生日的日期
    void setText2(QString days);//设置天数
    void setText3(QString days);
    QDate Birthday;
    QDate CurrentDate;
    QDate NextBirthday;
    int DisDays;
    int PlanAdvanceDays;
    QDate PlanDate;
    QDate PartyDate;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::PlanWindow *ui;
};

#endif // PLAN_H
