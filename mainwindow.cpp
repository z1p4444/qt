#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::binaryOperatorClicked()
{

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

