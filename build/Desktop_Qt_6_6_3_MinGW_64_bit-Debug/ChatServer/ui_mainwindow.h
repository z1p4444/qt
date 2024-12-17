/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *logEditor;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *startStopButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("#titleLabel { \n"
"    color: #8A96FF; /* \346\267\241\350\223\235\347\264\253\350\211\262\346\226\207\345\255\227 */\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    text-align: center;\n"
"    padding: 10px;\n"
"    border-bottom: 2px solid #8A96FF; /* \346\267\273\345\212\240\344\270\213\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"#mainFrame {\n"
"    background-color: #25233A; /* \346\267\261\350\223\235\347\264\253\350\211\262\350\203\214\346\231\257 */\n"
"    border: 2px solid #4C4A73; /* \350\276\271\346\241\206\344\270\272\346\232\227\350\223\235\347\264\253\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222\346\225\210\346\236\234 */\n"
"    padding: 15px;\n"
"}\n"
"\n"
"#loginFrame {\n"
"    background-color: #2E2B40; /* \346\233\264\346\267\261\347\232\204\347\264\253\350\211\262\350\203\214\346\231\257 */\n"
"    border: 2px solid #6A6AC9; /* \350\276\271\346\241\206\344\270\272\344\272\256\350\223\235\347\264\253\350\211\262 */\n"
"    border-radius: 8px; /* \345\234"
                        "\206\350\247\222\346\225\210\346\236\234 */\n"
"    padding: 20px;\n"
"}\n"
"/* \346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"QPushButton {\n"
"    background-color: #4C4A73; /* \346\232\227\350\223\235\347\264\253\350\211\262\350\203\214\346\231\257 */\n"
"    color: #EDEDED; /* \346\265\205\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"    border: 2px solid white;\n"
"    border-radius: 6px;\n"
"    padding: 8px 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #6A6AC9; /* \346\265\205\350\223\235\347\264\253\350\211\262\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #8A96FF; /* \346\214\211\344\270\213\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"/* \350\276\223\345\205\245\346\241\206\346\240\267\345\274\217 */\n"
"QLineEdit {\n"
"    background-color: #25233A; /* \346\267\261\350\223\235\347\264\253\350\211\262\350\203\214\346\231\257 */\n"
"    color: #EDEDED; /* \346\265\205\347\201\260\350\211\262\346\226"
                        "\207\345\255\227 */\n"
"    border: 1px solid #6A6AC9; /* \350\276\271\346\241\206\344\270\272\344\272\256\350\223\235\347\264\253\350\211\262 */\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #8A96FF; /* \350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
"QWidget {\n"
"    background-color: #000000; /* \351\273\221\350\211\262\350\203\214\346\231\257 */\n"
"    color: #EDEDED;           /* \346\265\205\347\201\260\350\211\262\346\226\207\345\255\227\357\274\214\347\241\256\344\277\235\346\226\207\345\255\227\345\217\257\350\247\201 */\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        logEditor = new QPlainTextEdit(groupBox);
        logEditor->setObjectName("logEditor");

        verticalLayout->addWidget(logEditor);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startStopButton = new QPushButton(centralwidget);
        startStopButton->setObjectName("startStopButton");

        horizontalLayout->addWidget(startStopButton);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\346\227\245\345\277\227", nullptr));
        startStopButton->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\346\234\215\345\212\241\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
