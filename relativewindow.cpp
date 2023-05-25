#include "relativewindow.h"
#include "ui_relativewindow.h"

extern QStringList gRelativeList;

RelativeWindow::RelativeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RelativeWindow)
{
    ui->setupUi(this);
    QString text =QString("姓名\t关系\t生日日期\t");
    ui->listWidget->addItem(text);
}

RelativeWindow::~RelativeWindow()
{
    delete ui;
}

/*
添加亲友
*/
void RelativeWindow::on_pushButton_clicked()
{
    MyDialog dialog(this);

    // 从输入框中的PersInfo转化为QString
    if (dialog.exec() == QDialog::Accepted) {
        PersInfo data = dialog.getData();

        QString text2 = QString("%1\t%2\t%3\t").arg(data.name, data.relationship, data.birth.toString(Qt::ISODate));
        ui->listWidget->addItem(text2);
    }
}


void RelativeWindow::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    setFocus();
}

/*
在已经添加亲友后，按任意键继续
*/
void RelativeWindow::keyPressEvent(QKeyEvent *event){
    if(ui->listWidget->count()>1){
        this->close();
        ChooseWindow *chooseWindow = new ChooseWindow();
        for(int i=0;i<ui->listWidget->count();++i){
            gRelativeList.append(ui->listWidget->item(i)->text());
        }
        chooseWindow->setListWidget();
        chooseWindow->show();
    }
    else{
        QMessageBox::warning(this, "警告", "请先添加一位亲友");
    }
}
