#ifndef PEOPLE_H
#define PEOPLE_H

#include <QWidget>
#include "mydialog.h"
#include "persinfo.h"
#include "choosewindow.h"
#include <QInputDialog>
#include <QMessageBox>
namespace Ui {
class People;
}

class People : public QWidget
{
    Q_OBJECT

public:
    explicit People(QWidget *parent = nullptr);
    ~People();
    void keyPressEvent(QKeyEvent *event);
    void People::showEvent(QShowEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::People *ui;
};

#endif // PEOPLE_H
