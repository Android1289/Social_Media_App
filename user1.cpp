#include "user1.h"
#include "feed.h"
#include "list.h"
#include "mainwindow.h"
#include "ui_user1.h"
#include <QDate>
#include <QDateEdit>

#include<iostream>


using namespace std;
User1::User1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::User1)
{
    user.open("users.txt");
    page.open("pages.txt");
    ui->setupUi(this);


    QPixmap pix5 ("friends.png");
    QPixmap pixx5 = pix5.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pix2("home.png");
    QPixmap pixx2 = pix2.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pix3("timeline.png");
    QPixmap pixx3 = pix3.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pix4("pages.png");
    QPixmap pixx4 = pix4.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui-> user_1_btn->setStyleSheet("background-color: transparent;");
    ui-> user_2_btn->setStyleSheet("background-color: transparent;");
    ui-> user_3_btn->setStyleSheet("background-color: transparent;");
    ui-> user_4_btn->setStyleSheet("background-color: transparent;");


    ui->icon_2->setPixmap(pixx5);
    ui->icon_3->setPixmap(pixx3);
    ui->icon_4->setPixmap(pixx4);
    ui->icon_5->setPixmap(pixx2);


}

User1::~User1()
{
    delete ui;
    delete list;
    delete friends;
}
void User1::setpix(QPixmap p)
{
    pix=p;
        QPixmap pixx1 = p.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->icon_1->setPixmap(pixx1);


}
void User1::setid(string s)
{
    id = s;
    QString d=QString::fromStdString(id);
    ui->id->setText("ID : "+d);
}
void User1::setbday(int d,int m)
{
    bday=d;
    bmonth=m;
    QString sday=QString::number(bday);
    QString smonth=QString::number(bmonth);
    ui->bd->setText("Birthday: "+sday+"/"+smonth);
}
void User1::setname(QString n)
{
    name=n;
    ui->name->setText("Name: "+name);
}
void User1::on_pushButton_clicked()
{
    MainWindow *w=new MainWindow;
    w->setdate(date);
    w->show();
    connect(this,&MainWindow::destroyed,this,&MainWindow::deleteLater);
    close();
}
void User1::setdate(QString dd)
{
    ui->date_label->setText(dd);
    date=dd;
    QDate d = QDate::fromString(dd, "MM-dd-yyyy");
    if(d.day()==bday&&d.month()==bmonth)
    {
        QPixmap pix("bday.png");
         QPixmap pixbday = pix.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->bday->setPixmap(pixbday);
    }
}

