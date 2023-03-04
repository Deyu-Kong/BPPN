/**
 * @file main.cpp
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/3     20:00
 *
 */
#include "mainwindow.h"
#include <welcome.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    class welcome we;
    if(we.exec()==QDialog::Accepted){
//        we.hide();
        w.show();
        return a.exec();
    }
//    w.show();
//    return a.exec();
}
