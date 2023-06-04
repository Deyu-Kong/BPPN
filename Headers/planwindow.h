/**
 * @file planwindow.h
 * @author 孔德昱，杜忠璠
 * @date 2023/3/3     20:00
 * @brief
 */
#ifndef PLAN_H
#define PLAN_H

#include <QWidget>
#include "mainwindow.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDate>
#include <QDebug>
#include <QString>
#include <QListWidgetItem>
#include <method.h>
#include <result.h>

namespace Ui
{
    class PlanWindow;
}
/**
 * @brief PlanWindow类，用于显示计划界面
 */
class PlanWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief PlanWindow类的构造函数，用于初始化显示的内容
     * @param parent 父窗口 默认为nullptr
     */
    explicit PlanWindow(QWidget *parent = nullptr);

    /**
     * @brief PlanWindow类的析构函数，用于关闭窗口
     */
    ~PlanWindow();

    /**
     * @brief 将计划日期传递到计划界面,并显示
     * @param fpd 计划日期
     */
    void setText1(QString nb);

    /**
     * @brief 将计划日期传递到计划界面,并显示
     * @param fpd 计划日期
     */
    void setText2(QString days); // 设置天数
    void setText3(QString days);
    QDate Birthday;      // 生日
    QDate CurrentDate;   // 当前日期
    QDate NextBirthday;  // 下一次生日
    int DisDays;         // 距离天数
    int PlanAdvanceDays; // 计划提前天数
    QDate PlanDate;      // 计划日期
    QDate PartyDate;     // 聚会日期
private slots:
    /**
     * @brief 在点击确认后执行，显示选择的亲属信息
     */
    void on_pushButton_clicked();

    /**
     * @brief 进行日期计算，显示计划日期
     */
    void on_pushButton_2_clicked();

    /**
     * @brief 点击后进入结果界面
     */
    void on_pushButton_3_clicked();

private:
    Ui::PlanWindow *ui;
};

#endif // PLAN_H
