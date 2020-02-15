#include "reportsetting.h"
#include "ui_reportsetting.h"

ReportSetting::ReportSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportSetting)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_ShowModal, true);
    ui->sid->setValidator(new QRegularExpressionValidator(QRegularExpression("\\d{13}")));
}

ReportSetting::~ReportSetting()
{
    delete ui;
}

void ReportSetting::on_buttonBox_accepted()
{
    QMap<QString, QString> rSet;
    rSet.insert("sName", ui->sname->text());
    rSet.insert("sID", ui->sid->text());
    rSet.insert("cName", ui->cname->text());
    rSet.insert("cTchr", ui->ctchr->text());
    rSet.insert("eTchr", ui->etchr->text());
    rSet.insert("eAddr", ui->eaddr->text());
    rSet.insert("eDate", ui->edate->text());
    rSet.insert("eRoom", ui->eroom->text());
    rSet.insert("eName", ui->ename->text());
    rSet.insert("eHour", ui->ehour->text());
    emit send_setting_map(rSet);
    this->accept();
}
