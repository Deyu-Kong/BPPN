
/**
 * @file welcome.cpp
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/3     20:00
 *
 */
#include "welcome.h"
#include "ui_welcome.h"


Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
//    ui->pushButton->setText("进入");
    ui->label->setText("欢迎使用本生日聚会计划便签");
    this->setAutoFillBackground(true);
    QPalette p=this->palette();
//    QPixmap *pix=new QPixmap(":/R-C.jpg");

    QPixmap pix(":/R-C.jpg");
    QPixmap temp(pix.size());
    temp.fill(Qt::transparent);
    QPainter pp(&temp);
    pp.setCompositionMode(QPainter::CompositionMode_Source);
    pp.drawPixmap(0,0,pix);
    pp.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    pp.fillRect(temp.rect(),QColor(0,0,0,150));//第四个参数为改透明度
    pp.end();
    pix=temp;
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    setWindowTitle("欢迎");
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::mousePressEvent(QMouseEvent *event){
    Welcome::~Welcome();
}

void Welcome::keyPressEvent(QKeyEvent *event){
    Welcome::~Welcome();
}

//void Welcome::on_pushButton_clicked()
//{
//    accept();
//}