void User1::addfrnds()
{

    int users;
    List *l=new List;
    string userid;


    if(first ==1 )
    {

        if(id=="u1")
        {
        frnds=4;
        list=new char*[frnds];
        l->getrows(frnds);
        friends=new char*[frnds];
        for(int i=0;i<frnds;i++)
        {
            friends[i] = new char[3];
            list[i]=new char[80];
            friends[i][0]='u';
            friends[i][2]='\0';
        }

        friends[0][1]='3';
        friends[1][1]='4';
        friends[2][1]='7';
        friends[3][1]='9';
        }
        else if(id=="u2")
        {
            frnds=0;
            l->add("No Friends To Show");
        }
        else if(id=="u3")
        {
            frnds=6;
            list=new char*[frnds];
            l->getrows(frnds);
            friends=new char*[frnds];
            for(int i=0;i<frnds;i++)
            {
                friends[i] = new char[3];
                list[i]=new char[80];
                friends[i][0]='u';
                friends[i][2]='\0';
            }

            friends[0][1]='1';
            friends[1][1]='4';
            friends[2][1]='5';
            friends[3][1]='6';
            friends[4][1]='7';
            friends[5][1]='8';
        }
        else if(id=="u4")
        {
            frnds=6;
            list=new char*[frnds];
            l->getrows(frnds);
            friends=new char*[frnds];
            for(int i=0;i<frnds;i++)
            {
                friends[i] = new char[3];
                list[i]=new char[80];
                friends[i][0]='u';
                friends[i][2]='\0';
            }

            friends[0][1]='1';
            friends[1][1]='3';
            friends[2][1]='5';
            friends[3][1]='6';
            friends[4][1]='7';
            friends[5][1]='8';
            friends[2][1]='9';

        }

        int index=0;
        user>>users;

        for (int i = 0; i < users; i++)
        {
            user>>userid;
            char* temp = new char[80];
            do {
                user.getline(temp, 80);
            } while (user && temp[0] == '\0');

             for(int j=0;j<frnds;j++)
            {
                if(userid[1]==friends[j][1])
                {
                    list[index]=temp;
                    index++;
                }

            }
        }
        first=0;
    }
    for(int i=0;i<frnds;i++)
    {
        l->add(list[i]);
    }
    l->setWindowTitle("Friends List");
    l->getdate(date);
    l->setbday(bday,bmonth);
    l->setpix(pix);
    l->setid(id);
    l->setname(name);
    l->show();
     connect(this,&List::destroyed,this,&List::deleteLater);
    close();





}
void User1::addpages()
{
    int numofpages;
    List *l1=new List;
    string pageid;


    if(pf ==1 )
    {
        if(id=="u1")
        {
            p=4;
            plist=new char*[p];
            l1->getrows(p);
            pages=new char*[p];
            for(int i=0;i<p;i++)
            {
                pages[i] = new char[3];
                plist[i]=new char[80];
                pages[i][0]='p';
                pages[i][3]='\0';
            }
            pages[0]="p3";
            pages[1]="p4";
            pages[2]="p7";
            pages[3]="p8";
        }
        else if(id=="u2")
        {
            p=7;
            plist=new char*[p];
            l1->getrows(p);
            pages=new char*[p];
            for(int i=0;i<p;i++)
            {
                pages[i] = new char[3];
                plist[i]=new char[80];
                pages[i][0]='p';
                pages[i][3]='\0';
            }

            pages[0]="p1";
            pages[1]="p2";
            pages[2]="p3";
            pages[3]="p5";
            pages[4]="p7";
            pages[5]="p8";
            pages[6]="p9";

        }
        else if(id=="u3")
        {
            p=5;
            plist=new char*[p];
            l1->getrows(p);
            pages=new char*[p];
            for(int i=0;i<p;i++)
            {
                pages[i] = new char[3];
                plist[i]=new char[80];
                pages[i][0]='p';
                pages[i][3]='\0';
            }

            pages[0]="p2";
            pages[1]="p4";
            pages[2]="p5";
            pages[3]="p6";
            pages[4]="p8";


        }
        else if(id=="u4")
        {
            p=3;
            plist=new char*[p];
            l1->getrows(p);
            pages=new char*[p];
            for(int i=0;i<p;i++)
            {
                pages[i] = new char[3];
                plist[i]=new char[80];
            }

            pages[0]="p1";
            pages[1]="p6";
            pages[2]="p8";


        }

        int index=0;
        page>>numofpages;

        for (int i = 0; i < numofpages; i++)
        {
            page>>pageid;
            char* temp = new char[80];
            do {
                page.getline(temp, 80);
            } while (page && temp[0] == '\0');

            // for(int j=0;j<frnds;j++)
            {
                for(int j=0;j<p;j++)
                {
                    if(pageid==pages[j])
                    {
                        plist[index]=temp;
                        index++;
                    }
                }
            }
        }
        pf=0;
    }
    for(int i=0;i<p;i++)
    {
        l1->add(plist[i]);
    }
    l1->setWindowTitle("Liked Pages List");
    l1->getdate(date);
    l1->setbday(bday,bmonth);
    l1->setpix(pix);
    l1->setid(id);
    l1->setname(name);
    l1->show();
     connect(this,&List::destroyed,this,&List::deleteLater);
    close();
    // connect(this,&List::destroyed,this,&List::deleteLater);


}

void User1::on_user_1_btn_clicked()
{
    addfrnds();

}
void User1::on_toolButton_clicked()
{
    addfrnds();
}
void User1::on_user_4_btn_clicked()
{
    addpages();
}

void User1::on_toolButton_4_clicked()
{
    addpages();
}
void User1::on_toolButton_2_clicked()
{

    feed *f=new feed;
    f->getdate(date);
    f->getid(id);
    f->setWindowTitle("HOME PAGE");
    f->show();
    f->home();
     connect(this,&List::destroyed,this,&List::deleteLater);
}

void User1::on_user_2_btn_clicked()
{
    feed *f=new feed;
    f->getdate(date);
    f->getid(id);
    f->setWindowTitle("HOME PAGE");
    f->show();
    f->home();
    connect(this,&List::destroyed,this,&List::deleteLater);
}

void User1::on_toolButton_5_clicked()
{
    feed *f=new feed;
    f->getdate(date);
    f->getid(id);
    f->setWindowTitle("ALL POSTS");
    f->show();
    f->print();
    connect(this,&List::destroyed,this,&List::deleteLater);
}

void User1::on_toolButton_3_clicked()
{
    feed *f=new feed;
    f->getdate(date);
    f->getid(id);
    f->setWindowTitle("TIMELINE");
    f->show();
    f->timeline();
    connect(this,&List::destroyed,this,&List::deleteLater);
}

void User1::on_user_3_btn_clicked()
{
    feed *f=new feed;
    f->getdate(date);
    f->getid(id);
    f->setWindowTitle("TIMELINE");
    f->show();
    f->timeline();
    connect(this,&List::destroyed,this,&List::deleteLater);
}

void User1::onListDestroyed(QObject *obj)
{
    if (obj == l) {
        l = nullptr;
    } else if (obj == l1) {
        l1= nullptr;
    }
}

void User1::on_toolButton_6_clicked()
{
    std::ofstream file("shared.txt", std::ios::out);
    file.close();
}

