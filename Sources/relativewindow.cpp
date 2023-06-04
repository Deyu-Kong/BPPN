/**
 * @file relativewindow.cpp
 * @brief 实现亲属信息界面
 * @author 孔德昱 杜忠璠
 * @date 2023/6/1
 */
#include "relativewindow.h"
#include "ui_relativewindow.h"

extern QStringList gRelativeList; // 亲属信息列表

/**
 * @brief RelativeWindow类的构造函数，用于初始化显示的内容
 * @param parent 父窗口 默认为nullptr
 */
RelativeWindow::RelativeWindow(QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::RelativeWindow)
{
    ui->setupUi(this);
    QString text = QString("姓名\t关系\t生日日期\t");
    ui->listWidget->addItem(text);
    setWindowTitle("添加亲友信息");
}

/**
 * @brief RelativeWindow类的析构函数，用于关闭窗口
 */
RelativeWindow::~RelativeWindow()
{
    delete ui;
}

/**
 * @brief 在点击添加亲属信息后执行，用于添加亲属信息
 */
void RelativeWindow::on_pushButton_clicked()
{
    MyDialog dialog(this); // 创建添加亲友对话框

    // 如果点击了确定按钮
    if (dialog.exec() == QDialog::Accepted)
    {
        PersInfo data = dialog.getData(); // 获取用户输入的亲属信息

        QString text2 = QString("%1\t%2\t%3\t").arg(data.name, data.relationship, data.birth.toString(Qt::ISODate)); // 将亲属信息转换为字符串
        ui->listWidget->addItem(text2);                                                                              // 将亲属信息添加到列表中
    }
}

/**
 * @brief 设置焦点
 * @param event 事件
 */
void RelativeWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    setFocus();
}

/**
 * @brief 获取键盘敲击事件，实现按任意键进入下一界面
 * @param event 事件
 */
void RelativeWindow::keyPressEvent(QKeyEvent *event)
{
    // 如果亲友信息列表中的亲友数量大于1
    if (ui->listWidget->count() > 1)
    {
        this->close();
        ChooseWindow *chooseWindow = new ChooseWindow();
        for (int i = 0; i < ui->listWidget->count(); ++i)
        {
            gRelativeList.append(ui->listWidget->item(i)->text()); // 将亲友信息列表中的亲友信息添加到全局变量中
        }
        chooseWindow->setListWidget(); // 设置列表
        chooseWindow->show();          // 显示下一界面
    }

    // 如果亲友信息列表中的亲友数量小于等于1(第一行为标题)
    else
    {
        QMessageBox::warning(this, "警告", "请先添加一位亲友"); // 弹出警告对话框
    }
}
