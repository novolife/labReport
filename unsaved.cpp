#include "unsaved.h"
#include "ui_unsaved.h"

unsaved::unsaved(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unsaved)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_ShowModal, true);
}

unsaved::~unsaved()
{
    delete ui;
}

void unsaved::on_buttonBox_accepted()
{
    emit send_unsaved();
    this->close();
}

void unsaved::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button == ui->buttonBox->button(QDialogButtonBox::Cancel))
    {
        this->close();
    }
    else if (button == ui->buttonBox->button(QDialogButtonBox::No))
    {
        emit no_unsaved();
        this->close();
    }
}
