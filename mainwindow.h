/**
 * @file mainwindow.h
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/3     20:00
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDate>
#include<QString>
#include<QDebug>
#include<method.h>
#include <QMainWindow>
#include<plan.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *getUi();
    void afterInput();
    QDate Birthday;
    QDate CurrentDate;
    QDate NextBirthday;
    bool eventFilter(QObject *obj, QEvent *event);
    int DisDays;
//    int PlanAdvanceDays;
//    QDate PlanDate;
//    QDate PartyDate;

private slots:
    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_2_userDateChanged(const QDate &date);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
