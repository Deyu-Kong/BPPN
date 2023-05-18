#include "people.h"
#include "ui_people.h"

People::People(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::People)
{
    ui->setupUi(this);
}

People::~People()
{
    delete ui;
}

void People::on_pushButton_clicked()
{
    MyDialog dialog(this);


    if (dialog.exec() == QDialog::Accepted) {
         PersInfo data = dialog.getData();
        QString text =QString("姓名\t关系\t生日日期\t");

        ui->listWidget->addItem(text);

        QString text2 = QString("%1\t%2\t%3\t").arg(data.name, data.relationship, data.birth.toString(Qt::ISODate));
        ui->listWidget->addItem(text2);
    }
}
