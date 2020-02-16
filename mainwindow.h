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

    void save_unsaved();
    void nosave_unsaved();

private:
    Ui::MainWindow *ui;
    QFile *save_file = nullptr;
    QString save_add = "";
    status report_s = UNSAVED;

};
#endif // MAINWINDOW_H
