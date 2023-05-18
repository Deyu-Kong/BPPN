/********************************************************************************
** Form generated from reading UI file 'people.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEOPLE_H
#define UI_PEOPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_People
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *People)
    {
        if (People->objectName().isEmpty())
            People->setObjectName(QStringLiteral("People"));
        People->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(People);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(People);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        listWidget = new QListWidget(People);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_3->addWidget(listWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        pushButton = new QPushButton(People);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        retranslateUi(People);

        QMetaObject::connectSlotsByName(People);
    } // setupUi

    void retranslateUi(QWidget *People)
    {
        People->setWindowTitle(QApplication::translate("People", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("People", "\350\257\267\346\267\273\345\212\240\346\202\250\347\232\204\344\272\262\345\217\213", Q_NULLPTR));
        pushButton->setText(QApplication::translate("People", "\346\267\273\345\212\240\344\272\262\345\217\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class People: public Ui_People {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEOPLE_H
