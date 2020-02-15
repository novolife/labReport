#include "start.h"
#include "ui_start.h"
#include <QDebug>

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int banner_num = qrand() % 7;
    QString banner_style = \
            "background-image: url(:/resource/banner-image/" + QString::number(banner_num) + ".jpg);";
    ui->banner->setStyleSheet(banner_style);
}

Start::~Start()
{
    delete ui;
}

void Start::get_setting_map(QMap<QString, QString> rSet)
{
    //qDebug() << rSet;
}

void Start::new_report()
{
    ReportSetting *r = new ReportSetting(this);
    connect(r, &ReportSetting::send_setting_map, this, &Start::get_setting_map);
    r->show();
}

void Start::on_new_2_clicked()
{
    new_report();
}

void Start::on_open_clicked()
{
    //open_report();
}

void Start::on_exit_clicked()
{
    this->close();
}
