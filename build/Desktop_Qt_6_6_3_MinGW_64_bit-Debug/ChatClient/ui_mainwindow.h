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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QStackedWidget *stackedWidget;
    QWidget *chatPage;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QTextEdit *roomTextEdit;
    QListView *userListWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *sayLineEdit;
    QPushButton *sayButton;
    QPushButton *logoutButton;
    QWidget *loginPage;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QFrame *loginFrame;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *serverEdit;
    QLabel *usernameEdit;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("#titleLabel { \n"
"    color: #8A96FF; /* \346\267\241\350\223\235\347\264\253\350\211\262\346\226\207\345\255\227 */\n"
"    font-size: 24px'\351\273\221\344\275\223';\n"
"    font-weight: bold;\n"
"    text-align: center;\n"
"    padding: 10px;\n"
"	border:none;\n"
"    border-bottom: 2px solid #8A96FF; /* \346\267\273\345\212\240\344\270\213\350\276\271\346\241\206 */\n"
"background-color:rgba(50, 0, 75, 1) ;\n"
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
"    border: 2px solid #6A6AC9; /* \350\276\271\346\241\206\344\270\272\344\272"
                        "\256\350\223\235\347\264\253\350\211\262 */\n"
"    border-radius: 8px; /* \345\234\206\350\247\222\346\225\210\346\236\234 */\n"
"    padding: 20px;\n"
"}\n"
"/* \346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"QPushButton {\n"
"    background-color: #4C4A73; /* \346\232\227\350\223\235\347\264\253\350\211\262\350\203\214\346\231\257 */\n"
"    color: #EDEDED; /* \346\265\205\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"    border: 2px solid white ;\n"
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
"    background-color: #25233A; /* \346\267\261\350\223\235\347\264\253\350\211\262\350\203\214\346"
                        "\231\257 */\n"
"    color: #EDEDED; /* \346\265\205\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
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
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");

        verticalLayout->addWidget(titleLabel);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        chatPage = new QWidget();
        chatPage->setObjectName("chatPage");
        verticalLayout_3 = new QVBoxLayout(chatPage);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        roomTextEdit = new QTextEdit(chatPage);
        roomTextEdit->setObjectName("roomTextEdit");

        horizontalLayout->addWidget(roomTextEdit);

        userListWidget = new QListView(chatPage);
        userListWidget->setObjectName("userListWidget");
        userListWidget->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(userListWidget);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        sayLineEdit = new QLineEdit(chatPage);
        sayLineEdit->setObjectName("sayLineEdit");

        horizontalLayout_2->addWidget(sayLineEdit);

        sayButton = new QPushButton(chatPage);
        sayButton->setObjectName("sayButton");

        horizontalLayout_2->addWidget(sayButton);

        logoutButton = new QPushButton(chatPage);
        logoutButton->setObjectName("logoutButton");

        horizontalLayout_2->addWidget(logoutButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(chatPage);
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        gridLayout_2 = new QGridLayout(loginPage);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer_2 = new QSpacerItem(20, 133, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(235, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        loginFrame = new QFrame(loginPage);
        loginFrame->setObjectName("loginFrame");
        loginFrame->setFrameShape(QFrame::Shape::StyledPanel);
        loginFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(loginFrame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(loginFrame);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        serverEdit = new QLineEdit(loginFrame);
        serverEdit->setObjectName("serverEdit");

        gridLayout->addWidget(serverEdit, 0, 1, 1, 1);

        usernameEdit = new QLabel(loginFrame);
        usernameEdit->setObjectName("usernameEdit");

        gridLayout->addWidget(usernameEdit, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(loginFrame);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        loginButton = new QPushButton(loginFrame);
        loginButton->setObjectName("loginButton");

        verticalLayout_2->addWidget(loginButton);


        gridLayout_2->addWidget(loginFrame, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(235, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 135, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);

        stackedWidget->addWidget(loginPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\201\212\345\244\251\345\256\244\345\256\242\346\210\267\347\253\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "z1\347\232\204\350\201\212\345\244\251\345\256\244", nullptr));
        sayButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200:", nullptr));
        usernameEdit->setText(QCoreApplication::translate("MainWindow", "\346\230\265\347\247\260:", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
