#ifndef START_H
#define START_H

#include <QMainWindow>
#include <QTime>
#include <QMap>

#include "mainwindow.h"
#include "reportsetting.h"
#include "about.h"

namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

private slots:
    void get_setting_map(QMap<QString, QString>);

    void on_new_2_clicked();
    void on_open_clicked();
    void on_exit_clicked();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionNew_triggered();

private:
    Ui::Start *ui;
    void new_report();
    void open_report();
};

#endif // START_H
