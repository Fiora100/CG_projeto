/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <drawarea.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    DrawArea *canvas;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *selectBox;
    QTableWidget *tabela;
    QPushButton *delButton;
    QPushButton *genButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(517, 282);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        canvas = new DrawArea(centralwidget);
        canvas->setObjectName("canvas");
        horizontalLayout_2 = new QHBoxLayout(canvas);
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        horizontalLayout->addWidget(canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        selectBox = new QComboBox(centralwidget);
        selectBox->setObjectName("selectBox");
        selectBox->setMinimumSize(QSize(80, 40));

        verticalLayout->addWidget(selectBox);

        tabela = new QTableWidget(centralwidget);
        tabela->setObjectName("tabela");
        tabela->setMinimumSize(QSize(80, 100));

        verticalLayout->addWidget(tabela);

        delButton = new QPushButton(centralwidget);
        delButton->setObjectName("delButton");
        delButton->setMinimumSize(QSize(80, 40));

        verticalLayout->addWidget(delButton);

        genButton = new QPushButton(centralwidget);
        genButton->setObjectName("genButton");
        genButton->setMinimumSize(QSize(80, 40));

        verticalLayout->addWidget(genButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 517, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        delButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        genButton->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
