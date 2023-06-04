
/**
 * @file planwindow.cpp
 * @author 杜忠璠，孔德昱
 * @date 2023/3/3
 * @brief 显示计划页面以及定义相关操作
 */
#include "planwindow.h"
#include "ui_planwindow.h"

extern QListWidgetItem *curRelative;

/**
 * @brief PlanWindow类的构造函数，用于初始化显示内容。
 * @param parent   继承的父类对象
 * @return 无返回值
 */
PlanWindow::PlanWindow(QWidget *parent) : QWidget(parent),
                                          ui(new Ui::PlanWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("返回");
    ui->label->setText("下次生日的日期：");
    ui->label_2->setText("剩余天数：");
    ui->label_3->setText("提前后的日期为：");
    ui->label_6->setText("计划日期为：");

    ui->pushButton_2->setText("确认");
    ui->pushButton_3->setText("查看最终结果");
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    setWindowTitle("制定聚会计划");
}
/**
 * @brief PlanWindow类的析构函数，用于关闭窗口。
 */
PlanWindow::~PlanWindow()
{
    delete ui;
}

/**
 * @brief 在计划阶段选择返回，重新输入当前日期。
 * @param parent   继承的父类对象
 * @return 无返回值
 */
void PlanWindow::on_pushButton_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow();
    QString item = curRelative->text();
    int fst_idx = item.indexOf('\t');
    int scd_idx = item.indexOf('\t', fst_idx + 1);
    QString date_t = item.mid(scd_idx + 1);
    QString date = date_t.split('\t').first();
    mainWindow->setBirthday(QDate::fromString(date, "yyyy-MM-dd"));
    mainWindow->setRelativeName(item.mid(0, fst_idx));
    mainWindow->show();
}
/**
 * @brief 显示下一次生日日期。
 * @param nb 下一次生日日期
 */
void PlanWindow::setText1(QString nb)
{
    ui->lineEdit->setText(nb);
}

/**
 * @brief 显示距离天数。
 * @param days 距离天数
 */
void PlanWindow::setText2(QString days)
{
    ui->lineEdit_2->setText(days);
}

/**
 * @brief 提示用户输入提前天数。
 * @param days 提前天数
 */
void PlanWindow::setText3(QString days)
{
    QString s("请输入0-");
    s.append(days);
    ui->lineEdit_3->setPlaceholderText(s); // 背景提示用户输入范围
    QIntValidator *IntValidator = new QIntValidator;

    IntValidator->setRange(0, days.toInt()); // 设置输入范围
    ui->lineEdit_3->setValidator(IntValidator);
}

/**
 * @brief 点击确认后，计算计划聚会日期。
 */
void PlanWindow::on_pushButton_2_clicked()
{
    if (ui->lineEdit_3->text().toInt() < 0 || ui->lineEdit_3->text().toInt() > ui->lineEdit_2->text().toInt())
    {

        QMessageBox::warning(this, tr("警告！"), tr("天数超出范围！"), "返回"); // 若输入的天数超出范围，弹出警告框
    }

    // 若输入的天数在范围内，计算计划聚会日期
    else
    {

        QString s = ui->lineEdit->text();

        int year = s.mid(0, 4).toInt();
        int month = s.mid(5, 2).toInt();
        int day = s.mid(8, 2).toInt();
        QDate d(year, month, day);

        MyDate d1(year, month, day);
        MyDate d2 = getAdvancedDate(d1, ui->lineEdit_3->text().toInt()); // 计算计划聚会日期
        QDate qd2(d2.year, d2.month, d2.day);
        PlanWindow::PlanAdvanceDays = ui->lineEdit_3->text().toInt();
        PlanWindow::PlanDate = qd2;
        CaculateWeekDay(d2);

        // 若计划聚会日期是特殊假日，弹出提示框，不用考虑是工作日
        if (isSpecialVacation(d2))
        {
            QMessageBox::warning(this, tr("提示！"), tr("此日期是特殊假日"), "确定");
        }

        // 若计划聚会日期是工作日，弹出提示框，自动调整到最近的周六
        else if (d2.week < 5)
        {
            QMessageBox::warning(this, tr("提示！"), tr("此日期是工作日，已为您自动调整到最近的周六"), "确定");
        }
        MyDate pd = plan2party(d2);
        int qpyear = pd.year;
        int qpmonth = pd.month;
        int qpday = pd.day;
        QDate qpd(qpyear, qpmonth, qpday);
        PlanWindow::PartyDate = qpd;
        ui->lineEdit_4->setText(qpd.toString("yyyy/MM/dd dddd"));
        ui->lineEdit_5->setText(qd2.toString("yyyy/MM/dd dddd"));
    }
}

/**
 * @brief 点击查看最终结果后，显示最终结果。
 */
void PlanWindow::on_pushButton_3_clicked()
{
    if (ui->lineEdit_4->text() == "")
    {
        QMessageBox::warning(this, tr("提示！"), tr("还未得到计划日期"), "返回");
    }
    else
    {
        this->close();
        Result *R = new Result();
        R->Birthday = PlanWindow::Birthday;
        R->NextBirthday = PlanWindow::NextBirthday;
        //        qDebug()<<R->NextBirthday;
        R->PlanAdvanceDays = PlanWindow::PlanAdvanceDays;
        R->DisDays = PlanWindow::DisDays;
        R->PlanDate = PlanWindow::PlanDate;
        R->CurrentDate = PlanWindow::CurrentDate;
        R->PartyDate = PlanWindow::PartyDate;
        R->setText1(PlanWindow::NextBirthday.toString("yyyy/MM/dd dddd"));
        QString ds = QString::number(PlanWindow::DisDays);
        R->setText2(ds);
        QString ad = QString::number(PlanWindow::PlanAdvanceDays);
        R->setText3(ad);
        R->setText4(PlanWindow::PlanDate.toString("yyyy/MM/dd dddd"));
        R->setText5(PlanWindow::PartyDate.toString("yyyy/MM/dd dddd"));
        R->show();
    }
}
