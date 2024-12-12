#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user1.h"
#include <QDateEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <QDate>
#include <QString>
#include <QLabel>
#include <QPixmap>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix1 ("1.png");
    QPixmap pixx1 = pix1.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pix2("2.jpg");
    QPixmap pixx2 = pix2.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pix3("3.jpg");
    QPixmap pixx3 = pix3.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap pix4("4.jpg");
    QPixmap pixx4 = pix4.scaled(ui->icon_1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);



    ui-> user_1_btn->setStyleSheet("background-color: transparent;");
    ui-> user_2_btn->setStyleSheet("background-color: transparent;");
    ui-> user_3_btn->setStyleSheet("background-color: transparent;");
    ui-> user_4_btn->setStyleSheet("background-color: transparent;");
    ui->label_3->setText(storeddate);
    ui->icon_1->setPixmap(pixx1);
    ui->icon_2->setPixmap(pixx2);
    ui->icon_3->setPixmap(pixx3);
    ui->icon_4->setPixmap(pixx4);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setdate(QString s)
{
    storeddate=s;
    ui->label_3->setText(storeddate);
}
void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    storeddate = date.toString("MM-dd-yyyy");
    ui->label_3->setText(storeddate);

    if (date.isValid()) {
        day = date.day();
        month = date.month();
        year = date.year();
    }


}
//button user1
void MainWindow::on_toolButton_clicked()
{
    User1 *u1=new User1;


    u1->setbday(14,5);
    u1->setdate(storeddate);
    QPixmap p("1.png");
    u1->setpix(p);
    u1->setid("u1");
    u1->setname("Muhammad Abdullah");
    u1->show();
   // connect(this,&User1::destroyed,this,&User1::deleteLater);
    close();

}
void MainWindow::on_user_1_btn_clicked()
{
    User1 *u1=new User1;


    u1->setbday(14,5);
    u1->setdate(storeddate);
    QPixmap p("1.png");
    u1->setpix(p);
    u1->setid("u1");
    u1->setname("Muhammad Abdullah");
    u1->show();
    // connect(this,&User1::destroyed,this,&User1::deleteLater);
    close();
}
//button user2
void MainWindow::on_user_2_btn_clicked()
{
    User1 *u1=new User1;


    u1->setbday(1,1);
    u1->setdate(storeddate);
    QPixmap p("2.jpg");
    u1->setpix(p);
    u1->setid("u2");
    u1->setname("Literally Me");
    u1->show();
    // connect(this,&User1::destroyed,this,&User1::deleteLater);
    close();
}
void MainWindow::on_toolButton_2_clicked()
{
    User1 *u1=new User1;


    u1->setbday(1,1);
    u1->setdate(storeddate);
    QPixmap p("2.jpg");
    u1->setpix(p);
    u1->setid("u2");
    u1->setname("Literally Me");
    u1->show();
    // connect(this,&User1::destroyed,this,&User1::deleteLater);
    close();
}
//button user3
void MainWindow::on_user_3_btn_clicked()
{
    User1 *u1=new User1;


    u1->setbday(31,4);
    u1->setdate(storeddate);
    QPixmap p("3.jpg");
    u1->setpix(p);
    u1->setid("u3");
    u1->setname("Amna Shahid");
    u1->show();
    // connect(this,&User1::destroyed,this,&User1::deleteLater);
    close();
}
void MainWindow::on_toolButton_3_clicked()
{
    User1 *u1=new User1;


    u1->setbday(31,4);
    u1->setdate(storeddate);
    QPixmap p("3.jpg");
    u1->setpix(p);
    u1->setid("u3");
    u1->setname("Amna Shahid");
    u1->show();
    // connect(this,&User1::destroyed,this,&User1::deleteLater);
    close();
}
//button user4
void MainWindow::on_user_4_btn_clicked()
{
    User1 *u1=new User1;


    u1->setbday(14,8);
    u1->setdate(storeddate);
    QPixmap p("4.jpg");
    u1->setpix(p);
    u1->setid("u4");
    u1->setname("Fatima's Cat");
    u1->show();
    // connect(this,&User1::destroyed,this,&User1::deleteLater);
    close();
}
void MainWindow::on_toolButton_4_clicked()
{
    User1 *u1=new User1;


    u1->setbday(14,8);
    u1->setdate(storeddate);
    QPixmap p("4.jpg");
    u1->setpix(p);
    u1->setid("u4");
    u1->setname("Fatima's Cat");
    u1->show();
    // connect(this,&User1::destroyed,this,&User1::deleteLater);
    close();
}
