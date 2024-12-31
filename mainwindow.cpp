#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitBTNs = {{Qt::Key_0,ui->btnNum0},
               {Qt::Key_1,ui->btnNum1},
               {Qt::Key_2,ui->btnNum2},
               {Qt::Key_3,ui->btnNum3},
               {Qt::Key_4,ui->btnNum4},
               {Qt::Key_5,ui->btnNum5},
               {Qt::Key_6,ui->btnNum6},
               {Qt::Key_7,ui->btnNum7},
               {Qt::Key_8,ui->btnNum8},
               };
    foreach (auto btn, digitBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

//    connect(ui->btnNum0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    connect(ui->btnPlus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));

    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    if(operands.size() == 2 && opcodes.size()>0){

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


     operands.push_back(QString::number(result));

        ui->statusbar->showMessage(QString("calculation is in progress :operand is %1,opcode is %2").arg(operands.size()).arg(opcodes.size()));



    }else{
        ui->statusbar->showMessage(QString("operand is %1,opcode is %2").arg(operands.size()).arg(opcodes.size()));
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

    if (operand != "") {
        operands.push_back(operand);  // 将当前操作数压入栈中
        operand = "";

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
        }
        operand =QString::number(result);
        ui->display->setText(QString::number(result));
    }
}

void MainWindow::on_btnEqual_clicked()
{
    // 如果有未处理的操作数，压入栈中
    if (operand!="") {
        operands.push_back(operand);
        operand="";
    }

    // 调用计算函数获取结果
    QString result = calculation();

    ui->display->setText(result);  // 更新显示屏幕

    // 清空操作符栈，保留计算结果以便继续操作
    opcodes.clear();
    operands.clear();  // 清空操作数栈
    operand = result;  // 将结果作为下一个操作的初始值

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"KEY";
    foreach(auto btnKey , digitBTNs.keys())
    {
        if(event->key() == btnKey)
            digitBTNs[btnKey]->animateClick();
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

