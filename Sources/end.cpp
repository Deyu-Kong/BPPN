
/**
 * @file end.cpp
 * @author 杜忠璠
 * @date 2023/3/4     9:00
 * @brief 实现结束界面
 */
#include "end.h"
#include "ui_end.h"

/**
 * @brief End类的构造函数，用于初始化显示的内容
 * @param parent 父窗口
 */
End::End(QWidget *parent) : QWidget(parent),
                            ui(new Ui::End)
{
    ui->setupUi(this);
    QMovie *movie = new QMovie(":/endgif.gif");
    movie->setScaledSize(QSize(150, 150));
    movie->start();

    ui->gif->setMovie(movie);
    ui->gif->show();
    //    movie->start();
    ui->label->setText("计划日期为");
    ui->lineEdit->setReadOnly(true);
    setWindowTitle("结束");
}
/**
 * @brief 将计划日期传递到结束界面,并显示
 * @param fpd 计划日期
 */
void End::setText1(QString fpd)
{
    ui->lineEdit->setText(fpd);
}
/**
 * @brief End类的析构函数，用于关闭窗口
 */
End::~End()
{
    delete ui;
}
/**
 * @brief 在点击确认后执行，用于关闭结束界面
 */
void End::on_pushButton_clicked()
{
    close();
}
/**
 * @brief 在鼠标点击后执行，用于关闭结束界面
 */
void End::mousePressEvent(QMouseEvent *event)
{
    close();
}
/**
 * @brief 在点击键盘后执行，用于关闭结束界面
 */
void End::keyPressEvent(QKeyEvent *event)
{
    close();
}
