#ifndef END_H
#define END_H

#include <QWidget>

namespace Ui {
class End;
}

class End : public QWidget
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);
    ~End();
     void setText1(QString fpd);

private slots:
     void on_pushButton_clicked();

private:
    Ui::End *ui;
};

#endif // END_H
