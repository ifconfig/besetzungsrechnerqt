#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_ber_triggered()
{
   QString text = "<b>Version:</b> ";
   text += APP_VERSION;
   QMessageBox::about(this, tr("Über"), text);
}

void MainWindow::on_actionDatenbank_ffnen_triggered()
{
    QString dbFile = QFileDialog::getOpenFileName(this,tr("Datenbank öffnen"), "", tr(""));
    m_dbMan = new DBManager(dbFile);
    ui->comradsTable->setModel(m_dbMan->getComradTableModel());
    ui->vehicleTable->setModel(m_dbMan->getVehicleTableModel());
}

void MainWindow::on_actionTestdatenbank_erzeugen_triggered()
{
   TestDbWindow *tW = new TestDbWindow;
   tW->show();
}
