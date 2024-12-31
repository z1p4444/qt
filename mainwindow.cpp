#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <math.h>
#include <QStack>
#include <QMap>
#include <functional>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitBTNsStandard = {
                         {Qt::Key_0, ui->btnNum0},
                         {Qt::Key_1, ui->btnNum1},
                         {Qt::Key_2, ui->btnNum2},
                         {Qt::Key_3, ui->btnNum3},
                         {Qt::Key_4, ui->btnNum4},
                         {Qt::Key_5, ui->btnNum5},
                         {Qt::Key_6, ui->btnNum6},
                         {Qt::Key_7, ui->btnNum7},
                         {Qt::Key_8, ui->btnNum8},
                         {Qt::Key_9, ui->btnNum9},
                         };

    digitBTNsScientific = {
                           {Qt::Key_0, ui->btnNum0_3},
                           {Qt::Key_1, ui->btnNum1_3},
                           {Qt::Key_2, ui->btnNum2_3},
                           {Qt::Key_3, ui->btnNum3_3},
                           {Qt::Key_4, ui->btnNum4_3},
                           {Qt::Key_5, ui->btnNum5_3},
                           {Qt::Key_6, ui->btnNum6_3},
                           {Qt::Key_7, ui->btnNum7_3},
                           {Qt::Key_8, ui->btnNum8_3},
                           {Qt::Key_9, ui->btnNum9_3},
                           };

    foreach (auto btn, digitBTNsStandard.values()) {
        connect(btn, &QPushButton::clicked, [this, btn]() {
            this->handleButtonClick(btn);
        });
    }
    foreach (auto btn, digitBTNsScientific.values()) {
        connect(btn, &QPushButton::clicked, [this, btn]() {
            this->handleButtonClick(btn);
        });
    }
    connect(ui->btnPlus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSign, &QPushButton::clicked, this, &MainWindow::btnUnaryOperatorClicked);

    connect(ui->btnPlus_3,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus_3,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple_3,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide_3,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnEqual_3,SIGNAL(clicked()),this,SLOT(on_btnEqual_clicked()));
    connect(ui->btnPercentage_3,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse_3,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare_3,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt_3,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnDel_3,SIGNAL(clicked()),this,SLOT(on_btnDel_clicked()));
    connect(ui->btnClear_3,SIGNAL(clicked()),this,SLOT(on_btnClear_clicked()));

    connect(ui->btnPi, SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnLn, SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnLog, &QPushButton::clicked, this, &MainWindow::btnUnaryOperatorClicked);
    connect(ui->btnSin, &QPushButton::clicked, this, &MainWindow::btnUnaryOperatorClicked);
    connect(ui->btnCos, &QPushButton::clicked, this, &MainWindow::btnUnaryOperatorClicked);
    connect(ui->btnTan, &QPushButton::clicked, this, &MainWindow::btnUnaryOperatorClicked);
    connect(ui->btnSign_3, &QPushButton::clicked, this, &MainWindow::btnUnaryOperatorClicked);
    // 创建模式菜单
    QMenu *menu = new QMenu(this);
    QAction *standardMode = menu->addAction("标准型");
    QAction *scientificMode = menu->addAction("科学型");
    QAction *programmerMode = menu->addAction("程序员型");
    QAction *dateCalculatorMode = menu->addAction("日期计算");

    // 将菜单绑定到按钮
    ui->menuButton->setMenu(menu);

    // 连接菜单的信号到槽函数
    connect(standardMode, &QAction::triggered, this, &MainWindow::switchToStandardMode);
    connect(scientificMode, &QAction::triggered, this, &MainWindow::switchToScientificMode);
    connect(programmerMode, &QAction::triggered, this, &MainWindow::switchToProgrammerMode);
    connect(dateCalculatorMode, &QAction::triggered, this, &MainWindow::switchToDateCalculatorMode);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    if(operands.size() == 2 && !opcodes.isEmpty()){

        double operand1 = operands.front().toDouble();
        operands.pop_front();
        double operand2 = operands.front().toDouble();
        operands.pop_front();

        QString op = opcodes.front();
        opcodes.pop_front();


        if(op == "+"){
            result = operand1 + operand2;
        }else if(op == "_"){
            result = operand1 - operand2;
        }else if(op == "×"){
            result = operand1 * operand2;
        }else if(op == "/"&&operand2 !=0){
            result = operand1 / operand2;
        }else if (op == "/" && operand2 == 0) {
            ui->statusbar->showMessage("Error: Division by zero");
            return "Error";
        }


        // 保留结果
        operands.push_back(QString::number(result));
        ui->statusbar->showMessage(QString("Calculation complete: operand count %1, opcode count %2")
                                       .arg(operands.size()).arg(opcodes.size()));



    }else{
        ui->statusbar->showMessage(QString("Invalid state: operand count %1, opcode count %2")
                                       .arg(operands.size()).arg(opcodes.size()));
    }

    return QString::number(result);
}

void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    if(digit== "0"&&operand=="0")
        digit= "";

    if(operand == "0"&&digit!="0")
        operand="";



    operand += digit;
    ui->display->setText(operand);  // 更新显示
}






