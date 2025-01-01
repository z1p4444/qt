#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <math.h>
#include <QStack>
#include <QMap>
#include <functional>
#include <QString>
#include <bitset>
#include <QRegularExpression>
#include <QDate>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkManager(new QNetworkAccessManager(this))  // 初始化 networkManager
{
    ui->setupUi(this);
    // 初始化货币与容量单位
    initCurrencyData();
    initCapacityData();

    // 绑定信号和槽
    connect(ui->convertCurrencyButton, &QPushButton::clicked, this, &MainWindow::fetchLiveRates);
    connect(ui->convertCapacityButton, &QPushButton::clicked, this, &MainWindow::convertCapacity);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::handleNetworkReply);
    currentBase = 10; // 默认进制为十进制

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
    // digitBTNsProgramer = {
    //                        {Qt::Key_0, ui->btnNum0_5},
    //                        {Qt::Key_1, ui->btnNum1_5},
    //                        {Qt::Key_2, ui->btnNum2_5},
    //                        {Qt::Key_3, ui->btnNum3_5},
    //                        {Qt::Key_4, ui->btnNum4_5},
    //                        {Qt::Key_5, ui->btnNum5_5},
    //                        {Qt::Key_6, ui->btnNum6_5},
    //                        {Qt::Key_7, ui->btnNum7_5},
    //                        {Qt::Key_8, ui->btnNum8_5},
    //                        {Qt::Key_9, ui->btnNum9_5},
    //                         {Qt::Key_A, ui->btnA},
    //                         {Qt::Key_B, ui->btnB},
    //                         {Qt::Key_C, ui->btnC},
    //                         {Qt::Key_D, ui->btnD},
    //                         {Qt::Key_E, ui->btnE},
    //                         {Qt::Key_F, ui->btnF},
    //                        };

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
    // foreach (auto btn, digitBTNsProgramer.values()) {
    //     connect(btn, &QPushButton::clicked, [this, btn]() {
    //         this->handleButtonClick(btn);
    //     });
    // }
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

    connect(ui->btnPlus_4,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus_4,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple_4,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide_4,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnEqual_4,SIGNAL(clicked()),this,SLOT(on_btnEqual_clicked()));
    connect(ui->btnPercentage_4,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnDel_4,SIGNAL(clicked()),this,SLOT(on_btnDel_clicked()));
    connect(ui->btnClear_4,SIGNAL(clicked()),this,SLOT(on_btnClear_clicked()));
    connect(ui->btnSign_4, &QPushButton::clicked, this, &MainWindow::btnUnaryOperatorClicked);
    connect(ui->btnHex, &QPushButton::clicked, this, [=]() { setBase(16); });
    connect(ui->btnDec, &QPushButton::clicked, this, [=]() { setBase(10); });
    connect(ui->btnOct, &QPushButton::clicked, this, [=]() { setBase(8); });
    connect(ui->btnBin, &QPushButton::clicked, this, [=]() { setBase(2); });
    connect(ui->btnNum0_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("0"); });
    connect(ui->btnNum1_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("1"); });
    connect(ui->btnNum2_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("2"); });
    connect(ui->btnNum3_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("3"); });
    connect(ui->btnNum4_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("4"); });
    connect(ui->btnNum5_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("5"); });
    connect(ui->btnNum6_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("6"); });
    connect(ui->btnNum7_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("7"); });
    connect(ui->btnNum8_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("8"); });
    connect(ui->btnNum9_5, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("9"); });
    connect(ui->btnA, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("A"); });
    connect(ui->btnB, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("B"); });
    connect(ui->btnC, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("C"); });
    connect(ui->btnD, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("D"); });
    connect(ui->btnE, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("E"); });
    connect(ui->btnF, &QPushButton::clicked, this, [=]() { onDigitButtonClicked("F"); });
    connect(ui->btnAND,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnOR,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnNOT,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnXOR,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnLeft,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnRight,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));


    connect(ui->btnCalculateDays, &QPushButton::clicked, this, &MainWindow::on_btnCalculateDays_clicked);

    // 创建模式菜单
    QMenu *menu = new QMenu(this);
    QAction *standardMode = menu->addAction("标准型");
    QAction *scientificMode = menu->addAction("科学型");
    QAction *programmerMode = menu->addAction("程序员型");
    QAction *dateCalculatorMode = menu->addAction("日期计算");
    QAction *CurrencyAndCapacityMode = menu->addAction("货币和容量计算");

    // 将菜单绑定到按钮
    ui->menuButton->setMenu(menu);

    // 连接菜单的信号到槽函数
    connect(standardMode, &QAction::triggered, this, &MainWindow::switchToStandardMode);
    connect(scientificMode, &QAction::triggered, this, &MainWindow::switchToScientificMode);
    connect(programmerMode, &QAction::triggered, this, &MainWindow::switchToProgrammerMode);
    connect(dateCalculatorMode, &QAction::triggered, this, &MainWindow::switchToDateCalculatorMode);
    connect(CurrencyAndCapacityMode, &QAction::triggered, this, &MainWindow::switchToCurrencyAndCapacityMode);
}
void MainWindow::updateDisplays(int value)
{
    // 将 `operand` 转换为整数
    bool ok;
    value = operand.toInt(&ok, currentBase); // 使用当前基数解析 `operand`
    if (!ok) {
        value = 0; // 如果解析失败，默认为 0
    }
    // 更新当前输入框
    ui->display->setText(operand);

    // 转换并显示为不同进制
    ui->displayHex->setText(QString::number(value, 16).toUpper());
    ui->displayDec->setText(QString::number(value, 10));
    ui->displayOct->setText(QString::number(value, 8));
    ui->displayBin->setText(QString::number(value, 2));
}
void MainWindow::setBase(int base)
{
    currentBase = base;
    operand.clear();
    updateDisplays(base);
}


MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    if (operands.size() < 2 || opcodes.isEmpty()) {
        ui->statusbar->showMessage("Waiting for more inputs...");
        return operands.isEmpty() ? "0" : operands.back();
    }
    while(operands.size() == 2 && !opcodes.isEmpty()){

        double operand1 = operands.front().toDouble();
        operands.pop_front();
        double operand2 = operands.front().toDouble();
        operands.pop_front();

        QString op = opcodes.front();
        opcodes.pop_front();


        if(op == "+"){
            result = operand1 + operand2;
            ui->display->setText(QString::number(result));
        }else if(op == "_"){
            result = operand1 - operand2;
        }else if(op == "×"){
            result = operand1 * operand2;
        }else if(op == "/"&&operand2 !=0){
            result = operand1 / operand2;
        }else if (op == "/" && operand2 == 0) {
            ui->statusbar->showMessage("Error: Division by zero");
            return "Error";
        }else if (op == "AND") {  // 按位与
            result = static_cast<int>(operand1) & static_cast<int>(operand2);
        } else if (op == "|") {  // 按位或
            result = static_cast<int>(operand1) | static_cast<int>(operand2);
        } else if (op == "^") {  // 按位异或
            result = static_cast<int>(operand1) ^ static_cast<int>(operand2);
        } else if (op == "<<") { // 左移
            result = static_cast<int>(operand1) << static_cast<int>(operand2);
        } else if (op == ">>") { // 右移
            result = static_cast<int>(operand1) >> static_cast<int>(operand2);
        } else if (op == "~") {
            if (operands.size() != 1) {
                ui->statusbar->showMessage("Error: Unary operator '~' requires exactly one operand");
                return "Error";
            }
            result = ~static_cast<int>(operand1);
        }else {
            ui->statusbar->showMessage("Error: Unknown operator");
            return "Error";
        }


        // 保留结果
        operands.push_front(QString::number(result));
        ui->statusbar->showMessage(QString("Calculation complete: operand count %1, opcode count %2")
                                       .arg(operands.size()).arg(opcodes.size()));



    }
    if(!operands.isEmpty()){
        result = operands.front().toDouble();
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
    ui->displayDec->setText(operand);
    updateDisplays(currentBase);
}


