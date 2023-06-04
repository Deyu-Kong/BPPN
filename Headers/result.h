/**
 * @file result.h
 * @author 杜忠璠 孔德昱
 * @date 2023/6/1
 * @brief 定义结果界面
 */
#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QMessageBox>
#include <planwindow.h>
#include <end.h>
#include <askdialog.h>
#include <choosewindow.h>

namespace Ui
{
    class Result;
}
/**
 * @brief Result类，用于显示结果界面
 */
class Result : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Result类的构造函数，用于初始化显示的内容
     */
    explicit Result(QWidget *parent = nullptr);

    /**
     * @brief Result类的析构函数，用于关闭窗口
     */
    ~Result();
    QDate Birthday;      // 生日
    QDate CurrentDate;   // 当前日期
    QDate NextBirthday;  // 下一次生日
    int DisDays;         // 距离天数
    int PlanAdvanceDays; // 计划提前天数
    QDate PlanDate;      // 计划日期
    QDate PartyDate;     // 聚会日期
    void setText1(QString nb);

    /**
     * @brief 显示距离天数
     * @param disday 距离天数
     */
    void setText2(QString disday);

    /**
     * @brief 显示提前天数
     * @param ad 提前天数
     */
    void setText3(QString ad);

    /**
     * @brief 显示计划日期
     * @param pd 计划日期
     */
    void setText4(QString pd);

    /**
     * @brief 显示最终聚会日期
     * @param fpd 最终聚会日期
     */
    void setText5(QString fpd);
private slots:
    /**
     * @brief 在点击确认后执行，用于关闭结果界面
     */
    void on_pushButton_2_clicked();

private:
    Ui::Result *ui;
};

#endif // RESULT_H
