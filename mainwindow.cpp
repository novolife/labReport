#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QMap<QString, QString> proSet, QMap<QString, QString> txtSet, QString rAdd, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sid->setValidator(new QRegularExpressionValidator(QRegularExpression("\\d{13}")));

    report_set = proSet;
    save_add = rAdd;

    // Get File Name & Set As Title
    file_info = new QFileInfo(save_add);
    file_name = file_info->fileName();
    setWindowTitle(file_name + "* - labReport");

    // Create Report File
    save_file = new QFile(save_add);
    save_file->open(QIODevice::WriteOnly);
    save_file->close();

    // Open Report As Setting File
    setting_file = new QSettings(save_add, QSettings::IniFormat);

    // Put The Settings On UI
    ui->sname->setText(proSet["sname"]);
    ui->sid->setText(proSet["sid"]);
    ui->cname->setText(proSet["cname"]);
    ui->etchr->setText(proSet["etchr"]);
    ui->ctchr->setText(proSet["ctchr"]);
    ui->eaddr->setText(proSet["eaddr"]);
    ui->edate->setDate(QDate::fromString(proSet["edate"]));
    ui->eroom->setText(proSet["eroom"]);
    ui->ename->setText(proSet["ename"]);
    ui->ehour->setText(proSet["ehour"]);

    ui->eprin->setText(txtSet["eprin"]);
    ui->epurp->setText(txtSet["epurp"]);
    ui->econt->setText(txtSet["econt"]);
    ui->etool->setText(txtSet["etool"]);
    ui->estep->setText(txtSet["estep"]);
    ui->erslt->setText(txtSet["erslt"]);
    ui->ecncl->setText(txtSet["ecncl"]);
    ui->efeel->setText(txtSet["efeel"]);
    ui->eadvs->setText(txtSet["eadvs"]);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionUndo_triggered()
{
    switch(ui->tabWidget->currentIndex())
    {
    case 0: ui->eprin->undo();
            break;
    case 1: ui->epurp->undo();
            break;
    case 2: ui->econt->undo();
            break;
    case 3: ui->etool->undo();
            break;
    case 4: ui->estep->undo();
            break;
    case 5: ui->erslt->undo();
            break;
    case 6: ui->ecncl->undo();
            break;
    case 7: ui->efeel->undo();
            break;
    case 8: ui->eadvs->undo();
            break;
    }
}

void MainWindow::on_actionRedo_triggered()
{
    switch(ui->tabWidget->currentIndex())
    {
    case 0: ui->eprin->redo();
            break;
    case 1: ui->epurp->redo();
            break;
    case 2: ui->econt->redo();
            break;
    case 3: ui->etool->redo();
            break;
    case 4: ui->estep->redo();
            break;
    case 5: ui->erslt->redo();
            break;
    case 6: ui->ecncl->redo();
            break;
    case 7: ui->efeel->redo();
            break;
    case 8: ui->eadvs->redo();
            break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(get_status() == SAVED || get_status() == NOSAVE)
    {
        event->accept();
    }
    else if (get_status() == UNSAVED)
    {
        unsaved *dialog = new unsaved(this);
        connect(dialog, &unsaved::send_unsaved, this, &MainWindow::save_unsaved);
        connect(dialog, &unsaved::no_unsaved, this, &MainWindow::nosave_unsaved);
        dialog->show();
        event->ignore();
    }
}

/**
 * @brief save the content in textedits
 */
void MainWindow::saving_file()
{
    setting_file->setValue("profile/sname", ui->sname->text());
    setting_file->setValue("profile/sid", ui->sid->text());
    setting_file->setValue("profile/cname", ui->cname->text());
    setting_file->setValue("profile/etchr", ui->etchr->text());
    setting_file->setValue("profile/ctchr", ui->ctchr->text());
    setting_file->setValue("profile/eaddr", ui->eaddr->text());
    setting_file->setValue("profile/edate", ui->edate->text());
    setting_file->setValue("profile/eroom", ui->eroom->text());
    setting_file->setValue("profile/ename", ui->ename->text());
    setting_file->setValue("profile/ehour", ui->ehour->text());

    setting_file->setValue("text/eprin", ui->eprin->toPlainText());
    setting_file->setValue("text/epurp", ui->epurp->toPlainText());
    setting_file->setValue("text/econt", ui->econt->toPlainText());
    setting_file->setValue("text/etool", ui->etool->toPlainText());
    setting_file->setValue("text/estep", ui->estep->toPlainText());
    setting_file->setValue("text/erslt", ui->erslt->toPlainText());
    setting_file->setValue("text/ecncl", ui->ecncl->toPlainText());
    setting_file->setValue("text/efeel", ui->efeel->toPlainText());
    setting_file->setValue("text/eadvs", ui->eadvs->toPlainText());

    setWindowTitle(file_name + " - labReport");
    set_status(SAVED);
}

/**
 * @brief slot func for about act.
 */
void MainWindow::on_actionAbout_triggered()
{
    about *about_dialog = new about();
    about_dialog->show();
}

/**
 * @brief slot func for exit act.
 */
void MainWindow::on_actionExit_triggered()
{
    close();
}

/**
 * @brief slot func for unsaved window -> Save
 */
void MainWindow::save_unsaved()
{
    saving_file();
    close();
}

/**
 * @brief slot func for unsaved window -> Yes
 */
void MainWindow::nosave_unsaved()
{
    set_status(NOSAVE);
    close();
}

/**
 * @brief slot func for save act.
 */
void MainWindow::on_actionSave_triggered()
{
    saving_file();
}

/**
 * @brief MainWindow::unsaved_title
 */
void MainWindow::unsaved_title()
{
    set_status(UNSAVED);
    setWindowTitle(file_name + "* - labReport");
}

void MainWindow::on_etool_textChanged()
{
    unsaved_title();
}

void MainWindow::on_eprin_textChanged()
{
    unsaved_title();
}

void MainWindow::on_epurp_textChanged()
{
    unsaved_title();
}

void MainWindow::on_econt_textChanged()
{
    unsaved_title();
}

void MainWindow::on_estep_textChanged()
{
    unsaved_title();
}

void MainWindow::on_erslt_textChanged()
{
    unsaved_title();
}

void MainWindow::on_ecncl_textChanged()
{
    unsaved_title();
}

void MainWindow::on_efeel_textChanged()
{
    unsaved_title();
}

void MainWindow::on_eadvs_textChanged()
{
    unsaved_title();
}

void MainWindow::on_sname_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    unsaved_title();
}

void MainWindow::on_sid_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    unsaved_title();
}

void MainWindow::on_cname_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    unsaved_title();
}

void MainWindow::on_ctchr_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    unsaved_title();
}

void MainWindow::on_etchr_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    unsaved_title();
}

void MainWindow::on_eaddr_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    unsaved_title();
}

void MainWindow::on_edate_dateChanged(const QDate &date)
{
    Q_UNUSED(date)
    unsaved_title();
}

void MainWindow::on_eroom_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    unsaved_title();
}

void MainWindow::on_ename_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    unsaved_title();
}

void MainWindow::on_ehour_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    unsaved_title();
}
