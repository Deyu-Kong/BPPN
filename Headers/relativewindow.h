/**
 * @file relativewindow.h
 * @brief 定义亲属信息界面
 * @date 2023/6/1
 * @author 孔德昱 杜忠璠
 */
#ifndef RELATIVEWINDOW_H
#define RELATIVEWINDOW_H

#include <QWidget>
#include "mydialog.h"
#include "persinfo.h"
#include "choosewindow.h"
#include <QInputDialog>
#include <QMessageBox>

namespace Ui
{
    class RelativeWindow;
}
/**
 * @brief RelativeWindow类，用于显示亲属信息界面
 */
class RelativeWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief RelativeWindow类的构造函数，用于初始化显示的内容
     * @param parent 父窗口 默认为nullptr
     */
    explicit RelativeWindow(QWidget *parent = nullptr);

    /**
     * @brief RelativeWindow类的析构函数，用于关闭窗口
     */
    ~RelativeWindow();

    /**
     * @brief 获取键盘敲击事件，实现按任意键进入下一界面
     * @param event 事件
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief 获取鼠标点击事件，实现点击鼠标进入下一界面
     * @param event 事件
     */
    void RelativeWindow::showEvent(QShowEvent *event);

private slots:
    /**
     * @brief 在点击添加亲属信息后执行，用于添加亲属信息
     */
    void on_pushButton_clicked();

private:
    Ui::RelativeWindow *ui;
};

#endif // RELATIVEWINDOW_H
