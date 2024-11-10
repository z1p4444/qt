#include "replacedialog.h"
#include "ui_replacedialog.h"
#include <QMessageBox>
ReplaceDialog::ReplaceDialog(QWidget *parent,QPlainTextEdit* textEdit)
    : QDialog(parent)
    , ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    pTextEdit = textEdit;

    ui->rbDown->setChecked(true);
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::on_btFindNext_clicked()
{
    QString target = ui->searchText->text();

    if(target == ""||pTextEdit == nullptr)
        return;
    QString text = pTextEdit->toPlainText();

    QTextCursor c = pTextEdit->textCursor();

    int index = -1;

    if(ui->rbDown->isChecked()){
        index = text.indexOf(target,c.position(),
                             ui->cbCaseSensetive->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive );
        if(index>=0){
            c.setPosition(index);
            c.setPosition(index+target.length(),QTextCursor::KeepAnchor);

            pTextEdit->setTextCursor(c);
        }
    }
    else if (ui->rbUp->isChecked())
    {
        index = text.lastIndexOf(target,c.position()-text.length()-1,
                                 ui->cbCaseSensetive->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive);
        if(index>=0){
            c.setPosition(index+target.length());
            c.setPosition(index+QTextCursor::KeepAnchor);

            pTextEdit->setTextCursor(c);
        }
    }

    if(index < 0)
    {
        QMessageBox msg(this);
        msg.setWindowTitle("z1p4444");
        msg.setText(QString("找不到 ")+target);
        msg.setWindowFlag(Qt::Drawer);
        msg.setIcon(QMessageBox::Information);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }

}


void ReplaceDialog::on_btReplace_clicked()
{

    QString target = ui->searchText->text();
    QString to = ui->targetText->text();
    if((pTextEdit!=nullptr)&&(target!="")&&(to!="")){
        QString selText = pTextEdit->textCursor().selectedText();

        if(selText == target)
        {
            pTextEdit->insertPlainText(to);
        }
        on_btFindNext_clicked();
    }
}


void ReplaceDialog::on_btReplaceAll_clicked()
{

    QString target = ui->searchText->text();
    QString to = ui->targetText->text();

    if((pTextEdit!=nullptr)&&(target!="")&&(to!="")){
        QString text = pTextEdit->toPlainText();
        text.replace(target,to,ui->cbCaseSensetive->isChecked()?Qt::CaseSensitive:
                                     Qt::CaseSensitive);
        pTextEdit->clear();

        pTextEdit->insertPlainText(text);

    }
}


void ReplaceDialog::on_btCancel_clicked()
{
    accept();
}

