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

    QList <QualificationSliderWidget*> sliderList;
    // show sliders
    foreach (QSharedPointer<Qualification> quali, qualiList->getList())
      {
        auto sliderWidget = new QualificationSliderWidget(quali, sliderArea);
        sliderList.append(sliderWidget);
        sliderArea->layout()->addWidget(sliderWidget);
      }

    // populate dependencies
    for(int depIndex=0; depIndex<sliderList.size(); ++depIndex)
      {
        for(int masterIndex=0; masterIndex<sliderList.size(); ++masterIndex)
          {
            if(sliderList.at(depIndex)->isDependentOf(sliderList.at(masterIndex)))
              {
                sliderList.at(depIndex)->setDependency(sliderList.at(masterIndex));
              }
          }
      }
}
