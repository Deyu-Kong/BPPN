/**
 * @file askdialog.h
 * @authors 孔德昱
 * @date 2023-5-28
 * @brief 定义ChooseWindow类，用于让用户选择亲友
 */
#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "mainwindow.h"

extern QStringList gRelativeList;

namespace Ui
{
    class ChooseWindow;
}
/**
 * @brief ChooseWindow类，用于显示让用户选择亲友的窗口
 */
class ChooseWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief ChooseWindow类的构造函数，用于初始化显示的内容
     * @param parent 父窗口 默认为nullptr
     */
    explicit ChooseWindow(QWidget *parent = nullptr);
    /**
     * @brief 将亲友信息从RelativeWindow传递到ChooseWindow
     */
    ~ChooseWindow();
    /**
     * @brief ChooseWindow类的析构函数，用于关闭窗口
     */
    Ui::ChooseWindow *ui;
    /**
     * @brief 将亲友信息从RelativeWindow传递到ChooseWindow
     */
    void setListWidget();
private slots:
    /**
     * @brief 在选择了一位亲友后点击确认后执行，用于关闭ChooseWindow，打开MainWindow，
     * 同时将选择的亲友信息传递到MainWindow
     */
    void on_pushButton_clicked();
};

#endif // CHOOSEWINDOW_H
