#ifndef REPORTSETTING_H
#define REPORTSETTING_H

#include <QDialog>
#include <QMap>

namespace Ui {
class ReportSetting;
}

class ReportSetting : public QDialog
{
    Q_OBJECT

public:
    explicit ReportSetting(QWidget *parent = nullptr);
    ~ReportSetting();

private slots:
    void on_buttonBox_accepted();

signals:
    void send_setting_map(QMap<QString, QString>);

private:
    Ui::ReportSetting *ui;
};

#endif // REPORTSETTING_H