void MainWindow::on_btnClear_clicked()
{
    operand.clear();
    ui->display->setText(operand);
    ui->displayDec->setText(operand);
    updateDisplays(currentBase);
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
    // 如果已经有两个操作数和一个操作符，则计算
    while (operands.size() == 2 && !opcodes.isEmpty()) {
        bool ok;
        QString result = calculation(&ok);
        if (ok && result != "Error") {
            ui->display->setText(result);
            operand = result; // 将结果作为下一个操作的初始值
            operands.clear();              // 清空操作数栈
            operands.push_back(operand);   // 更新栈中的操作数
        } else{
            ui->display->setText(result);
        }

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
    bool ok;
    QVector<double> decimalOperands;

    // 如果有未处理的操作数，压入栈中
    if (!operand.isEmpty()) {
        operands.push_back(operand);
        operand.clear();
    }

    // 将所有操作数从当前进制转换为十进制
    for (const QString& op : operands) {
        double value = op.toDouble(&ok); // 转换为浮点数（当前基数的支持可扩展）
        if (!ok) {
            ui->display->setText("Error");
            operands.clear();
            opcodes.clear();
            return;
        }
        decimalOperands.push_back(value);
    }

    // 调用计算函数进行计算
    QString result = calculation(&ok);

    if (ok && result != "Error") {
        // 在十进制框中显示结果
        //ui->displayDec->setText(result);

        // 清空栈，准备新操作
        operands.clear();
        opcodes.clear();

        // 将结果作为下一个操作的初始值
        operand = result;

        // 更新其他进制框
        int decimalResult = result.toInt(&ok, 10); // 确保结果可解析为十进制整数
        if (ok) {
            ui->displayHex->setText(QString::number(decimalResult, 16).toUpper());
            ui->displayOct->setText(QString::number(decimalResult, 8));
            ui->displayBin->setText(QString::number(decimalResult, 2));
        }
    } else {
        // 如果发生错误，清空所有状态
        operands.clear();
        opcodes.clear();
        operand.clear();
        ui->display->setText("Error");
    }

    // 确保更新状态栏和显示框
    updateDisplays(currentBase);
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
void MainWindow::switchToCurrencyAndCapacityMode()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->statusbar->showMessage("已切换到货币容量计算模式");
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
    }else if (currentPage == 2) {
        ui->statusbar->showMessage("Programer mode button clicked: " + btn->text());
        operand += btn->text();
        // ui->displayHex->setText(operand);
        //默认十进制
        //ui->displayDec->setText(operand);
        // ui->displayOct->setText(operand);
        // ui->displayBin->setText(operand);
    }
}


QString convertToBase(int num, int base) {
    if (base == 2) return QString::fromStdString(std::bitset<32>(num).to_string());
    if (base == 8) return QString::number(num, 8);
    if (base == 16) return QString::number(num, 16).toUpper();
    return QString::number(num); // 默认十进制
}

// 从字符串解析为十进制
int parseInput(QString input, int base) {
    return input.toInt(nullptr, base);
}

int bitwiseAnd(int a, int b) { return a & b; }
int bitwiseOr(int a, int b) { return a | b; }
int bitwiseXor(int a, int b) { return a ^ b; }
int bitwiseNot(int a) { return ~a; }
int leftShift(int a, int shift) { return a << shift; }
int rightShift(int a, int shift) { return a >> shift; }

void MainWindow::onBaseChange(int base) {
    currentBase = base;
    int value = parseInput(ui->display->text(), currentBase);
    ui->display->setText(convertToBase(value, base));
}

void MainWindow::onAndButtonClicked() {
    int num1 = parseInput(operand1, currentBase);
    int num2 = parseInput(operand2, currentBase);
    int result = bitwiseAnd(num1, num2);
    ui->display->setText(convertToBase(result, currentBase));
}

void MainWindow::onDigitButtonClicked(QString digit) {


        // 检查输入是否合法
       QRegularExpression regex;
        switch (currentBase) {
        case 16:
            regex =QRegularExpression("[0-9a-fA-F]"); // 十六进制合法字符
            break;
        case 10:
            regex = QRegularExpression("[0-9]"); // 十进制合法字符
            break;
        case 8:
            regex =QRegularExpression("[0-7]"); // 八进制合法字符
            break;
        case 2:
            regex =QRegularExpression("[0-1]"); // 二进制合法字符
            break;
        }

        if (regex.match(digit).hasMatch()) {
            operand.append(digit); // 如果输入合法，添加到 `operand`
        } else {
            // 非法输入时，可提示用户或忽略
            return;
        }

        updateDisplays(currentBase); // 更新显示


}

bool MainWindow::isValidDigit(QString digit) {
    if (currentBase == 2) return digit == "0" || digit == "1";
    if (currentBase == 8) return digit >= "0" && digit <= "7";
    if (currentBase == 10) return digit >= "0" && digit <= "9";
    if (currentBase == 16) return (digit >= "0" && digit <= "9") || (digit >= "A" && digit <= "F");
    return false;
}

int MainWindow::parseInput(QString input, int base) {
    return input.toInt(nullptr, base);
}
QString MainWindow::convertToBase(int num, int base) {
    if(base<2||base>16) {
        return "Error: Unsupported base";
    }

    QString result;
    const char *digits = "0123456789ABCDEF";

    // 处理负数
    bool isNegative = num < 0;
    if (isNegative) {
        num = -num;
    }

    do {
        int remainder = num % base;
        result.prepend(digits[remainder]);
        num /= base;
    } while (num > 0);

    if (isNegative) {
        result.prepend('-');
    }

    return result;
}




