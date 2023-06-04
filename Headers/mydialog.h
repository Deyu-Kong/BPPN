/**
 * @file mydialog.h
 * @author 孔德昱 杜忠璠
 * @date 2023/3/3
 * @brief 添加亲属信息的对话框
 */
#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QLabel>
#include <QMessageBox>
#include "persinfo.h"

/**
 * @brief MyDialog类，用于添加亲属信息
 */
class MyDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief MyDialog类的构造函数，用于初始化对话框
     * @param parent 父窗口 默认为nullptr
     */
    MyDialog(QWidget *parent = nullptr);

    /**
     * @brief 获取用户输入的亲属信息
     * @return PersInfo类型的亲属信息
     */
    PersInfo getData();

    /**
     * @brief 确认按钮的槽函数
     */
    void onOkButtonClicked();

    QLineEdit *lineEdit1; // 用于输入亲属姓名
    QLineEdit *lineEdit2; // 用于输入亲属关系
    QDateEdit *dateEdit;  // 用于输入亲属生日
};

#endif // MYDIALOG_H
