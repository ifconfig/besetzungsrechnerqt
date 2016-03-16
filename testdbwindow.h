#ifndef TESTDBWINDOW_H
#define TESTDBWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>

#include <QFile>
#include <QHash>
#include <QList>
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
#include "comrad.h"


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

  void on_pushButton_2_clicked();

private:
  Ui::TestDbWindow *ui;
  QJsonObject loadConfObject();
  QSharedPointer<QualificationList> m_qualiList;
  QHash<QString, QualificationSliderWidget *> m_sliderHashList;

  QSharedPointer<VehicleList> m_vehicleList;
  QHash<QString, VehicleSpinBoxWidget*> m_vehicleSpinBoxList;
  void createQualificationSliders(QJsonObject configurationObject);
  void createVehicleSpinBoxes(QJsonObject configurationObject);
  QList<Comrad> generateComradList(int numberComrads, QSharedPointer<QualificationList> qualiList);
};

#endif // TESTDBWINDOW_H
