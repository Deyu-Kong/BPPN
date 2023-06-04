/**
 * @file askdialog.h
 * @authors 孔德昱
 * @date 2023-5-28
 * @brief ChooseWindow类的实现文件，用于让用户选择亲友
 */
#include "choosewindow.h"
#include "ui_choosewindow.h"

extern QStringList gRelativeList;
extern QListWidgetItem *curRelative;

/**
 * @brief ChooseWindow类的构造函数，用于初始化显示的内容
 * @param parent 父窗口 默认为nullptr
 */
ChooseWindow::ChooseWindow(QWidget *parent) : QWidget(parent),
                                              ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);
    setWindowTitle("选择");
}

/**
 * @brief ChooseWindow类的析构函数，用于关闭窗口
 */
ChooseWindow::~ChooseWindow()
{
    delete ui;
}

/**
 * @brief 将亲友信息从RelativeWindow传递到ChooseWindow
 */
void ChooseWindow::setListWidget()
{
    for (int i = 0; i < gRelativeList.size(); i++)
    {
        ui->listWidget->addItem(gRelativeList.at(i));
    }
}

/**
 * @brief 在选择了一位亲友后点击确认后执行，用于关闭ChooseWindow，打开MainWindow，
 * 同时将选择的亲友信息传递到MainWindow
 */
void ChooseWindow::on_pushButton_clicked()
{
    // 获取当前选中的亲友
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    // 如果选中了亲友，关闭ChooseWindow，打开MainWindow，并传递亲友信息
    if (currentItem->text() != "姓名\t关系\t生日日期\t")
    {
        curRelative = currentItem;
        this->close();
        MainWindow *mainWindow = new MainWindow();
        QString item = currentItem->text();
        int fst_idx = item.indexOf('\t');
        int scd_idx = item.indexOf('\t', fst_idx + 1);
        QString date_t = item.mid(scd_idx + 1);
        QString date = date_t.split('\t').first();
        mainWindow->setBirthday(QDate::fromString(date, "yyyy-MM-dd"));
        mainWindow->setRelativeName(item.mid(0, fst_idx));
        mainWindow->show();
    }
    else // 如果没有选中亲友，弹出警告
    {
        QMessageBox::warning(this, "警告", "请选择一位亲友！");
    }
}
