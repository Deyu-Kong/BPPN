
/**
 * @file mainwindow.cpp
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/3     20:00
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("您的生日日期：");
    ui->label_2->setText("当前日期：");
//    ui->dateEdit->setMinimumDate(QDate::currentDate().addDays(-365*120));
//    ui->dateEdit->setMaximumDate(QDate::currentDate());
//    ui->dateEdit->setFocus();
    ui->dateEdit_2->setDate(QDate::currentDate());
//    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit_2->setCalendarPopup(true);
    ui->label_3->setText("距离您的生日还有：");
//    ui->birthday->setText(this->Birthday.toString());
//    ui->label_4->setText("天过生日");
//    int byear=ui->dateEdit->date().year();
//    int bmonth=ui->dateEdit->date().month();
//    int bday=ui->dateEdit->date().day();
    int cyear=ui->dateEdit_2->date().year();
    int cmonth=ui->dateEdit_2->date().month();
    int cday=ui->dateEdit_2->date().day();
//    MyDate date1(byear,bmonth,bday);
    MyDate date1(this->Birthday.year(),this->Birthday.month(),this->Birthday.day());
    MyDate date2(cyear,cmonth,cday);
    getNextBirthday(date2,date1);
    int nyear=date1.year;
    int nmonth=date1.month;
    int nday=date1.day;
    QDate nextBirthday(nyear,nmonth,nday);
//    qDebug()<<nyear<<" "<<nmonth<<" "<<nday;
    int days=ui->dateEdit_2->date().daysTo(nextBirthday);
    QString ds=QString::number(days);
    ui->lineEdit->setText(ds);
    QString nB = nextBirthday.toString("yyyy/MM/dd dddd");
    ui->label_5->setText("下次生日的日期");
    ui->lineEdit_2->setText(nB);
//    QString dateChoice = ui->dateEdit->date().toString("yyyy-MM-dd dddd");
//    qDebug()<<dateChoice;
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    setWindowTitle("生日聚会计划便签");
    ui->label_6->setVisible(0);
    ui->lineEdit->setVisible(0);
    ui->lineEdit_2->setVisible(0);
    ui->label_3->setVisible(0);
    ui->label_5->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
//    int byear=ui->dateEdit->date().year();
//    int bmonth=ui->dateEdit->date().month();
//    int bday=ui->dateEdit->date().day();
//    MainWindow::Birthday=ui->dateEdit->date();
    int cyear=ui->dateEdit_2->date().year();
    int cmonth=ui->dateEdit_2->date().month();
    int cday=ui->dateEdit_2->date().day();
    MainWindow::CurrentDate=ui->dateEdit_2->date();
//    MyDate date1(byear,bmonth,bday);
    MyDate date1(this->Birthday.year(),this->Birthday.month(),this->Birthday.day());
    MyDate date2(cyear,cmonth,cday);
    getNextBirthday(date2,date1);
    int nyear=date1.year;
    int nmonth=date1.month;
    int nday=date1.day;
    QDate nextBirthday(nyear,nmonth,nday);
    MainWindow::NextBirthday=nextBirthday;
    int days=ui->dateEdit_2->date().daysTo(nextBirthday);
    QString ds=QString::number(days);
    MainWindow::DisDays=days;
    ui->lineEdit->setText(ds);
    QString nB = nextBirthday.toString("yyyy/MM/dd dddd");
    ui->lineEdit_2->setText(nB);
}


void MainWindow::on_dateEdit_2_userDateChanged(const QDate &date)
{
//    int byear=ui->dateEdit->date().year();
//    int bmonth=ui->dateEdit->date().month();
//    int bday=ui->dateEdit->date().day();
//    MainWindow::Birthday=ui->dateEdit->date();
    int cyear=ui->dateEdit_2->date().year();
    int cmonth=ui->dateEdit_2->date().month();
    int cday=ui->dateEdit_2->date().day();
    MainWindow::CurrentDate=ui->dateEdit_2->date();
//    MyDate date1(byear,bmonth,bday);
    MyDate date1(this->Birthday.year(),this->Birthday.month(),this->Birthday.day());
    MyDate date2(cyear,cmonth,cday);
    getNextBirthday(date2,date1);
    int nyear=date1.year;
    int nmonth=date1.month;
    int nday=date1.day;
    QDate nextBirthday(nyear,nmonth,nday);
    MainWindow::NextBirthday=nextBirthday;
    int days=ui->dateEdit_2->date().daysTo(nextBirthday);
    MainWindow::DisDays=days;
    QString ds=QString::number(days);
    ui->lineEdit->setText(ds);
    QString nB = nextBirthday.toString("yyyy/MM/dd dddd");
    ui->lineEdit_2->setText(nB);
}


void MainWindow::afterInput()
{
    this->close();
    Plan *pl=new Plan();
    pl->Birthday=MainWindow::Birthday;
    pl->NextBirthday=MainWindow::NextBirthday;
    pl->CurrentDate=MainWindow::CurrentDate;
    pl->DisDays=MainWindow::DisDays;
    pl->show();
    pl->setText1(ui->lineEdit_2->text());
    pl->setText2(ui->lineEdit->text());
    pl->setText3(ui->lineEdit->text());

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label_6->setVisible(1);
    ui->lineEdit->setVisible(1);
    ui->lineEdit_2->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_5->setVisible(1);
    ui->centralwidget->installEventFilter(this);
}

void MainWindow::setBirthday(QDate birthday){
    this->Birthday = birthday;
    ui->birthday->setText(this->Birthday.toString());
//    ui->birthday->setText("你好");
}

Ui::MainWindow *MainWindow::getUi(){
    return ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event){
//    qDebug()<<"Now is at eventFilter";
    if (event->type() == QEvent::KeyPress||event->type() == QEvent::MouseButtonPress)
    {
        afterInput();
        return true;
    }

    return QObject::eventFilter(obj, event);
}
