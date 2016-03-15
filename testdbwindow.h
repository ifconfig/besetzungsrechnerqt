#ifndef TESTDBWINDOW_H
#define TESTDBWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "qualificationsliderwidget.h"
#include "vehiclespinboxwidget.h"
#include "qualificationlist.h"
#include "vehiclelist.h"


namespace Ui {
  class TestDbWindow;
}

class TestDbWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit TestDbWindow(QWidget *parent = 0);
  ~TestDbWindow();

private slots:
  void on_pushButton_clicked();

private:
  Ui::TestDbWindow *ui;
  QJsonObject loadConfObject();
  void createQualificationSliders(QJsonObject configurationObject);
  void createVehicleSpinBoxes(QJsonObject configurationObject);
};

#endif // TESTDBWINDOW_H
