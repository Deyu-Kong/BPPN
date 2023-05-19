#include "choosewindow.h"
#include "ui_choosewindow.h"

ChooseWindow::ChooseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);
//    QString text =QString("姓名\t关系\t生日日期\t");
//    ui->listWidget->addItem(text);
}

ChooseWindow::~ChooseWindow()
{
    delete ui;
}

void ChooseWindow::setListWidget(){
    for(int i=0;i<this->list.size();i++){
        ui->listWidget->addItem(this->list.at(i));
    }
}

void ChooseWindow::on_pushButton_clicked()
{
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
//    qDebug()<<currentItem->text();
    if(currentItem->text()!="姓名\t关系\t生日日期\t"){
        this->close();
        MainWindow *mainWindow = new MainWindow();
        QString item = currentItem->text();
        int fst_idx = item.indexOf('\t');
        int scd_idx = item.indexOf('\t',fst_idx+1);
        QString date_t = item.mid(scd_idx+1);
        QString date = date_t.split('\t').first();
        mainWindow->setBirthday(QDate::fromString(date,"yyyy-MM-dd"));
        mainWindow->show();
    }else{
        QMessageBox::warning(this,"警告","请选择一位亲友！");
    }
}
