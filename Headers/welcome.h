/**
 * @file welcome.h
 * @author 杜忠璠 孔德昱
 * @date 2023/3/3
 * @brief 定义欢迎界面
 */
** /
#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
    namespace Ui
{
    class Welcome;
}
/**
 * @brief Welcome类，用于显示欢迎界面
 */
class Welcome : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Welcome类的构造函数，用于初始化显示的内容
     * @param parent 父窗口 默认为nullptr
     */
    explicit Welcome(QWidget *parent = nullptr);

    /**
     * @brief 鼠标按下事件
     * @param event 事件
     */
    void mousePressEvent(QMouseEvent *event);

    /**
     * @brief 键盘按下事件
     * @param event 事件
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief Welcome类的析构函数，用于关闭窗口
     */
    ~Welcome();

private slots:

private:
    Ui::Welcome *ui;
};

#endif // WELCOME_H
