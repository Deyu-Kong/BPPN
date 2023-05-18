#include "people.h"
#include "ui_people.h"
#include "mydialog.h"
#include "persinfo.h"
#include <QInputDialog>

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
        QString text = QString("%1, %2, %3").arg(data.name, data.relationship, data.birth.toString(Qt::ISODate));
        ui->listWidget->addItem(text);
    }
}
