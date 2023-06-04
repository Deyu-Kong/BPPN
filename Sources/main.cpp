
/**
 * @file main.cpp
 * @author 杜忠璠
 * @date 2023/3/3
 * @brief 主函数
 */
#include "mainwindow.h"
#include "relativewindow.h"
#include <welcome.h>
#include <QApplication>

// #include <QDebug>

int main(int argc, char *argv[])
{
    // 在QApplication创建之前加入该句，解决分辨率不同导致的文字压缩问题|
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    //    MainWindow mainWindow;
    RelativeWindow relativeWindow;
    Welcome welcome;

    // 首先显示欢迎界面
    welcome.exec();
    // 如果用户点击了开始按钮，则显示RelativeWindow
    relativeWindow.show();
    return a.exec();
}
