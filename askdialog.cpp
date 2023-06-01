#include<QDialog>
#include<QGridLayout>
#include<QLineEdit>
#include<QPushButton>
#include<QDateEdit>
#include "askdialog.h"


AskDialog::AskDialog(QWidget* parent) : QDialog(parent) {
    // 创建布局和控件
    QGridLayout* layout = new QGridLayout(this);
    QLabel* nameLabel = new QLabel(QString("是否需要为其它亲友确定计划日期？"), this);

    QPushButton* okButton = new QPushButton("是", this);
    QPushButton* noButton = new QPushButton("否", this);
    // 添加控件到布局
    layout->addWidget(nameLabel, 0, 0);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(noButton);

    layout->addLayout(buttonLayout, 3, 0);

    // 连接信号和槽
    connect(okButton, &QPushButton::clicked, this, &AskDialog::onOkButtonClicked);
    connect(noButton, &QPushButton::clicked, this, &AskDialog::onNoButtonClicked);
}
/*
添加亲友信息后在输入框中点击确定
*/
void AskDialog::onOkButtonClicked(){
    AskDialog::accept();
}

void AskDialog::onNoButtonClicked(){
    AskDialog::reject();
}

