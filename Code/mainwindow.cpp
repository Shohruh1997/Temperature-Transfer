#include "mainwindow.h"
#include "ui_mainwindow.h"
bool cels=false;
bool kelv=false;
bool faren=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TempLineEdit->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CelsiyRadioButton_clicked()
{
    ui->CelLineEdit->setText("0");
    ui->KelLineEdit->setText("273.15");
    ui->FarLineEdit->setText("32");
    cels=true;
}


void MainWindow::on_FarenRadioButton_clicked()
{
    ui->CelLineEdit->setText("-17.78");
    ui->KelLineEdit->setText("255.372");
    ui->FarLineEdit->setText("0");
    faren=true;
}


void MainWindow::on_KelvinRadioButton_clicked()
{
    ui->CelLineEdit->setText("-273.1");
    ui->KelLineEdit->setText("0");
    ui->FarLineEdit->setText("-459.7");
    kelv=true;
}


void MainWindow::on_pushButton_clicked()
{
    QString val=ui->TempLineEdit->text();
    double dblval=val.toDouble();
    if(cels)
    {
        double CelDblVal= dblval;
        ui->CelLineEdit->setText(QString::number(CelDblVal));
        double KelDblVal=dblval+ 273.15;
        ui->KelLineEdit->setText(QString::number(KelDblVal));
        double FarDblVal=dblval* 1.8 + 32;
        ui->FarLineEdit->setText(QString::number(FarDblVal));

    }else if(kelv)
    {
        double KelDblVal= dblval;
        ui->KelLineEdit->setText(QString::number(KelDblVal));
        double CelDblVal=dblval- 273.15;
        ui->CelLineEdit->setText(QString::number(CelDblVal));
        double FarDblVal= CelDblVal* 9/5 + 32;
        ui->FarLineEdit->setText(QString::number(FarDblVal));

    }else if(faren)
    {
        double FarDblVal= dblval;
        ui->FarLineEdit->setText(QString::number(FarDblVal));
        double CelDblVal=(dblval- 32) * 5/9 ;
        ui->CelLineEdit->setText(QString::number(CelDblVal));
        double KelDblVal=CelDblVal+ 273.15;
        ui->KelLineEdit->setText(QString::number(KelDblVal));

    }
    cels=ui->CelsiyRadioButton->isChecked();
    faren=ui->FarenRadioButton->isChecked();
    kelv=ui->KelvinRadioButton->isChecked();
}


void MainWindow::on_ClearPushButton_clicked()
{
     ui->TempLineEdit->setText("0");
}

