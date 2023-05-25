
/**
 * @file plan.cpp
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/3     20:00
 *
 */
#include "planwindow.h"
#include "ui_planwindow.h"

extern QListWidgetItem *curRelative;

PlanWindow::PlanWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlanWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("返回");
    ui->label->setText("下次生日的日期：");
    ui->label_2->setText("剩余天数：");
//    ui->label_3->setText("天");
    ui->label_3->setText("提前后的日期为：");
    ui->label_6->setText("计划日期为：");

    ui->pushButton_2->setText("确认");
    ui->pushButton_3->setText("查看最终结果");
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    setWindowTitle("制定聚会计划");


}

PlanWindow::~PlanWindow()
{
    delete ui;
}

/*
    在计划阶段选择返回，重新输入当前日期。
*/
void PlanWindow::on_pushButton_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    QString item = curRelative->text();
    int fst_idx = item.indexOf('\t');
    int scd_idx = item.indexOf('\t',fst_idx+1);
    QString date_t = item.mid(scd_idx+1);
    QString date = date_t.split('\t').first();
    mainWindow->setBirthday(QDate::fromString(date,"yyyy-MM-dd"));
    mainWindow->setRelativeName(item.mid(0,fst_idx));
    mainWindow->show();
}


void PlanWindow::setText1(QString nb){
    ui->lineEdit->setText(nb);
}
void PlanWindow::setText2(QString days){
    ui->lineEdit_2->setText(days);
}
void PlanWindow::setText3(QString days){
    QString s("请输入0-");
    s.append(days);
    ui->lineEdit_3->setPlaceholderText(s);//背景提示用户输入范围
    QIntValidator* IntValidator = new QIntValidator;

    IntValidator->setRange(0, days.toInt());
    ui->lineEdit_3->setValidator(IntValidator);
}
void PlanWindow::on_pushButton_2_clicked()
{
//    qDebug()<<ui->lineEdit_2->text().toInt();
    if(ui->lineEdit_3->text().toInt()<0
            ||ui->lineEdit_3->text().toInt()>ui->lineEdit_2->text().toInt()){

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
        PlanWindow::PlanAdvanceDays=ui->lineEdit_3->text().toInt();
        PlanWindow::PlanDate=qd2;
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
        PlanWindow::PartyDate=qpd;
//        qDebug()<<d;
        ui->lineEdit_4->setText(qpd.toString("yyyy/MM/dd dddd"));
        ui->lineEdit_5->setText(qd2.toString("yyyy/MM/dd dddd"));
    }
}


void PlanWindow::on_pushButton_3_clicked()
{
    if(ui->lineEdit_4->text()==""){
         QMessageBox::warning(this, tr("提示！"),tr("还未得到计划日期"),"返回");
    }
    else{
        this->close();
        Result *R=new Result();
        R->Birthday=PlanWindow::Birthday;
        R->NextBirthday=PlanWindow::NextBirthday;
//        qDebug()<<R->NextBirthday;
        R->PlanAdvanceDays=PlanWindow::PlanAdvanceDays;
        R->DisDays=PlanWindow::DisDays;
        R->PlanDate=PlanWindow::PlanDate;
        R->CurrentDate=PlanWindow::CurrentDate;
        R->PartyDate=PlanWindow::PartyDate;
        R->setText1(PlanWindow::NextBirthday.toString("yyyy/MM/dd dddd"));
        QString ds=QString::number(PlanWindow::DisDays);
        R->setText2(ds);
        QString ad=QString::number(PlanWindow::PlanAdvanceDays);
        R->setText3(ad);
        R->setText4(PlanWindow::PlanDate.toString("yyyy/MM/dd dddd"));
        R->setText5(PlanWindow::PartyDate.toString("yyyy/MM/dd dddd"));
        R->show();
    }
//    QMessageBox::warning(this, tr("警告！"),tr("天数超出范围！"),"返回");
}
