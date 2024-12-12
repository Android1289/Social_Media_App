#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include <QMainWindow>
#include <QDate>
#include <QLabel>
#include <QPixmap>



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
    void setdate(QString);

private slots:
    void on_toolButton_clicked();
    void on_user_1_btn_clicked();
    void on_dateEdit_userDateChanged(const QDate &date);



    void on_user_2_btn_clicked();

    void on_toolButton_2_clicked();

    void on_user_3_btn_clicked();

    void on_toolButton_3_clicked();

    void on_user_4_btn_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *label_3;
    int day=1;
    int month =1;
    int year = 2000;
    QString storeddate="01-01-2000";


};
#endif // MAINWINDOW_H
