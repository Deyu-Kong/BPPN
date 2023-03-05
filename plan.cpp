#pragma execution_character_set("utf-8")
/**
 * @file plan.cpp
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/3     20:00
 *
 */
#include "plan.h"
#include "ui_plan.h"

Plan::Plan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plan)
{
    ui->setupUi(this);
    ui->pushButton->setText("返回");
    ui->label->setText("下次生日的日期");
    ui->label_2->setText("还有");
    ui->label_3->setText("天");
    ui->label_6->setText("计划日期为");

    ui->pushButton_2->setText("确认");
    ui->pushButton_3->setText("查看最终结果");
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    setWindowTitle("制定聚会计划");


}

Plan::~Plan()
{
    delete ui;
}

void Plan::on_pushButton_clicked()
{
    this->close();
    MainWindow *m=new MainWindow();
    m->show();
}
void Plan::setText1(QString nb){
    ui->lineEdit->setText(nb);
}
void Plan::setText2(QString days){
    ui->lineEdit_2->setText(days);
}
void Plan::setText3(QString days){
    QString s("请输入1-");
    s.append(days);
    ui->lineEdit_3->setPlaceholderText(s);//背景提示用户输入范围
    QIntValidator* IntValidator = new QIntValidator;

    IntValidator->setRange(1, days.toInt());
    ui->lineEdit_3->setValidator(IntValidator);
}
void Plan::on_pushButton_2_clicked()
{   qDebug()<<ui->lineEdit_2->text().toInt();
    if(ui->lineEdit_3->text().toInt()<1||ui->lineEdit_3->text().toInt()>ui->lineEdit_2->text().toInt()){

        QMessageBox::warning(this, tr("警告！"),tr("天数超出范围！"),"返回");
    }
    else{

        QString s=ui->lineEdit->text();

        int year=s.mid(0,4).toInt();
        int month=s.mid(5,2).toInt();
        int day=s.mid(8,2).toInt();
//        qDebug()<<ui->lineEdit->text()[0];
        QDate d(year,month,day);

        MyDate d1(year,month,day);
        MyDate d2=getAdvancedDate(d1,ui->lineEdit_3->text().toInt());
        QDate qd2(d2.year,d2.month,d2.day);
        Plan::PlanAdvanceDays=ui->lineEdit_3->text().toInt();
        Plan::PlanDate=qd2;
//        int pyear=d2.year;
//        int pmonth=d2.month;
//        int pday=d2.day;
        CaculateWeekDay(d2);
//        d2.week=d2.week+1;

        if(d2.week<5){
             QMessageBox::warning(this, tr("提示！"),tr("此日期是工作日，已为您自动调整到最近的周六"),"返回");

        }
        MyDate pd=plan2party(d2);
        int qpyear=pd.year;
        int qpmonth=pd.month;
        int qpday=pd.day;
        QDate qpd(qpyear,qpmonth,qpday);
        Plan::PartyDate=qpd;
//        qDebug()<<d;
        ui->lineEdit_4->setText(qpd.toString("yyyy/MM/dd"));
    }
}


void Plan::on_pushButton_3_clicked()
{
    if(ui->lineEdit_4->text()==""){
         QMessageBox::warning(this, tr("提示！"),tr("还未得到计划日期"),"返回");
    }
    else{
        this->close();
        Result *R=new Result();
        R->Birthday=Plan::Birthday;
        R->NextBirthday=Plan::NextBirthday;
//        qDebug()<<R->NextBirthday;
        R->PlanAdvanceDays=Plan::PlanAdvanceDays;
        R->DisDays=Plan::DisDays;
        R->PlanDate=Plan::PlanDate;
        R->CurrentDate=Plan::CurrentDate;
        R->PartyDate=Plan::PartyDate;
        R->setText1(Plan::NextBirthday.toString("yyyy/MM/dd"));
        QString ds=QString::number(Plan::DisDays);
        R->setText2(ds);
        QString ad=QString::number(Plan::PlanAdvanceDays);
        R->setText3(ad);
        R->setText4(Plan::PlanDate.toString("yyyy/MM/dd"));
        R->setText5(Plan::PartyDate.toString("yyyy/MM/dd"));
        R->show();
    }
//    QMessageBox::warning(this, tr("警告！"),tr("天数超出范围！"),"返回");
}

