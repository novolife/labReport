#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "about.h"
#include "unsaved.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QMap<QString, QString>, QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

    enum status
    {
        SAVED = 0,
        UNSAVED = 1,
        NOSAVE = 2
    };
    Q_ENUM(status)

    status get_status() { return report_s; }
    void set_status(status new_s) { report_s = new_s; }

private slots:
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();
    void on_actionSave_triggered();

    void save_unsaved();
    void nosave_unsaved();

    void on_etool_textChanged();
    void on_eprin_textChanged();
    void on_epurp_textChanged();
    void on_econt_textChanged();
    void on_estep_textChanged();
    void on_erslt_textChanged();
    void on_ecncl_textChanged();
    void on_efeel_textChanged();
    void on_eadvs_textChanged();

    void on_sname_textChanged(const QString &arg1);
    void on_sid_textChanged(const QString &arg1);
    void on_cname_textChanged(const QString &arg1);
    void on_ctchr_textChanged(const QString &arg1);
    void on_etchr_textChanged(const QString &arg1);
    void on_eaddr_textChanged(const QString &arg1);
    void on_edate_dateChanged(const QDate &date);
    void on_eroom_textChanged(const QString &arg1);
    void on_ename_textChanged(const QString &arg1);
    void on_ehour_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QMap<QString, QString> report_set;

    QFile *save_file = nullptr;
    QFileInfo *file_info = nullptr;
    QSettings *setting_file = nullptr;

    QString save_add = "";
    QString file_name = "";

    status report_s = UNSAVED;

    void saving_file();
    void unsaved_title();

};
#endif // MAINWINDOW_H
