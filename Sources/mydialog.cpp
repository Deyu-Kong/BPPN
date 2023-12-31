/**
 * @file mydialog.cpp
 * @brief 实现添加亲属信息的对话框
 * @date 2023/5/28
 * @author 孔德昱 杜忠璠
 */

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include "mydialog.h"

/**
 * @brief MyDialog类的构造函数，用于初始化对话框
 * @param parent 父窗口 默认为nullptr
 */
MyDialog::MyDialog(QWidget *parent) : QDialog(parent)
{
    // 创建布局和控件
    QGridLayout *layout = new QGridLayout(this);
    QLabel *nameLabel = new QLabel(QString("姓名"), this);

    lineEdit1 = new QLineEdit(this);
    QLabel *relationLabel = new QLabel("关系", this);
    lineEdit2 = new QLineEdit(this);
    QLabel *birthdayLabel = new QLabel("生日", this);
    dateEdit = new QDateEdit(QDate::currentDate(), this);
    dateEdit->setCalendarPopup(true);
    QPushButton *okButton = new QPushButton("确认", this);

    // 添加控件到布局
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(lineEdit1, 0, 1);
    layout->addWidget(relationLabel, 1, 0);
    layout->addWidget(lineEdit2, 1, 1);
    layout->addWidget(birthdayLabel, 2, 0);
    layout->addWidget(dateEdit, 2, 1);
    layout->addWidget(okButton, 3, 0);
    setWindowTitle("添加");
    // 连接信号和槽
    connect(okButton, &QPushButton::clicked, this, &MyDialog::onOkButtonClicked);
}

/**
 * @brief 确认按钮的槽函数,添加亲友信息后在输入框中点击确定
 */
void MyDialog::onOkButtonClicked()
{
    if (lineEdit1->text().isEmpty() && lineEdit2->text().isEmpty())
    {
        QMessageBox::warning(this, "警告", "姓名和关系不能为空！");
    }
    else if (lineEdit1->text().isEmpty())
    {
        QMessageBox::warning(this, "警告", "姓名不能为空！");
    }
    else if (lineEdit2->text().isEmpty())
    {
        QMessageBox::warning(this, "警告", "关系不能为空");
    }
    else
        MyDialog::accept();
}

/**
 * @brief 获取用户输入的亲属信息
 * @return PersInfo类型的亲属信息
 */
PersInfo MyDialog::getData()
{
    return PersInfo(lineEdit1->text(), lineEdit2->text(), dateEdit->date());
}
