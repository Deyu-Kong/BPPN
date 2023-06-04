
/**
 * @file result.cpp
 * @author 杜忠璠
 * @date 2023/5/28
 * @brief 实现结果界面
 */
#include "result.h"
#include "ui_result.h"

/**
 * @brief Result类的构造函数，用于初始化显示的内容
 * @param parent 父窗口 默认为nullptr
 */
Result::Result(QWidget *parent) : QWidget(parent),
                                  ui(new Ui::Result)
{
    ui->setupUi(this);
    ui->pushButton_2->setText("确定");
    ui->label->setText("下次生日日期");
    ui->label_2->setText("还有");
    ui->label_3->setText("天过生日");
    ui->label_4->setText("希望提前");
    ui->label_5->setText("天过生日");
    ui->label_6->setText("此日期为");
    ui->label_7->setText("聚会计划制定日期为");
    ui->lineEdit->setReadOnly(true); // 设置为只读
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    setWindowTitle("结果");
}

/**
 * @brief 显示下一个生日日期
 * @param nb 下一个生日日期
 */
void Result::setText1(QString nb)
{
    ui->lineEdit->setText(nb);
}

/**
 * @brief 显示距离天数
 * @param disday 距离天数
 */
void Result::setText2(QString disday)
{
    ui->lineEdit_2->setText(disday);
}

/**
 * @brief 显示提前天数
 * @param ad 提前天数
 */
void Result::setText3(QString ad)
{
    ui->lineEdit_3->setText(ad);
}

/**
 * @brief 显示计划日期
 * @param pd 计划日期
 */
void Result::setText4(QString pd)
{
    ui->lineEdit_4->setText(pd);
}

/**
 * @brief 显示最终聚会日期
 * @param fpd 最终聚会日期
 */
void Result::setText5(QString fpd)
{
    ui->lineEdit_5->setText(fpd);
}

/**
 * @brief Result类的析构函数，用于关闭窗口
 */
Result::~Result()
{
    delete ui; // 释放内存
}

/**
 * @brief 选择是否为另一个亲友制定计划，若是，返回选择亲友界面，若否，返回结束界面
 */
void Result::on_pushButton_2_clicked()
{
    AskDialog dialog(this);

    int resout = dialog.exec();

    // 不为另一个亲友制定计划
    if (resout == QDialog::Rejected)
    {
        End *ed = new End(); // 创建结束界面
        ed->setText1(ui->lineEdit_5->text());
        ed->show(); // 显示结束界面
    }

    // 为另一个亲友制定计划
    else
    {
        ChooseWindow *chooseWindow = new ChooseWindow(); // 创建选择亲友界面
        chooseWindow->setListWidget();                   // 设置亲友列表
        chooseWindow->show();                            // 显示选择亲友界面
    }
    this->close();
}
