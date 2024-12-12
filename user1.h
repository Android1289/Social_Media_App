#pragma once
#include "list.h"
#include <QWidget>
#include <QDate>
#include<fstream>
#include <QStringListModel>

using namespace std;

namespace Ui {
class User1;
}

class User1 : public QWidget
{
    Q_OBJECT

public:
    explicit User1(QWidget *parent = nullptr);
    ~User1();
    void setdate(QString dd);
    void addfrnds();
    void addpages();
    void setpix(QPixmap);
    void setname(QString);
    void setbday(int ,int);
    void setid(string);

    void onListDestroyed(QObject *obj);

private slots:
    void on_pushButton_clicked();
    void on_user_1_btn_clicked();
    void on_toolButton_clicked();

    void on_user_4_btn_clicked();

   // void onListDestroyed(QObject *obj);

    void on_toolButton_4_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_3_clicked();

    void on_user_2_btn_clicked();

    void on_user_3_btn_clicked();



    void on_toolButton_6_clicked();

private:

    QPixmap pix;
    string id;
    QString name;
    Ui::User1 *ui;
    QString date;
    int bday;
    int bmonth;
    int frnds;
    char** friends;
    ifstream user;
    char** list;
    int first=1;

    int p;
    char** pages;
    char** plist;
    ifstream page;
    int pf=1;

    List *l= nullptr;
    List *l1=nullptr;
};

