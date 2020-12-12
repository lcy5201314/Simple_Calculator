#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <bits/stdc++.h>
#include <QMainWindow>
#include <QString>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*
     * 定义：按键处理函数；
     * 参数1：按键值 并且参数2为空
     * 参数2；运算符 并且参数1为0
    */
    void btn_logic(int x , QString i = " ");

    void den_logic();

public:
    QString a;        //a来存储内容
    QStringList b;    //b来存储运算符 b[0]数字1 b[1]运算符 b[2]数字2

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
