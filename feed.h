#ifndef FEED_H
#define FEED_H

#include "qdatetime.h"
#include <QWidget>
#include<fstream>
#include<string>
#include"comment.h"

using namespace std;
namespace Ui {
class feed;
}

class feed : public QWidget
{
    Q_OBJECT

public:
    explicit feed(QWidget *parent = nullptr);
    ~feed();
    void getdate(QString);
    void getid(string);
    void getname(string);
    void print();
    void home();
    void timeline();
    Ui::feed *ui;
    fstream posts;
    fstream users;
    fstream pages;
    fstream comments;
    fstream oposts;
    fstream shared;
    string postid;
    string name;
    string id;
    QDate date;
    QString datestring;
    int day;
    int month;
    int year;
    int pp=50;
    char** friends=nullptr;
    char** likedpages=nullptr;
    int numoffrnds;
    int numofpages;
    char** liked;
    int num=1;
    Comment *c1;
    static int share;
    static int numofcmnts;
private slots:
    void on_liked_clicked();
    void on_spinBox_valueChanged(int arg1);
    void on_like_clicked();
    void on_share_clicked();
    void on_cmnt_clicked();
    void on_toolButton_clicked();
};

#endif // FEED_H
