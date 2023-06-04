/**
 * @file askdialog.h
 * @authors 孔德昱
 * @date 2023-6-1
 * @brief 定义AskDialog类，用于询问用户是否要保存修改的信息
*/
#ifndef ASKDIALOG_H
#define ASKDIALOG_H

#ifndef MYDIALOG_H
#define MYDIALOG_H

#include<QDialog>
#include<QGridLayout>
#include<QLineEdit>
#include<QPushButton>
#include<QDateEdit>
#include<QLabel>
#include<QMessageBox>
#include "persinfo.h"

/**
 * @brief AskDialog类，用于询问用户是否需要重新/为其他亲友确定计划日期
*/
class AskDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief AskDialog类的构造函数，用于初始化显示的内容以及连接信号和槽
     * @param parent 父窗口
     */
    AskDialog(QWidget* parent = nullptr);
    /**
     * @brief 当用户点击确认时，返回QDialog::Accepted状态，同时关闭对话框
     */
    void onOkButtonClicked();
    /**
     * @brief 当用户点击取消时，返回QDialog::Rejected状态，同时关闭对话框
    */
    void onNoButtonClicked();
};


#endif // MYDIALOG_H
#endif // ASKDIALOG_H
