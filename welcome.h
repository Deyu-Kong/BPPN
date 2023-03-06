/**
 * @file welcome.h
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/3     20:00
 *
 */
#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QKeyEvent>

namespace Ui {
class welcome;
}

class welcome : public QDialog
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    // 鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event);
    ~welcome();

private slots:
//    void on_pushButton_clicked();

private:
    Ui::welcome *ui;
};

#endif // WELCOME_H
