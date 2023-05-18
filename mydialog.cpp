#include<QDialog>
#include<QGridLayout>
#include<QLineEdit>
#include<QPushButton>
#include<QDateEdit>
#include "mydialog.h"





MyDialog::MyDialog(QWidget* parent) : QDialog(parent) {
    // 创建布局和控件
    QGridLayout* layout = new QGridLayout(this);
    lineEdit1 = new QLineEdit(this);
    lineEdit2 = new QLineEdit(this);
    dateEdit = new QDateEdit(QDate::currentDate(), this);
    QPushButton* okButton = new QPushButton("OK", this);

    // 添加控件到布局
    layout->addWidget(lineEdit1, 0, 0);
    layout->addWidget(lineEdit2, 1, 0);
    layout->addWidget(dateEdit, 2, 0);
    layout->addWidget(okButton, 3, 0);

    // 连接信号和槽
    connect(okButton, &QPushButton::clicked, this, &MyDialog::accept);
}

PersInfo MyDialog::getData(){
    return PersInfo(lineEdit1->text(), lineEdit2->text(), dateEdit->date());
    }



