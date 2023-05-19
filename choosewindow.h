#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class ChooseWindow;
}

class ChooseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseWindow(QWidget *parent = nullptr);
    ~ChooseWindow();
    Ui::ChooseWindow *ui;
    QStringList list;
    void setListWidget();
private slots:
    void on_pushButton_clicked();
};

#endif // CHOOSEWINDOW_H
