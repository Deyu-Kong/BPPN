/**
 * @file mainwindow.h
 * @author 杜忠璠
 * @date 2023/3/3
 * @brief 定义主界面
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDate>
#include <QString>
#include <QDebug>
#include <method.h>
#include <QMainWindow>
#include <planwindow.h>
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief MainWindow类，用于显示主界面
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QDate Birthday;       // 用于存储生日
    QDate CurrentDate;    // 用于存储当前日期
    QDate NextBirthday;   // 用于存储下一次生日
    QString relativeName; // 用于存储亲友姓名
    int DisDays;          // 用于存储距离下一次生日的天数

    /**
     * @brief MainWindow类的构造函数，用于初始化显示的内容
     * @param parent 父窗口 默认为nullptr
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief MainWindow类的析构函数，用于关闭窗口
     */
    ~MainWindow();
    /**
     * @brief 获取ui
     */
    Ui::MainWindow *getUi();
    /**
     * @brief 在点击键盘后执行，用于关闭结束界面
     */
    void afterInput();

    /**
     * @brief 事件过滤器，用于判断是否点击了鼠标
     */
    bool eventFilter(QObject *obj, QEvent *event);
    /**
     * @brief 设置生日
     */
    void setBirthday(QDate birthday);
    /**
     * @brief 设置当前亲友的姓名
     */
    void setRelativeName(QString name);

private slots:
    /**
     * @brief 在dateEdit_2的日期改变后执行，用于计算下一次生日的日期
     */
    void on_dateEdit_2_userDateChanged(const QDate &date);
    /**
     * @brief 在点击确认后执行，显示下一次生日的日期
     */
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
