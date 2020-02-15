#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QMap<QString, QString> rSet, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString save_add = QFileDialog::getSaveFileName(this, "新建报告文件", "./untitled.rpt", "报告文件(*.rpt)");
    /*save_file = new QFile(save_add);
    save_file->open(QIODevice::WriteOnly);*/

    ui->sname->setText(rSet["sName"]);
    ui->sid->setText(rSet["sID"]);
    ui->cname->setText(rSet["cName"]);
    ui->etchr->setText(rSet["eTchr"]);
    ui->ctchr->setText(rSet["cTchr"]);
    ui->eaddr->setText(rSet["eAddr"]);
    ui->edate->setDate(QDate::fromString(rSet["eDate"]));
    ui->eroom->setText(rSet["eRoom"]);
    ui->ename->setText(rSet["eName"]);
    ui->ehour->setText(rSet["eHour"]);
}

MainWindow::~MainWindow()
{
    delete ui;
}

