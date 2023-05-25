#ifndef RELATIVEWINDOW_H
#define RELATIVEWINDOW_H

#include <QWidget>
#include "mydialog.h"
#include "persinfo.h"
#include "choosewindow.h"
#include <QInputDialog>
#include <QMessageBox>

namespace Ui {
class RelativeWindow;
}

class RelativeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RelativeWindow(QWidget *parent = nullptr);
    ~RelativeWindow();
    void keyPressEvent(QKeyEvent *event);
    void RelativeWindow::showEvent(QShowEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::RelativeWindow *ui;
};

#endif // RELATIVEWINDOW_H
