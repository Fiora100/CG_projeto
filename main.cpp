#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(R"(
        QWidget {
            background-color: #f5f5f5;
            font-family: "Segoe UI", sans-serif;
            font-size: 10pt;
        }
        QPushButton {
            background-color: #0078d7;
            color: white;
            border: none;
            border-radius: 5px;
            padding: 8px 16px;
        }
        QPushButton:hover {
            background-color: #005fa1;
        }
        QPushButton:pressed {
            background-color: #004b80;
        }
        QComboBox {
            background-color: #ffffff;
            border: 1px solid #cccccc;
            border-radius: 5px;
            padding: 5px 10px;
            min-width: 80px;
        }
        QComboBox:hover {
            border: 1px solid #999999;
        }
        QComboBox QAbstractItemView {
            background-color: #ffffff;
            border: 1px solid #cccccc;
            selection-background-color: #0078d7;
            selection-color: white;
        }
        QLineEdit {
            border: 1px solid #cccccc;
            border-radius: 5px;
            padding: 5px 10px;
            background-color: white;
        }
    )");

    MainWindow w;
    w.show();
    return a.exec();
}
