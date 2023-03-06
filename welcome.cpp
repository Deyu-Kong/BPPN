#pragma execution_character_set("utf-8")
/**
 * @file welcome.cpp
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/3     20:00
 *
 */
#include "welcome.h"
#include "ui_welcome.h"


welcome::welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
//    ui->pushButton->setText("进入");
    ui->label->setText("欢迎使用本生日聚会计划便签");
    setWindowTitle("欢迎");
}

welcome::~welcome()
{
    delete ui;
}

void welcome::mousePressEvent(QMouseEvent *event){
    welcome::~welcome();
}

void welcome::keyPressEvent(QKeyEvent *event){
    welcome::~welcome();
}

//void welcome::on_pushButton_clicked()
//{
//    accept();
//}

