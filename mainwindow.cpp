#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QMap<QString, QString> rSet, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sid->setValidator(new QRegularExpressionValidator(QRegularExpression("\\d{13}")));
/*
    do
    {
        save_add = QFileDialog::getSaveFileName(this, "新建报告文件", "./untitled.rpt", "报告文件(*.rpt)");
    }
    while (save_add == "" && (QMessageBox::critical(this, "文件名不能为空！", "请设置报告文件位置！")));
    save_file = new QFile(save_add);
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

void MainWindow::on_actionUndo_triggered()
{
    switch(ui->tabWidget->currentIndex())
    {
    case 0: ui->eprin->undo();
            break;
    case 1: ui->epurp->undo();
            break;
    case 2: ui->econt->undo();
            break;
    case 3: ui->etool->undo();
            break;
    case 4: ui->estep->undo();
            break;
    case 5: ui->erslt->undo();
            break;
    case 6: ui->ecncl->undo();
            break;
    case 7: ui->efeel->undo();
            break;
    case 8: ui->eadvs->undo();
            break;
    }
}

void MainWindow::on_actionRedo_triggered()
{
    switch(ui->tabWidget->currentIndex())
    {
    case 0: ui->eprin->redo();
            break;
    case 1: ui->epurp->redo();
            break;
    case 2: ui->econt->redo();
            break;
    case 3: ui->etool->redo();
            break;
    case 4: ui->estep->redo();
            break;
    case 5: ui->erslt->redo();
            break;
    case 6: ui->ecncl->redo();
            break;
    case 7: ui->efeel->redo();
            break;
    case 8: ui->eadvs->redo();
            break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(get_status() == SAVED)
        event->accept();
    else if (get_status() == UNSAVED)
    {
        if (QMessageBox::information(this, "报告未保存", "是否仍要退出程序？", QMessageBox::Ok, QMessageBox::No) == QMessageBox::Ok)
            event->accept();
        else
            event->ignore();
    }

}

void MainWindow::on_actionAbout_triggered()
{
    about *about_dialog = new about();
    about_dialog->show();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
