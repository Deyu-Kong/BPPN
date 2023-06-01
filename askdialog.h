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


class AskDialog : public QDialog {
    Q_OBJECT

public:
    AskDialog(QWidget* parent = nullptr);
    void onOkButtonClicked();
    void onNoButtonClicked();
};


#endif // MYDIALOG_H


#endif // ASKDIALOG_H
