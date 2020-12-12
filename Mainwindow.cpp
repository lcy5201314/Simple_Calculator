#include "Mainwindow.h"
#include "ui_Mainwindow.h"

#include <QString>
#include <QDebug>
#include <string>
#include "QDebug"
#include <stack>
#include <bits/stdc++.h>
#include<vector>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //清空a，b
    a.clear();
    b.clear();

    //绑定按键0与处理函数
    connect(ui->pushButton_0,&QPushButton::clicked,[=](){btn_logic(0);});
    //绑定按键1与处理函数
    connect(ui->pushButton_1,&QPushButton::clicked,[=](){btn_logic(1);});
    //绑定按键2与处理函数
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){btn_logic(2);});
    //绑定按键3与处理函数
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){btn_logic(3);});
    //绑定按键4与处理函数
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){btn_logic(4);});
    //绑定按键5与处理函数
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){btn_logic(5);});
    //绑定按键6与处理函数
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){btn_logic(6);});
    //绑定按键7与处理函数
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){btn_logic(7);});
    //绑定按键8与处理函数
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){btn_logic(8);});
    //绑定按键9与处理函数
    connect(ui->pushButton_9,&QPushButton::clicked,[=](){btn_logic(9);});

    //绑定按键+与处理函数
    connect(ui->pushButton_addition,&QPushButton::clicked,[=](){btn_logic(0,"+");});
    //绑定按键-与处理函数
    connect(ui->pushButton_subtraction,&QPushButton::clicked,[=](){btn_logic(0,"-");});
    //绑定按键*与处理函数
    connect(ui->pushButton_multiplication,&QPushButton::clicked,[=](){btn_logic(0,"*");});
    //绑定按键/与处理函数
    connect(ui->pushButton_division,&QPushButton::clicked,[=](){btn_logic(0,"/");});
    //绑定按键=与处理函数
    connect(ui->pushButton_equal,&QPushButton::clicked,[=](){btn_logic(0,"=");});

    //绑定按键AC与处理函数
    connect(ui->pushButton_clear,&QPushButton::clicked,[=](){
        a.clear();
        b.clear();
        ui->lineEdit->setText(a);
    });

    //绑定按键退格->与处理函数
    connect(ui->pushButton_backspace,&QPushButton::clicked,[=](){
        //删除a.pop
        a.chop(1);
        ui->lineEdit->setText(a);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::btn_logic(int x , QString i)
{
    if(i == " ")
    {
        a += QString::number(x);
    }
    //如果运算符被按下，将lineEdit的内容存储到b[0]中
    else if(x == 0)
    {
//        b.insert(0,a);
//        qDebug() << "b0" << b.at(0);
        if(i != "=")
        {
            b.insert(0,a);
            a.clear();
            b.insert(1,i);
        }
        else
        {
            b.insert(2,a);
            qDebug() << "b0" << b.at(0);
            qDebug() << "b1" << b.at(1);
            qDebug() << "b2" << b.at(2);
            den_logic();
         }
      }
      ui->lineEdit->setText(a);
}


void MainWindow::den_logic()
{
    a.clear();
    if(b.at(1) == "+")
    {
        a += QString::number( QString(b.at(0)).toDouble()  + QString(b.at(2)).toDouble() );
    }
    else if (b.at(1) == "-")
    {
        a += QString::number( QString(b.at(0)).toDouble()  - QString(b.at(2)).toDouble() );
    }
    else if (b.at(1) == "*")
    {
        a += QString::number( QString(b.at(0)).toDouble()  * QString(b.at(2)).toDouble() );
    }
    else if (b.at(1) == "/")
    {
        a += QString::number( QString(b.at(0)).toDouble()  / QString(b.at(2)).toDouble() );
    }
    ui->lineEdit->setText(a);
}

