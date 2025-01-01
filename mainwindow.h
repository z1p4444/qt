#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStack>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString operand;
    QString opcode;
    QStack<QString> operands;
    QStack<QString> opcodes;
    QMap<int,QPushButton*> digitBTNs;
    QMap<int,QPushButton*> digitBTNsStandard;
    QMap<int,QPushButton*> digitBTNsScientific;
    QMap<int,QPushButton*> digitBTNsProgramer;

    QString calculation(bool *ok=NULL);
public slots:
    void btnNumClicked();

    void btnBinaryOperatorClicked();

    void btnUnaryOperatorClicked();

    void on_btnPeriod_clicked();

    void on_btnDel_clicked();

    void on_btnClear_clicked();

    void on_btnEqual_clicked();

    void onAndButtonClicked();


    void onDigitButtonClicked(QString digit);
    void onBaseChange(int base);

public slots:
    void switchToStandardMode();
    void switchToScientificMode();
    void switchToProgrammerMode();
    void switchToDateCalculatorMode();
    void handleButtonClick(QPushButton *btn);
    void updateDisplays(int value);



    virtual void keyPressEvent(QKeyEvent *event);



private slots:
    void setBase(int base);


private:
    Ui::MainWindow *ui;
    int currentBase; // 添加这行，声明 currentBase
    QString operand1; // 存储第一个操作数
    QString operand2; // 存储第二个操作数

    QString convertToBase(int num, int base);
    int parseInput(QString input, int base);
    bool isValidDigit(QString digit);
};
#endif // MAINWINDOW_H
