#include "choosewindow.h"
#include "ui_choosewindow.h"

extern QStringList gRelativeList;
extern QListWidgetItem *curRelative;

ChooseWindow::ChooseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);

}

ChooseWindow::~ChooseWindow()
{
    delete ui;
}

/*
    将亲友信息从RelativeWindow传递到ChooseWindow
*/
void ChooseWindow::setListWidget(){
    for(int i=0;i<gRelativeList.size();i++){
        ui->listWidget->addItem(gRelativeList.at(i));
    }
}

/*
    在选择了一位亲友后点击确认后执行
*/
void ChooseWindow::on_pushButton_clicked()
{
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    if(currentItem->text()!="姓名\t关系\t生日日期\t"){
        curRelative = currentItem;
        this->close();
        MainWindow *mainWindow = new MainWindow();
        QString item = currentItem->text();
        int fst_idx = item.indexOf('\t');
        int scd_idx = item.indexOf('\t',fst_idx+1);
        QString date_t = item.mid(scd_idx+1);
        QString date = date_t.split('\t').first();
        mainWindow->setBirthday(QDate::fromString(date,"yyyy-MM-dd"));
        mainWindow->setRelativeName(item.mid(0,fst_idx));
        mainWindow->show();
    }else{
        QMessageBox::warning(this,"警告","请选择一位亲友！");
    }
}
