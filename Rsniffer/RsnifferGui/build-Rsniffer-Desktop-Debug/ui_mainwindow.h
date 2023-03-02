/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_rule;
    QTableWidget *tableWidget_rule;
    QPushButton *add_pushButton;
    QPushButton *delete_pushButton;
    QPushButton *apply_pushButton;
    QFrame *frame_2;
    QLabel *label_3;
    QRadioButton *accept_radioButton;
    QRadioButton *reject_radioButton;
    QPushButton *clear_pushButton;
    QLineEdit *lineEdit_rcfg;
    QPushButton *load_pushButton;
    QPushButton *save_pushButton;
    QPushButton *select_pushButton;
    QWidget *tab_log;
    QPushButton *savelog_pushButton;
    QPushButton *clearlog_pushButton;
    QPushButton *flashlog_pushButton;
    QPushButton *loadlog_pushButton;
    QTableWidget *tableWidget_logs;
    QPushButton *detailslog_pushButton;
    QPushButton *datalog_pushButton;
    QTextBrowser *textBrowser_logs;
    QPushButton *selectlog_pushButton;
    QLineEdit *lineEdit_lcfg;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(771, 494);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background-color: rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"    color: black;  /*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 751, 421));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget\n"
"{\n"
"    background-color: rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}"));
        tab_rule = new QWidget();
        tab_rule->setObjectName(QString::fromUtf8("tab_rule"));
        tableWidget_rule = new QTableWidget(tab_rule);
        tableWidget_rule->setObjectName(QString::fromUtf8("tableWidget_rule"));
        tableWidget_rule->setGeometry(QRect(10, 50, 621, 341));
        tableWidget_rule->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"    background-color: rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    selection-background-color:rgba(192,221,244);/*\350\203\214\346\231\257\350\211\262*/;/*\347\202\271\345\207\273\351\200\211\344\270\255\351\242\234\350\211\262*/\n"
"    border:1px solid #E0DDDC;/*\350\276\271\346\241\206\344\270\2721\345\203\217\347\264\240\357\274\214\347\201\260\350\211\262*/\n"
"    gridline-color:lightgray;/*\350\277\231\344\270\252\346\230\257\350\241\250\346\240\274\347\232\204\346\240\274\345\255\220\347\272\277\347\232\204\351\242\234\350\211\262\357\274\214\344\270\272\344\272\256\347\201\260*/\n"
"}\n"
""));
        add_pushButton = new QPushButton(tab_rule);
        add_pushButton->setObjectName(QString::fromUtf8("add_pushButton"));
        add_pushButton->setGeometry(QRect(640, 50, 98, 31));
        add_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        delete_pushButton = new QPushButton(tab_rule);
        delete_pushButton->setObjectName(QString::fromUtf8("delete_pushButton"));
        delete_pushButton->setGeometry(QRect(640, 90, 98, 31));
        delete_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        apply_pushButton = new QPushButton(tab_rule);
        apply_pushButton->setObjectName(QString::fromUtf8("apply_pushButton"));
        apply_pushButton->setGeometry(QRect(640, 170, 98, 31));
        apply_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        frame_2 = new QFrame(tab_rule);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(630, 290, 121, 101));
        frame_2->setStyleSheet(QString::fromUtf8("border:1px solid #E0DDDC;/*\350\276\271\346\241\206\344\270\2721\345\203\217\347\264\240\357\274\214\347\201\260\350\211\262*/"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 101, 17));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"	font: 63 10pt \"URW Bookman\";\n"
"border:none;/*\350\276\271\346\241\206\346\240\267\345\274\217*/\n"
"}"));
        accept_radioButton = new QRadioButton(frame_2);
        accept_radioButton->setObjectName(QString::fromUtf8("accept_radioButton"));
        accept_radioButton->setGeometry(QRect(10, 40, 91, 22));
        accept_radioButton->setStyleSheet(QString::fromUtf8("border:none;/*\350\276\271\346\241\206\346\240\267\345\274\217*/"));
        reject_radioButton = new QRadioButton(frame_2);
        reject_radioButton->setObjectName(QString::fromUtf8("reject_radioButton"));
        reject_radioButton->setGeometry(QRect(10, 70, 91, 22));
        reject_radioButton->setStyleSheet(QString::fromUtf8("border:none;/*\350\276\271\346\241\206\346\240\267\345\274\217*/"));
        label_3->raise();
        reject_radioButton->raise();
        accept_radioButton->raise();
        clear_pushButton = new QPushButton(tab_rule);
        clear_pushButton->setObjectName(QString::fromUtf8("clear_pushButton"));
        clear_pushButton->setGeometry(QRect(640, 130, 98, 31));
        clear_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        lineEdit_rcfg = new QLineEdit(tab_rule);
        lineEdit_rcfg->setObjectName(QString::fromUtf8("lineEdit_rcfg"));
        lineEdit_rcfg->setGeometry(QRect(130, 14, 391, 21));
        load_pushButton = new QPushButton(tab_rule);
        load_pushButton->setObjectName(QString::fromUtf8("load_pushButton"));
        load_pushButton->setGeometry(QRect(530, 10, 98, 31));
        load_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        save_pushButton = new QPushButton(tab_rule);
        save_pushButton->setObjectName(QString::fromUtf8("save_pushButton"));
        save_pushButton->setGeometry(QRect(640, 10, 98, 31));
        save_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        select_pushButton = new QPushButton(tab_rule);
        select_pushButton->setObjectName(QString::fromUtf8("select_pushButton"));
        select_pushButton->setGeometry(QRect(10, 10, 111, 31));
        select_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   \n"
