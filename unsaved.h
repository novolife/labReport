#ifndef UNSAVED_H
#define UNSAVED_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class unsaved;
}

class unsaved : public QDialog
{
    Q_OBJECT

public:
    explicit unsaved(QWidget *parent = nullptr);
    ~unsaved();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::unsaved *ui;

signals:
    void send_unsaved();
    void no_unsaved();
};

#endif // UNSAVED_H
