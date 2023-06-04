/**
 * @file askdialog.cpp
 * @authors 孔德昱
 * @date 2023-5-28
 * @brief AskDialog类的实现文件
 */
#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include "askdialog.h"

/**
 * @brief AskDialog类的构造函数，用于初始化显示的内容以及连接信号和槽
 * @param parent 父窗口
 */
AskDialog::AskDialog(QWidget *parent) : QDialog(parent)
{
    // 创建布局和控件
    QGridLayout *layout = new QGridLayout(this);
    QLabel *nameLabel = new QLabel(QString("是否需要为其它亲友确定计划日期？"), this);
    QPushButton *okButton = new QPushButton("是", this);
    QPushButton *noButton = new QPushButton("否", this);

    // 添加控件到布局
    layout->addWidget(nameLabel, 0, 0);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(noButton);
    layout->addLayout(buttonLayout, 3, 0);
    setWindowTitle("提示");

    // 连接信号和槽
    connect(okButton, &QPushButton::clicked, this, &AskDialog::onOkButtonClicked);
    connect(noButton, &QPushButton::clicked, this, &AskDialog::onNoButtonClicked);
}
/**
 * @brief 当用户点击确认时，返回QDialog::Accepted状态，同时关闭对话框
 */
void AskDialog::onOkButtonClicked()
{
    AskDialog::accept();
}

/**
 * @brief 当用户点击取消时，返回QDialog::Rejected状态，同时关闭对话框
 */
void AskDialog::onNoButtonClicked()
{
    AskDialog::reject();
}