"    border-style:none;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:none;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227"
                        "\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        tabWidget->addTab(tab_rule, QString());
        frame_2->raise();
        tableWidget_rule->raise();
        add_pushButton->raise();
        delete_pushButton->raise();
        apply_pushButton->raise();
        clear_pushButton->raise();
        lineEdit_rcfg->raise();
        load_pushButton->raise();
        save_pushButton->raise();
        select_pushButton->raise();
        tab_log = new QWidget();
        tab_log->setObjectName(QString::fromUtf8("tab_log"));
        tab_log->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background-color: rgb(240,240,240); /*\350\203\214\346\231\257\350\211\262*/\n"
"    color: black;  /*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}"));
        savelog_pushButton = new QPushButton(tab_log);
        savelog_pushButton->setObjectName(QString::fromUtf8("savelog_pushButton"));
        savelog_pushButton->setGeometry(QRect(420, 10, 98, 21));
        savelog_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:0px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        clearlog_pushButton = new QPushButton(tab_log);
        clearlog_pushButton->setObjectName(QString::fromUtf8("clearlog_pushButton"));
        clearlog_pushButton->setGeometry(QRect(640, 10, 98, 21));
        clearlog_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:0px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        flashlog_pushButton = new QPushButton(tab_log);
        flashlog_pushButton->setObjectName(QString::fromUtf8("flashlog_pushButton"));
        flashlog_pushButton->setGeometry(QRect(530, 10, 98, 21));
        flashlog_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:0px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        loadlog_pushButton = new QPushButton(tab_log);
        loadlog_pushButton->setObjectName(QString::fromUtf8("loadlog_pushButton"));
        loadlog_pushButton->setGeometry(QRect(310, 10, 98, 21));
        loadlog_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:0px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        tableWidget_logs = new QTableWidget(tab_log);
        tableWidget_logs->setObjectName(QString::fromUtf8("tableWidget_logs"));
        tableWidget_logs->setGeometry(QRect(10, 40, 731, 251));
        tableWidget_logs->setStyleSheet(QString::fromUtf8(""));
        detailslog_pushButton = new QPushButton(tab_log);
        detailslog_pushButton->setObjectName(QString::fromUtf8("detailslog_pushButton"));
        detailslog_pushButton->setGeometry(QRect(640, 350, 98, 27));
        detailslog_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        datalog_pushButton = new QPushButton(tab_log);
        datalog_pushButton->setObjectName(QString::fromUtf8("datalog_pushButton"));
        datalog_pushButton->setGeometry(QRect(640, 310, 98, 27));
        datalog_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    background-color:rgba(198,198,198);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:10px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    font-size:12pt;/*\345\255\227\344\275\223 \345\255\227\344\275\223\345\244\247\345\260\217*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:6px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    background-color:rgba(198,198,220);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271"
                        "\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:solid;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        textBrowser_logs = new QTextBrowser(tab_log);
        textBrowser_logs->setObjectName(QString::fromUtf8("textBrowser_logs"));
        textBrowser_logs->setGeometry(QRect(10, 300, 621, 81));
        textBrowser_logs->setStyleSheet(QString::fromUtf8("font: 9pt \"Monospace\";"));
        selectlog_pushButton = new QPushButton(tab_log);
        selectlog_pushButton->setObjectName(QString::fromUtf8("selectlog_pushButton"));
        selectlog_pushButton->setGeometry(QRect(10, 10, 51, 21));
        selectlog_pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"   \n"
"    border-style:none;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    border-radius:5px;/*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"	font: 63 11pt \"URW Bookman\";\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"    padding:0px; /*\345\241\253\350\241\254*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201*/\n"
"QPushButton:pressed\n"
"{\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-style:none;/*\350\276\271\346\241\206\346\240\267\345\274\217 solid\345\256\236\347\272\277 none\346\227\240\350\276\271\346\241\206 inset/outset 3D\350\276\271\346\241\206*/\n"
"    color: black;/*\345\255"
                        "\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"/*\351\274\240\346\240\207\346\202\254\345\201\234\347\212\266\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    background-color:rgba(198,198,190);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-color:rgba(205,205,205);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    color: black;/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}\n"
"\n"
""));
        lineEdit_lcfg = new QLineEdit(tab_log);
        lineEdit_lcfg->setObjectName(QString::fromUtf8("lineEdit_lcfg"));
        lineEdit_lcfg->setGeometry(QRect(60, 10, 241, 21));
        tabWidget->addTab(tab_log, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 771, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        add_pushButton->setText(QApplication::translate("MainWindow", "Add", nullptr));
        delete_pushButton->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        apply_pushButton->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Log by Default:", nullptr));
        accept_radioButton->setText(QApplication::translate("MainWindow", "Yes", nullptr));
        reject_radioButton->setText(QApplication::translate("MainWindow", "No", nullptr));
        clear_pushButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        load_pushButton->setText(QApplication::translate("MainWindow", "Load", nullptr));
        save_pushButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        select_pushButton->setText(QApplication::translate("MainWindow", "Configuration", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_rule), QApplication::translate("MainWindow", "Rules Filter", nullptr));
        savelog_pushButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        clearlog_pushButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        flashlog_pushButton->setText(QApplication::translate("MainWindow", "Flash", nullptr));
        loadlog_pushButton->setText(QApplication::translate("MainWindow", "Load", nullptr));
        detailslog_pushButton->setText(QApplication::translate("MainWindow", "Details", nullptr));
        datalog_pushButton->setText(QApplication::translate("MainWindow", "Data", nullptr));
        selectlog_pushButton->setText(QApplication::translate("MainWindow", "Log", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_log), QApplication::translate("MainWindow", "Capture Results", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
