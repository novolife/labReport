#include "start.h"
#include "ui_start.h"
#include <QDebug>

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);

    // Random Pics For Start Menu Banner
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
    int banner_num = qrand() % 7;
    QString banner_style = "background-image: url(:/resource/banner-image/" + QString::number(banner_num) + ".jpg);";
    ui->banner->setStyleSheet(banner_style);
}

Start::~Start()
{
    delete ui;
}

void Start::get_setting_map(QMap<QString, QString> proSet)
{
    QString save_add;

    if ((save_add = get_save_add()) == "") // If Cancel, Return to Start Menu
    {
        return;
    }

    QMap<QString, QString> txtSet;
    txtSet.insert("eprin", "");
    txtSet.insert("epurp", "");
    txtSet.insert("econt", "");
    txtSet.insert("etool", "");
    txtSet.insert("estep", "");
    txtSet.insert("erslt", "");
    txtSet.insert("ecncl", "");
    txtSet.insert("efeel", "");
    txtSet.insert("eadvs", "");

    MainWindow *w = new MainWindow(proSet, txtSet, save_add);
    w->show();
    close();
}

QString Start::get_save_add()
{
    QString save_add = "";

    while(1)
    {
        save_add = QFileDialog::getOpenFileName(this, "Select Saving Position", "./untitled.rpt", "Report File (*.rpt)");

        if (save_add != "")
        {
            QFileInfo *file_info = new QFileInfo(save_add);
            if (file_info->suffix() != "rpt") // Illegal Suffix
            {
                QMessageBox::critical(this, "Please Use Correct Suffix!", "Report File Suffix MUST BE \".rpt\"");
            }
            else // Legal Suffix
            {
                break;
            }
        }
        else // If Cancel
        {
            break;
        }
    }

    return save_add;
}

void Start::new_report()
{
    ReportSetting *r = new ReportSetting(this);
    connect(r, &ReportSetting::send_setting_map, this, &Start::get_setting_map);
    r->show();
}

void Start::open_report()
{
    QString file_add = "";

    if ((file_add = get_save_add()) == "") // If Cancel, Return to Start Menu
    {
        return;
    }

    // Restore Report Settings
    QSettings *report_setting = new QSettings(file_add, QSettings::IniFormat);

    QMap<QString, QString> proSet;
    proSet.insert("sname", report_setting->value("profile/sname").toString());
    proSet.insert("sid", report_setting->value("profile/sid").toString());
    proSet.insert("cname", report_setting->value("profile/cname").toString());
    proSet.insert("ctchr", report_setting->value("profile/ctchr").toString());
    proSet.insert("etchr", report_setting->value("profile/etchr").toString());
    proSet.insert("eaddr", report_setting->value("profile/eaddr").toString());
    proSet.insert("edate", report_setting->value("profile/edate").toString());
    proSet.insert("ehoom", report_setting->value("profile/eroom").toString());
    proSet.insert("ename", report_setting->value("profile/ename").toString());
    proSet.insert("ehour", report_setting->value("profile/ehour").toString());

    QMap<QString, QString> txtSet;
    txtSet.insert("eprin", report_setting->value("text/eprin").toString());
    txtSet.insert("epurp", report_setting->value("text/epurp").toString());
    txtSet.insert("econt", report_setting->value("text/econt").toString());
    txtSet.insert("etool", report_setting->value("text/etool").toString());
    txtSet.insert("estep", report_setting->value("text/estep").toString());
    txtSet.insert("erslt", report_setting->value("text/erslt").toString());
    txtSet.insert("ecncl", report_setting->value("text/ecncl").toString());
    txtSet.insert("efeel", report_setting->value("text/efeel").toString());
    txtSet.insert("eadvs", report_setting->value("text/eadvs").toString());

    MainWindow *w = new MainWindow(proSet, txtSet, file_add);
    w->show();
    close();
}

void Start::on_new_2_clicked()
{
    new_report();
}

void Start::on_open_clicked()
{
    open_report();
}

void Start::on_exit_clicked()
{
    close();
}

void Start::on_actionOpen_triggered()
{
    open_report();
}

void Start::on_actionExit_triggered()
{
    close();
}

void Start::on_actionAbout_triggered()
{
    about *about_dialog = new about();
    about_dialog->show();
}

void Start::on_actionNew_triggered()
{
    new_report();
}
