﻿#pragma execution_character_set("utf-8")
/**
 * @file end.cpp
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/4     9:00
 *
 */
#include "end.h"
#include "ui_end.h"

End::End(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::End)
{


    ui->setupUi(this);
    QMovie *movie=new QMovie(":/endgif.gif");
    movie->setScaledSize(QSize(150,150));
    movie->start();

    ui->gif->setMovie(movie);
    ui->gif->show();
//    movie->start();
    ui->pushButton->setText("退出");
    ui->label->setText("计划日期为");
    ui->lineEdit->setReadOnly(true);
    setWindowTitle("结束");
}
void End::setText1(QString fpd){
    ui->lineEdit->setText(fpd);
}

End::~End()
{
    delete ui;
}

void End::on_pushButton_clicked()
{
    close();
}

