
/**
 * @file mainwindow.cpp
 * @author 杜忠璠
 * @date 2023/3/3     20:00
 * @brief 定义主界面
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow类的构造函数，用于初始化显示的内容
 * @param parent 父窗口 默认为nullptr
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    ui->label_2->setText("当前日期：");
    ui->dateEdit_2->setDate(QDate::currentDate());
    //    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit_2->setCalendarPopup(true);
    ui->label_3->setText("距离您的生日还有：");
    this->CurrentDate = ui->dateEdit_2->date();

    ui->label_5->setText("下次生日的日期");
    ui->daysDistance->setReadOnly(true);
    ui->nextBirthdayLabel->setReadOnly(true);
    setWindowTitle("生日聚会计划便签");
    ui->label_6->setVisible(0);
    ui->daysDistance->setVisible(0);
    ui->nextBirthdayLabel->setVisible(0);
    ui->label_3->setVisible(0);
    ui->label_5->setVisible(0);
}
/**
 * @brief MainWindow类的析构函数，用于关闭窗口
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief 在dateEdit_2的日期改变后执行，用于计算下一次生日的日期
 */
void MainWindow::on_dateEdit_2_userDateChanged(const QDate &date)
{
    this->CurrentDate = date;                                                // 更新当前日期
    this->NextBirthday = getNextBirthday(this->CurrentDate, this->Birthday); // 更新下一次生日
    int days = ui->dateEdit_2->date().daysTo(this->NextBirthday);
    this->DisDays = days;
    QString ds = QString::number(days);
    ui->daysDistance->setText(ds);
    QString nextBirthdayString = this->NextBirthday.toString("yyyy/MM/dd dddd");
    ui->nextBirthdayLabel->setText(nextBirthdayString);
}

/**
 *
 * @brief 该函数用于在点击键盘后执行，用于关闭MainWindow，打开PlanWindow。
 */
void MainWindow::afterInput()
{
    this->close();
    PlanWindow *pl = new PlanWindow();
    pl->Birthday = MainWindow::Birthday;
    pl->NextBirthday = MainWindow::NextBirthday;
    pl->CurrentDate = MainWindow::CurrentDate;
    pl->DisDays = MainWindow::DisDays;
    pl->show();
    pl->setText1(ui->nextBirthdayLabel->text());
    pl->setText2(ui->daysDistance->text());
    pl->setText3(ui->daysDistance->text());
}

/**
 * @brief 在点击确认后执行，显示下一次生日的日期
 */
void MainWindow::on_pushButton_2_clicked()
{
    ui->label_6->setVisible(1);
    ui->daysDistance->setVisible(1);
    ui->nextBirthdayLabel->setVisible(1);
    ui->label_3->setVisible(1);
    ui->label_5->setVisible(1);
    ui->centralwidget->installEventFilter(this);
}

/*
 * @brief 设置当前亲友的生日
 **/
void MainWindow::setBirthday(QDate birthday)
{
    // 设置生日
    this->Birthday = birthday;
    // 设置当前日期
    ui->birthday->setText(this->Birthday.toString("yyyy-MM-dd"));
    // 设置下一次生日
    this->NextBirthday = getNextBirthday(this->CurrentDate, this->Birthday);
    int days = this->CurrentDate.daysTo(this->NextBirthday);
    QString ds = QString::number(days);
    ui->daysDistance->setText(ds);
    QString nextBirthdayString = this->NextBirthday.toString("yyyy/MM/dd dddd");
    // 将下一次生日显示在界面上
    ui->nextBirthdayLabel->setText(nextBirthdayString);
}

/**
 * @brief 设置当前亲友的姓名
 */
void MainWindow::setRelativeName(QString name)
{
    this->relativeName = name;
    ui->label->setText(this->relativeName + "的生日日期：");
}

/**
 * @brief 获取ui
 */
Ui::MainWindow *MainWindow::getUi()
{
    return ui;
}

/**
 * @brief 设置事件过滤器，用于判断是否点击了鼠标或是键盘。
 * 若是，则执行afterInput函数，关闭MainWindow，打开PlanWindow
 */
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    //    qDebug()<<"Now is at eventFilter";
    // 如果是键盘事件或者是鼠标事件，执行afterInput函数，并返回true
    if (event->type() == QEvent::KeyPress || event->type() == QEvent::MouseButtonPress)
    {
        afterInput();
        return true;
    }
    // 否则返回对应的事件
    return QObject::eventFilter(obj, event);
}
