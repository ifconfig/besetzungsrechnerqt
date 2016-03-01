#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "general.h"

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
