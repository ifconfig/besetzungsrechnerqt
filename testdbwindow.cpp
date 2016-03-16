#include "testdbwindow.h"
#include "ui_testdbwindow.h"

TestDbWindow::TestDbWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::TestDbWindow)
{
  ui->setupUi(this);
}

TestDbWindow::~TestDbWindow()
{
  delete ui;
}

void TestDbWindow::on_pushButton_clicked()
{
    QJsonObject configurationObject = loadConfObject();
    createQualificationSliders(configurationObject);
    createVehicleSpinBoxes(configurationObject);
}

QJsonObject TestDbWindow::loadConfObject()
{
    QString val;
    QFile file;
    //file.setFileName("/Users/heyne/workspaces/workspace_qt/names.json");
    file.setFileName("names.json");
    bool ok = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!ok){
        QString filename = QFileDialog::getOpenFileName(this, "JSON öffnen", "./","JSON Files (*.json)");
        file.setFileName(filename);
        ok = file.open(QIODevice::ReadOnly | QIODevice::Text);
        if(!ok){
            return QJsonObject();
        }
    }
    val = file.readAll();
    file.close();
    QJsonDocument confFile = QJsonDocument::fromJson(val.toUtf8());
    return confFile.object();
}

void TestDbWindow::createQualificationSliders(QJsonObject configurationObject)
{
    QWidget* sliderArea = new QWidget(ui->groupBox_qualifications);
    sliderArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sliderArea->setLayout(new QVBoxLayout(sliderArea));
    ui->scrollArea_qualifications->setWidget(sliderArea);


    QJsonArray qualificationsArray =  configurationObject["qualifications"].toArray();

    QualificationList* qualiList = new QualificationList(qualificationsArray);

    QHash <QString, QualificationSliderWidget*> sliderHashList;

    // show sliders
    foreach (QSharedPointer<Qualification> quali, qualiList->getHashList())
      {
        auto sliderWidget = new QualificationSliderWidget(quali, sliderArea);
        sliderHashList.insert(quali->qualiShortName(), sliderWidget);
        sliderArea->layout()->addWidget(sliderWidget);
      }

    foreach(auto qualiSliderWidget, sliderHashList)
      {
        foreach(auto dependency, qualiSliderWidget->dependencies())
          {
            qualiSliderWidget->setDependency(sliderHashList[dependency->qualiShortName()]);
          }
      }
}

void TestDbWindow::createVehicleSpinBoxes(QJsonObject configurationObject)
{
    QWidget* spinBoxArea = new QWidget(ui->groupBox_vehicles);
    spinBoxArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    spinBoxArea->setLayout(new QVBoxLayout(spinBoxArea));
    ui->scrollArea_vehicles->setWidget(spinBoxArea);

    QJsonArray vehiclesArray = configurationObject["vehicles"].toArray();
    VehicleList* vehicleList = new VehicleList(vehiclesArray);

    foreach (QSharedPointer<Vehicle> vehicle, vehicleList->vehicles()) {
        spinBoxArea->layout()->addWidget(new VehicleSpinBoxWidget(vehicle, spinBoxArea));

    }
}
