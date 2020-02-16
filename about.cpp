#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_ShowModal, true);
}

about::~about()
{
    delete ui;
}
