/**
 * @file end.h
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/4     9:00
 * @brief 定义结束界面
 */
#ifndef END_H
#define END_H

#include <QWidget>
#include <QMovie>
namespace Ui
{
    class End;
}
/**
 * @brief End类，用于显示结束界面
 */
class End : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief End类的构造函数，用于初始化显示的内容
     * @param parent 父窗口 默认为nullptr
     */
    explicit End(QWidget *parent = nullptr);
    /**
     * @brief End类的析构函数，用于关闭窗口
     */
    ~End();
    /**
     * @brief 将计划日期传递到结束界面,并显示
     * @param fpd 计划日期
     */
    void setText1(QString fpd);
    //
    /**
     * @brief 鼠标按下事件,在鼠标点击后执行，用于关闭结束界面
     */
    void mousePressEvent(QMouseEvent *event);
    /**
     * @brief 键盘按下事件,在点击键盘后执行，用于关闭结束界面
     */
    void keyPressEvent(QKeyEvent *event);

private slots:
    /**
     * @brief 在点击确认后执行，用于关闭结束界面
     */
    void on_pushButton_clicked();

private:
    Ui::End *ui;
};

#endif // END_H
