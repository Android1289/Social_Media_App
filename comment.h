#ifndef COMMENT_H
#define COMMENT_H

#include <QWidget>
#include<string>
using namespace std;

namespace Ui {
class Comment;
}

class Comment : public QWidget
{
    Q_OBJECT

public:
    explicit Comment(QWidget *parent = nullptr);
    ~Comment();
    string cmnt;
    string getcmnt();

private slots:
    void on_pushButton_clicked();
    void onEnterPressed();


private:
    Ui::Comment *ui;

};

#endif // COMMENT_H
