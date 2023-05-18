#ifndef MYDIALOG_H
#define MYDIALOG_H

#include<QDialog>
#include<QGridLayout>
#include<QLineEdit>
#include<QPushButton>
#include<QDateEdit>
#include "persinfo.h"

class MyDialog : public QDialog {
    Q_OBJECT

public:
    MyDialog(QWidget* parent = nullptr);
    PersInfo getData();

private:
    QLineEdit* lineEdit1;
    QLineEdit* lineEdit2;
    QDateEdit* dateEdit;
};


#endif // MYDIALOG_H
