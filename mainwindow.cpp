#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnNum0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    connect(ui->btnPlus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
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
        }else if(op == "-"){
            result = operand1 - operand2;
        }else if(op == "*"){
            result = operand1 * operand2;
        }else if(op == "/"){
            result = operand1 / operand2;
        }

        ui->statusbar->showMessage(QString("calculation is in progress :operand is %1,opcode is %2").arg(operands.size()).arg(opcodes.size()));



    }else
        ui->statusbar->showMessage(QString("operand is %1,opcode is %2").arg(operands.size()).arg(opcodes.size()));

    return QString::number(result);
}

void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    if(digit == "0" && operand == "0")
        digit = "";
    if(operand == "0" && digit != "0")
        operand = "";

    operand +=digit;



    ui->display->setText(operand);


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
    ui->statusbar->showMessage("last operand "+operand );
    QString opcode = qobject_cast<QPushButton*>(sender())->text();
    qDebug()<<opcode ;
    if(operand != "")
    {
        operands.push_back(operand);
        operand = "";
        opcodes.push_back(opcode);

    QString result = calculation();
    ui->display->setText(result);
    }
}

void MainWindow::on_btnEqual_clicked()
{
    if(operand != "")
    {
        operands.push_back(operand);
        operand = "";
    }
     QString result = calculation();
     ui->display->setText(result);
}

