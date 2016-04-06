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

    m_qualiList = QSharedPointer<QualificationList>(new QualificationList(qualificationsArray));

    // show sliders

    foreach (QSharedPointer<Qualification> quali, m_qualiList->getHashList())
      {
        auto sliderWidget = new QualificationSliderWidget(quali, sliderArea);
        m_sliderHashList.insert(quali->qualiShortName(), sliderWidget);
        sliderArea->layout()->addWidget(sliderWidget);
      }


}

void TestDbWindow::createVehicleSpinBoxes(QJsonObject configurationObject)
{
    QWidget* spinBoxArea = new QWidget(ui->groupBox_vehicles);
    spinBoxArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    spinBoxArea->setLayout(new QVBoxLayout(spinBoxArea));
    ui->scrollArea_vehicles->setWidget(spinBoxArea);

    QJsonArray vehiclesArray = configurationObject["vehicles"].toArray();
    m_vehicleList = QSharedPointer<VehicleList>(new VehicleList(vehiclesArray));

    foreach (QSharedPointer<Vehicle> vehicle, m_vehicleList->vehicles())
      {
        VehicleSpinBoxWidget* vehicleSpinBoxWidget = new VehicleSpinBoxWidget(vehicle, spinBoxArea);
        spinBoxArea->layout()->addWidget(vehicleSpinBoxWidget);
        m_vehicleSpinBoxList.insert(vehicle->name(), vehicleSpinBoxWidget);
      }
}

QList<Comrad> TestDbWindow::generateComradList(int numberComrads, QSharedPointer<QualificationList> qualiList)
{

}

// generieren Button pressed
void TestDbWindow::on_pushButton_2_clicked()
{

  // gather Qualification percentages
  foreach (auto qualificationSliderWidget, m_sliderHashList)
    {
      m_qualiList->qualificationPercentages()->insert(
            qualificationSliderWidget->qualification()->qualiShortName(),
            qualificationSliderWidget->qualificationSlider()->value());
    }

  // gather Vehicle number
  foreach (auto vehicleSpinBox, m_vehicleSpinBoxList)
    {
      m_vehicleList->vehicleNumber()->insert(
            vehicleSpinBox->vehicle()->name(),
            vehicleSpinBox->vehicleSpinBox()->value());
    }

  QList<Comrad> comradList = generateComradList(ui->numberComradsSpinBox->value(), m_qualiList);

}
