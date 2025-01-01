#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStack>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>
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
    void switchToCurrencyAndCapacityMode();
    void handleButtonClick(QPushButton *btn);
    void updateDisplays(int value);



    virtual void keyPressEvent(QKeyEvent *event);



private slots:
    void setBase(int base);


    void on_btnCalculateDays_clicked();
private slots:

    void convertCapacity();
private:
    Ui::MainWindow *ui;
    int currentBase; // 添加这行，声明 currentBase
    QString operand1; // 存储第一个操作数
    QString operand2; // 存储第二个操作数

    QString convertToBase(int num, int base);
    int parseInput(QString input, int base);
    bool isValidDigit(QString digit);

    QMap<QString, double> currencyRates;  // 货币汇率表
    QMap<QString, double> capacityRates;  // 容量换算表

    QNetworkAccessManager *networkManager;  // 网络管理器

    void initCurrencyData();
    void initCapacityData();
private slots:
    void convertCurrency();
    void fetchLiveRates();  // 获取实时汇率
    void handleNetworkReply(QNetworkReply* reply);  // 处理网络回复
    void on_convertCurrencyButton_clicked();
    void updateCurrencyResultLabel(double result);
};
#endif // MAINWINDOW_H
