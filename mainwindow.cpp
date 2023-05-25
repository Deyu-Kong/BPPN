
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
//    ui->label_2->setText("当前日期：");
    ui->dateEdit_2->setDate(QDate::currentDate());
//    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit_2->setCalendarPopup(true);
    ui->label_3->setText("距离您的生日还有：");
    this->CurrentDate = ui->dateEdit_2->date();

    ui->label_5->setText("下次生日的日期");
    ui->daysDistance->setReadOnly(true);
    ui->nextBirthdayLabel->setReadOnly(true);
    setWindowTitle("生日聚会计划便签");
    ui->label_6->setVisible(0);
    ui->daysDistance->setVisible(0);
    ui->nextBirthdayLabel->setVisible(0);
    ui->label_3->setVisible(0);
    ui->label_5->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dateEdit_2_userDateChanged(const QDate &date)
{
    this -> CurrentDate = date;
    this -> NextBirthday = getNextBirthday(this->CurrentDate,this->Birthday);
    int days=ui->dateEdit_2->date().daysTo(this->NextBirthday);
    this->DisDays=days;
    QString ds=QString::number(days);
    ui->daysDistance->setText(ds);
    QString nextBirthdayString = this->NextBirthday.toString("yyyy/MM/dd dddd");
    ui->nextBirthdayLabel->setText(nextBirthdayString);
}


void MainWindow::afterInput()
{
    this->close();
    PlanWindow *pl=new PlanWindow();
    pl->Birthday=MainWindow::Birthday;
    pl->NextBirthday=MainWindow::NextBirthday;
    pl->CurrentDate=MainWindow::CurrentDate;
    pl->DisDays=MainWindow::DisDays;
    pl->show();
    pl->setText1(ui->nextBirthdayLabel->text());
    pl->setText2(ui->daysDistance->text());
    pl->setText3(ui->daysDistance->text());

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label_6->setVisible(1);
    ui->daysDistance->setVisible(1);
    ui->nextBirthdayLabel->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_5->setVisible(1);
    ui->centralwidget->installEventFilter(this);
}


/*
 * 设置当前亲友的生日
 **/
void MainWindow::setBirthday(QDate birthday){
    // 设置生日
    this->Birthday = birthday;
    ui->birthday->setText(this->Birthday.toString("yyyy-MM-dd"));
    // 设置下一次生日
    this->NextBirthday = getNextBirthday(this->CurrentDate,this->Birthday);
    int days=this->CurrentDate.daysTo(this->NextBirthday);
    QString ds=QString::number(days);
    ui->daysDistance->setText(ds);
    QString nextBirthdayString = this->NextBirthday.toString("yyyy/MM/dd dddd");
    ui->nextBirthdayLabel->setText(nextBirthdayString);
}

void MainWindow::setRelativeName(QString name){
    this->relativeName = name;
    ui->label->setText(this->relativeName+"的生日日期：");
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
