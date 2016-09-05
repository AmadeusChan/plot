#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connected_flag=false;
    network=new myNetwork(this);
    connect(network,&myNetwork::serverSetUp,[=](QHostAddress address_,int port_){
        QString string_;
        string_.setNum(port_);
        qDebug()<<address_;
        qDebug()<<string_;
        string_="Address:"+address_.toString()+"  Port:"+string_;
        qDebug()<<string_;
        ui->label->setText(string_);
    });
    connect(network,&myNetwork::connected,[=](){
        ui->label->setText("connected!");
        connected_flag=true;
        connect(ui->pushButton,&QPushButton::clicked,[=](){
            network->writeData("C-"+ui->lineEdit->text()+"-"+ui->lineEdit_2->text()+"-"+ui->lineEdit_3->text()+"-");
        });
        connect(ui->pushButton_2,&QPushButton::clicked,[=](){
            QString string_="R-";
            string_+=ui->lineEdit_4->text()+"-";
            string_+=ui->lineEdit_5->text()+"-";
            string_+=ui->lineEdit_6->text()+"-";
            string_+=ui->lineEdit_7->text()+"-";
            network->writeData(string_);
        });
        connect(ui->pushButton_3,&QPushButton::clicked,[=](){
            QString string_="T-";
            string_+=ui->lineEdit_8->text()+"-";
            string_+=ui->lineEdit_9->text()+"-";
            string_+=ui->lineEdit_10->text()+"-";
            string_+=ui->lineEdit_11->text()+"-";
            string_+=ui->lineEdit_12->text()+"-";
            string_+=ui->lineEdit_13->text()+"-";
            network->writeData(string_);
        });
    });
    network->setUpServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}
