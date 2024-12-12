#include "list.h"
#include "ui_list.h"
#include "user1.h"
#include<string>
#include<QString>

using namespace std;

List::List(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::List)
{
    ui->setupUi(this);
}

List::~List()
{

    delete ui;
}

void List::add(string s)
{
    QString q = QString::fromStdString(s);
    ui->view->addItem(q);
}

void List ::getrows(int r)
{
    rows =r;
}

void List::del()
{
    if(ui->pushButton)
        delete ui->pushButton;
}
void List::on_pushButton_clicked()
{
    User1 *u1=new User1;

    u1->setbday(bday,bmonth);
    u1->setdate(d);
    u1->setpix(pix);
    u1->setid(id);
    u1->setname(name);
    u1->show();
    connect(this,&User1::destroyed,this,&User1::deleteLater);
    close();
}

void List:: getdate(QString s)
{
    d=s;
}
void List::setpix(QPixmap p)
{

    pix=p;


}
void List::setid(string s)
{
    id = s;

}
void List::setbday(int d,int m)
{
    bday=d;
    bmonth=m;

}
void List::setname(QString n)
{
    name=n;
}
