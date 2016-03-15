#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "general.h"
#include "dbmanager.h"
#include "testdbwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_ber_triggered();

    void on_actionDatenbank_ffnen_triggered();

    void on_actionTestdatenbank_erzeugen_triggered();

private:
    Ui::MainWindow *ui;
    DBManager *m_dbMan;
};

#endif // MAINWINDOW_H
