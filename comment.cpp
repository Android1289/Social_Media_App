#include "comment.h"
#include "ui_comment.h"
#include<string>
#include <QTextEdit>
#include <QKeyEvent>
using namespace std;

Comment::Comment(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Comment)
{
    ui->setupUi(this);
}

Comment::~Comment()
{
    delete ui;
}

void Comment::on_pushButton_clicked()
{
    QString s;
    s=ui->textEdit->toPlainText();
    cmnt=s.toStdString();
    ui->textEdit->clear();
}

void Comment::onEnterPressed()
{
    on_pushButton_clicked();
}

string Comment::getcmnt()
{
    return cmnt;
}
