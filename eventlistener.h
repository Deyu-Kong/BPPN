#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H
#include<QKeyEvent>
#include<QApplication>
#include<QDialog>
#include"welcome.h"
// 监听按下任意键
class KeyEventFilter : public QObject
{
public:
    KeyEventFilter(QObject* parent = nullptr) : QObject(parent) {}

protected:
    bool eventFilter(QObject* obj, QEvent* event) override
    {
        if (event->type() == QEvent::KeyPress)
        {
            // 获取按下的键
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            Qt::Key key = static_cast<Qt::Key>(keyEvent->key());

            // 如果按下了任意键，则关闭窗口
            if (key != Qt::Key_unknown)
            {

                welcome::accept();
            }
            return true;
        }

        return QObject::eventFilter(obj, event);
    }
};

#endif // EVENTLISTENER_H