void MainWindow::on_btnCalculateDays_clicked()
{
    // 获取日期
    QDate startDate = ui->dateEditStart->date();
    QDate endDate = ui->dateEditEnd->date();

    // 计算日期差
    int daysDifference = startDate.daysTo(endDate);

    // 显示结果
    ui->display->setText(QString("日期差：%1 天").arg(daysDifference));
}
void MainWindow::initCurrencyData()
{
    // 初始化汇率（默认值）
    currencyRates["USD_TO_EUR"] = 0.85;
    currencyRates["EUR_TO_CNY"] = 7.8;
    currencyRates["USD_TO_CNY"] = 7.0;

    // 设置货币选项
    ui->currencyFromCombo->addItems({"USD", "EUR", "CNY"});
    ui->currencyToCombo->addItems({"USD", "EUR", "CNY"});
}

void MainWindow::initCapacityData()
{
    // 设置容量单位与换算比例（相对于升）
    capacityRates["L_TO_ML"] = 1000.0;
    capacityRates["L_TO_GALLON"] = 0.264172;
    capacityRates["ML_TO_L"] = 0.001;

    // 设置容量单位选项
    ui->capacityFromCombo->addItems({"L", "ML", "GALLON"});
    ui->capacityToCombo->addItems({"L", "ML", "GALLON"});
}


void MainWindow::convertCurrency()
{
    QString from = ui->currencyFromCombo->currentText();
    QString to = ui->currencyToCombo->currentText();
    double amount = ui->currencyInput->text().toDouble();

    QString key = from + "_TO_" + to;
    if (currencyRates.contains(key)) {
        double rate = currencyRates[key];
        double result = amount * rate;
        ui->display->setText(QString::number(result));
    } else {
        ui->statusbar->showMessage("未找到对应汇率", 3000);
    }
}
void MainWindow::fetchLiveRates()
{
    // 替换为您选择的汇率API的URL和密钥
    QString apiKey = "091e5c8d3d4b8f91087e3f25";  // 替换为您的API密钥
    QString url = QString("https://v6.exchangerate-api.com/v6/091e5c8d3d4b8f91087e3f25/latest/USD").arg(apiKey);

    // 定义 QNetworkRequest 对象
    QUrl requestUrl(url);
    QNetworkRequest request(requestUrl);
    qDebug() << "Requesting URL: " << requestUrl.toString();
    // 发起网络请求
    networkManager->get(request);  // 发送 GET 请求
}
void MainWindow::handleNetworkReply(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Response Data:" << responseData;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();
            if (jsonObj.contains("conversion_rates")) {
                QJsonObject rates = jsonObj["conversion_rates"].toObject();

                // 提取一些示例汇率
                double usdToEur = rates["EUR"].toDouble();
                double usdToCny = rates["CNY"].toDouble();
                qDebug() << "USD to EUR:" << usdToEur;
                qDebug() << "USD to CNY:" << usdToCny;

                // 更新到类成员变量
                currencyRates["USD_TO_EUR"] = usdToEur;
                currencyRates["USD_TO_CNY"] = usdToCny;

                // 在 UI 上显示成功消息
                ui->statusbar->showMessage("汇率更新成功！", 3000);
            } else {
                qDebug() << "JSON does not contain 'conversion_rates'";
                ui->statusbar->showMessage("API 返回格式错误！", 3000);
            }
        } else {
            qDebug() << "Failed to parse JSON!";
            ui->statusbar->showMessage("解析返回数据失败！", 3000);
        }
    } else {
        qDebug() << "Network Error:" << reply->errorString();
        ui->statusbar->showMessage("网络错误: " + reply->errorString(), 3000);
    }

    reply->deleteLater();  // 清理资源
}
void MainWindow::convertCapacity()
{
    QString from = ui->capacityFromCombo->currentText();
    QString to = ui->capacityToCombo->currentText();
    double amount = ui->capacityInput->text().toDouble();

    QString key = from + "_TO_" + to;
    if (capacityRates.contains(key)) {
        double rate = capacityRates[key];
        double result = amount * rate;
        ui->display->setText(QString::number(result));
    } else {
        ui->statusbar->showMessage("未找到对应容量单位换算", 3000);
    }
}

void MainWindow::on_convertCurrencyButton_clicked()
{
    double inputValue = ui->inputSpinBox->value();
    QString fromCurrency = ui->currencyFromCombo->currentText();
    QString toCurrency = ui->currencyToCombo->currentText();

    double rate = 1.0; // 默认汇率为1（即无转换）
    if (fromCurrency == "USD" && toCurrency == "EUR") {
        rate = currencyRates["USD_TO_EUR"];
    } else if (fromCurrency == "USD" && toCurrency == "CNY") {
        rate = currencyRates["USD_TO_CNY"];
    }

    double result = inputValue * rate;
    updateCurrencyResultLabel(result);
}
void MainWindow::updateCurrencyResultLabel(double result)
{
    ui->display->setText(QString::number(result, 'f', 2));
}
