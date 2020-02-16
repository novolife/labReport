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

void unsaved::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button == ui->buttonBox->button(QDialogButtonBox::Yes))
    {
        emit no_unsaved();
    }
    else if (button == ui->buttonBox->button(QDialogButtonBox::Save))
    {
        emit send_unsaved();
    }

    close();
}
