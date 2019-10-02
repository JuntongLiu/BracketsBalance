/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/
/*
 * This is a compiler auto generated file. To build this program with the Qt IDE,
 * this file will be regenerated from the UI file and overriten each time doing compiling.
 * Since the UI will not be changed any more, I will create a make file so that
 * the program can be build using this file and the main.cpp, mainwindow.cpp files
 * independently from the IDE later.
 *
 *                                      JT
 */

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *label_Title;
    QLabel *label_TextEdit;
    QTextEdit *textEdit;
    QLabel *label_Result;
    QLabel *label_ResultArea;
    QPushButton *pushButton_Run;
    QPushButton *pushButton_Clean;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(9, 9, 381, 221));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        label_Title = new QLabel(frame);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setGeometry(QRect(70, 20, 231, 20));
        QFont font;
        font.setPointSize(12);
        label_Title->setFont(font);

        label_TextEdit = new QLabel(frame);
        label_TextEdit->setObjectName(QString::fromUtf8("label_TextEdit"));
        label_TextEdit->setGeometry(QRect(30, 60, 261, 17));

        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 80, 251, 61));

        label_Result = new QLabel(frame);
        label_Result->setObjectName(QString::fromUtf8("label_Result"));
        label_Result->setGeometry(QRect(30, 160, 64, 17));

        label_ResultArea = new QLabel(frame);
        label_ResultArea->setObjectName(QString::fromUtf8("label_ResultArea"));
        label_ResultArea->setGeometry(QRect(80, 180, 271, 20));

        pushButton_Run = new QPushButton(frame);
        pushButton_Run->setObjectName(QString::fromUtf8("pushButton_Run"));
        pushButton_Run->setGeometry(QRect(300, 80, 61, 27));

        pushButton_Clean = new QPushButton(frame);
        pushButton_Clean->setObjectName(QString::fromUtf8("pushButton_Clean"));
        pushButton_Clean->setGeometry(QRect(300, 110, 61, 27));
        MainWindow->setCentralWidget(centralWidget);

        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        MainWindow->setMenuBar(menuBar);

        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_Title->setText(QCoreApplication::translate("MainWindow", "Bracket Balance Program UI ", nullptr));
        label_TextEdit->setText(QCoreApplication::translate("MainWindow", "Type in string with brackets and run:", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type in a string with brackets and click Run...", nullptr));
        label_Result->setText(QCoreApplication::translate("MainWindow", "Result:", nullptr));
        label_ResultArea->setText(QString());
        pushButton_Run->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        pushButton_Clean->setText(QCoreApplication::translate("MainWindow", "Clean", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
