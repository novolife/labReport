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
    rSet.insert("sname", ui->sname->text());
    rSet.insert("sid", ui->sid->text());
    rSet.insert("cname", ui->cname->text());
    rSet.insert("ctchr", ui->ctchr->text());
    rSet.insert("etchr", ui->etchr->text());
    rSet.insert("eaddr", ui->eaddr->text());
    rSet.insert("edate", ui->edate->text());
    rSet.insert("eroom", ui->eroom->text());
    rSet.insert("ename", ui->ename->text());
    rSet.insert("ehour", ui->ehour->text());
    emit send_setting_map(rSet);
}