void MainWindow::on_btnPeriod_clicked()
{

    if(!operand.contains("."))
        operand += qobject_cast<QPushButton*>(sender())->text();
     ui->display->setText(operand);
}


void MainWindow::on_btnDel_clicked()
{

    operand = operand.left(operand.length() - 1);
    ui->display->setText(operand);

}


void MainWindow::on_btnClear_clicked()
{
    operand.clear();
    ui->display->setText(operand);

}

void MainWindow::btnBinaryOperatorClicked()
{
    ui->statusbar->showMessage("Last operand: " + operand);

    QString opcode = qobject_cast<QPushButton*>(sender())->text();
    qDebug()<<opcode;

    if (!operand.isEmpty()) {
        operands.push_back(operand);  // 将当前操作数压入栈中
        operand.clear();

    }
    // 如果已经有两个操作数和一个操作符，则立即计算
    if (operands.size() == 2 && !opcodes.isEmpty()) {
        QString result = calculation();
        ui->display->setText(result);
    }
    opcodes.push_back(opcode);
        // QString result = calculation();
        // ui->display->setText(result);

    ui->statusbar->showMessage("Opcode pressed: " + opcode);
}


void MainWindow::btnUnaryOperatorClicked()
{
    qDebug()<<operand ;
    if(operand != ""){
        double result = operand.toDouble();
        operand = "";

        QString op = qobject_cast<QPushButton *>(sender())->text();

        if(op == "%"){
            result /=100.0;
        }else if(op == "1/X"){
            if(result != 0){
            result = 1/result;
            }else{
                ui->statusbar->showMessage("Error: Division by zero");
                return;
            }
        }
        else if(op == "X^2"){
            result *= result;
        }else if(op == "√x"){
            result = sqrt(result);
        }else if(op == "±"){
            result =  -result;
        }else if (op == "ln"){
            result = log(result); // 计算自然对数
        } else if (op == "log") {
            result = log10(result); // 计算常用对数
        } else if (op == "sin") {
            result = sin(result); // 计算正弦值
        } else if (op == "cos") {
            result = cos(result); // 计算余弦值
        } else if (op == "tan") {
            result = (result); // 计算正切值
         } else if (op == "±") {
           result = -result; // 改变符号
        }else if (op == "Π") {
            result = M_PI;
            operand = QString::number(result);
            ui->display->setText(operand);
         }

        operand =QString::number(result);
        ui->display->setText(QString::number(result));
    }
}

void MainWindow::on_btnEqual_clicked()
{
    // 如果有未处理的操作数，压入栈中
    if (!operand.isEmpty()) {
        operands.push_back(operand);
        operand.clear();
    }

    // 调用计算函数获取结果
    QString result = calculation();

    if (result != "Error") {
        ui->display->setText(result);  // 更新显示屏幕
        operands.clear();  // 清空操作数栈
        opcodes.clear();   // 清空操作符栈
        operand = result;  // 将结果作为下一个操作的初始值
    } else {
        // 如果发生错误，清空所有状态
        operands.clear();
        opcodes.clear();
        operand.clear();
    }

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"KEY";
    int currentPage = ui->stackedWidget->currentIndex();
    QMap<int, QPushButton*> *activeDigitBTNs;

    if (currentPage == 0) {
        activeDigitBTNs = &digitBTNsStandard;
    } else if (currentPage == 3) {
        activeDigitBTNs = &digitBTNsScientific;
    } else {
        return;
    }

    foreach (auto key, activeDigitBTNs->keys()) {
        if (event->key() == key) {
            QPushButton *btn = activeDigitBTNs->value(key);
            btn->animateClick();
            break;
        }
    }
    if (event->key() == Qt::Key_Plus) {
        ui->btnPlus->animateClick();
    } else if (event->key() == Qt::Key_Minus) {
        ui->btnMinus->animateClick();
    } else if (event->key() == Qt::Key_Asterisk) {
        ui->btnMultiple->animateClick();
    } else if (event->key() == Qt::Key_Slash) {
        ui->btnDivide->animateClick();
    } else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        ui->btnEqual->animateClick();
    }
    // if(event->key() == Qt::Key_0)
    //     ui->btnNum0->animateClick();
    // else if(event->key()== Qt::Key_1)
    //     ui->btnNum1->animateClick();


}
void MainWindow::switchToStandardMode()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->statusbar->showMessage("已切换到标准型");
}

void MainWindow::switchToScientificMode()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->statusbar->showMessage("已切换到科学型");
}

void MainWindow::switchToProgrammerMode()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->statusbar->showMessage("已切换到程序员型");
}

void MainWindow::switchToDateCalculatorMode()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->statusbar->showMessage("已切换到日期计算模式");
}

void MainWindow::handleButtonClick(QPushButton *btn)
{
    int currentPage = ui->stackedWidget->currentIndex();

    if (currentPage == 0) { // 标准模式
        ui->statusbar->showMessage("Standard mode button clicked: " + btn->text());
        operand += btn->text();
        ui->display->setText(operand);
    } else if (currentPage == 1) {
        ui->statusbar->showMessage("Scientific mode button clicked: " + btn->text());
        operand += btn->text();
        ui->display->setText(operand);
    }
}



