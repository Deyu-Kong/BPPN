#pragma execution_character_set("utf-8")
/**
 * @file main.cpp
 * @author Du Zhongfan  (Student-ID:2020302041100)
 * @date 2023/3/3     20:00
 *
 */
#include "mainwindow.h"
#include <welcome.h>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]){
    //在QApplication创建之前加入该句，解决分辨率不同导致的文字压缩问题|
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;
    class welcome we;
//    if(we.exec()==QDialog::Accepted){
//    if(we.exec()){
//        we.hide();
//        w.show();
//        return a.exec();
//    }
    we.exec();
    w.show();
    return a.exec();
}
