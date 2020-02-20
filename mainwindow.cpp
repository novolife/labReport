#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QMap<QString, QString> rSet, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sid->setValidator(new QRegularExpressionValidator(QRegularExpression("\\d{13}")));
    report_set = rSet;

    while(1)
    {
        save_add = QFileDialog::getSaveFileName(this, "Select Saving Position", "./untitled.rpt", "Report File (*.rpt)");
        file_info = new QFileInfo(save_add);

        if (save_add == "")
        {
            QMessageBox::critical(this, "Please Select Saving Position!", "Report Saving Position Could NOT Be Empty.");
        }
        else if (file_info->suffix() != ".rpt")
        {
            QMessageBox::critical(this, "Please Use Correct Suffix!", "Report File Suffix MUST BE \".rpt\"");
        }
        else
        {
            break;
        }
    }

    file_info = new QFileInfo(save_add);
    file_name = file_info->fileName();
    setWindowTitle(file_name + "* - labReport");

    save_file = new QFile(save_add);
    save_file->open(QIODevice::WriteOnly);
    save_file->close();

    setting_file = new QSettings(save_add, QSettings::IniFormat);

    ui->sname->setText(rSet["sName"]);
    ui->sid->setText(rSet["sID"]);
    ui->cname->setText(rSet["cName"]);
    ui->etchr->setText(rSet["eTchr"]);
    ui->ctchr->setText(rSet["cTchr"]);
    ui->eaddr->setText(rSet["eAddr"]);
    ui->edate->setDate(QDate::fromString(rSet["eDate"]));
    ui->eroom->setText(rSet["eRoom"]);
    ui->ename->setText(rSet["eName"]);
    ui->ehour->setText(rSet["eHour"]);
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
    if(get_status() == SAVED)
    {
        saving_file();
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
    else if (get_status() == NOSAVE)
    {
        event->accept();
    }

}

/**
 * @brief save the content in textedits
 */
void MainWindow::saving_file()
{
    setting_file->setValue("profile/sname", report_set["sName"]);
    setting_file->setValue("profile/sid", report_set["sID"]);
    setting_file->setValue("profile/cname", report_set["cName"]);
    setting_file->setValue("profile/etchr", report_set["eTchr"]);
    setting_file->setValue("profile/ctchr", report_set["cTchr"]);
    setting_file->setValue("profile/eaddr", report_set["eAddr"]);
    setting_file->setValue("profile/edate", report_set["eDate"]);
    setting_file->setValue("profile/eroom", report_set["eRoom"]);
    setting_file->setValue("profile/ename", report_set["eName"]);
    setting_file->setValue("profile/ehour", report_set["eHour"]);

    setting_file->setValue("text/eprin", ui->eprin->toPlainText());
    setting_file->setValue("text/epurp", ui->epurp->toPlainText());
    setting_file->setValue("text/econt", ui->econt->toPlainText());
    setting_file->setValue("text/etool", ui->etool->toPlainText());
    setting_file->setValue("text/estep", ui->estep->toPlainText());
    setting_file->setValue("text/erslt", ui->erslt->toPlainText());
    setting_file->setValue("text/ecncl", ui->ecncl->toPlainText());
    setting_file->setValue("text/efeel", ui->efeel->toPlainText());
    setting_file->setValue("text/eadvs", ui->eadvs->toPlainText());

    setWindowTitle(save_add + " - labReport");
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

void MainWindow::unsaved_title()
{
    setWindowTitle(save_add + "* - labReport");
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
