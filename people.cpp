#include "people.h"
#include "ui_people.h"

People::People(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::People)
{
    ui->setupUi(this);
    QString text =QString("姓名\t关系\t生日日期\t");
    ui->listWidget->addItem(text);
}

People::~People()
{
    delete ui;
}

// 添加亲友
void People::on_pushButton_clicked()
{
    MyDialog dialog(this);


    if (dialog.exec() == QDialog::Accepted) {
         PersInfo data = dialog.getData();
//        QString text =QString("姓名\t关系\t生日日期\t");

//        ui->listWidget->addItem(text);

        QString text2 = QString("%1\t%2\t%3\t").arg(data.name, data.relationship, data.birth.toString(Qt::ISODate));
        ui->listWidget->addItem(text2);
    }
}

void People::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    setFocus();
}

void People::keyPressEvent(QKeyEvent *event){
    if(ui->listWidget->count()>1){
//        ui->listWidget->addItem("杜忠璠\t孙子\t2002-02-20");
        this->close();
        ChooseWindow *chooseWindow = new ChooseWindow();
        for(int i=0;i<ui->listWidget->count();++i){
            chooseWindow->list.append(ui->listWidget->item(i)->text());
        }
        chooseWindow->setListWidget();
        chooseWindow->show();
    }
    else{
        QMessageBox::warning(this, "警告", "请先添加一位亲友");
    }
}
