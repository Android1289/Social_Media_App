#ifndef LIST_H
#define LIST_H

#include <QWidget>
#include<string>

using namespace std;
namespace Ui {
class List;
}

class List : public QWidget
{
    Q_OBJECT

public:
    explicit List(QWidget *parent = nullptr);
     ~List();
    void add(string);
    void getrows(int);
    void getdate(QString);
    void setpix(QPixmap);
    void setname(QString);
    void setbday(int ,int);
    void setid(string);
    void del();

private slots:
    void on_pushButton_clicked();

private:
    Ui::List *ui;
    int rows;
    QString d;
    string id;
    QString name;
    int bday;
    int bmonth;
    QPixmap pix;
};

#endif // LIST_H
