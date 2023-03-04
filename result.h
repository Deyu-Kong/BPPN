#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include<QMessageBox>
#include<plan.h>
#include<end.h>
namespace Ui {
class Result;
}

class Result : public QWidget
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();
    QDate Birthday;
    QDate CurrentDate;
    QDate NextBirthday;
    int DisDays;
    int PlanAdvanceDays;
    QDate PlanDate;
    QDate PartyDate;
    void setText1(QString nb);
    void setText2(QString disday);
    void setText3(QString ad);
    void setText4(QString pd);
    void setText5(QString fpd);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Result *ui;
};

#endif // RESULT_H
