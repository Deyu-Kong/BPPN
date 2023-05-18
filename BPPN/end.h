/**
 * @file end.h
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/4     9:00
 *
 */
#ifndef END_H
#define END_H

#include <QWidget>
#include<QMovie>
namespace Ui {
class End;
}

class End : public QWidget
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);
    ~End();
     void setText1(QString fpd);
     // 鼠标按下事件
     void mousePressEvent(QMouseEvent *event);
     // 键盘按下事件
     void keyPressEvent(QKeyEvent *event);

private slots:
     void on_pushButton_clicked();

private:
    Ui::End *ui;
};

#endif // END_H
