
/**
 * @file result.cpp
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/4     9:00
 *
 */
#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    ui->pushButton->setText("重新制定计划");
    ui->pushButton_2->setText("结束");
    ui->label->setText("下次生日日期");
    ui->label_2->setText("还有");
    ui->label_3->setText("天过生日");
//    ui->lineEdit->setText(NextBirthday.toString("yyyy/MM/dd dddd"));
    ui->label_4->setText("希望提前");
    ui->label_5->setText("天过生日");
    ui->label_6->setText("此日期为");
    ui->label_7->setText("聚会计划制定日期为");
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    setWindowTitle("结果");


}

void Result::setText1(QString nb){
    ui->lineEdit->setText(nb);
}
void Result::setText2(QString disday){
    ui->lineEdit_2->setText(disday);
}
void Result::setText3(QString ad){
    ui->lineEdit_3->setText(ad);
}
void Result::setText4(QString pd){
    ui->lineEdit_4->setText(pd);
}
void Result::setText5(QString fpd){
    ui->lineEdit_5->setText(fpd);
}
Result::~Result()
{
    delete ui;
}

void Result::on_pushButton_clicked()
{
    this->close();
    PlanWindow *pla=new PlanWindow();
    pla->PlanAdvanceDays=Result::PlanAdvanceDays;
    pla->DisDays=Result::DisDays;
    pla->PlanDate=Result::PlanDate;
    pla->CurrentDate=Result::CurrentDate;
    pla->Birthday=Result::Birthday;
    pla->NextBirthday=Result::NextBirthday;
    pla->PartyDate=Result::PartyDate;
    pla->setText1(ui->lineEdit->text());
    pla->setText2(ui->lineEdit_2->text());
    pla->setText3(ui->lineEdit_2->text());
    pla->show();
}


void Result::on_pushButton_2_clicked()
{
    this->close();
    End *ed=new End();
    ed->setText1(ui->lineEdit_5->text());
    ed->show();
}

