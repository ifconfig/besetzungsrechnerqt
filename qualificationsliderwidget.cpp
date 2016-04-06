#include "qualificationsliderwidget.h"

QualificationSliderWidget::QualificationSliderWidget(QWidget *parent) : QWidget(parent)
{

}

QualificationSliderWidget::QualificationSliderWidget(QSharedPointer<Qualification> quali, QWidget *parent) : QWidget(parent)
{
  m_qualification = quali;
  setLayout(new QVBoxLayout());
  QString qualiName = quali->qualiName();
  m_qualificationNameLabel = new QLabel(qualiName, this);
  layout()->addWidget(m_qualificationNameLabel);



  QWidget* sliderWithPercentArea = new QWidget(this);
  sliderWithPercentArea->setLayout(new QHBoxLayout);

   m_qualificationSlider = new QSlider(sliderWithPercentArea);
   m_qualificationSlider->setRange(0,100);
   m_qualificationSlider->setOrientation(Qt::Horizontal);
   m_qualificationSlider->setMinimumWidth(250);
   m_qualificationSlider->setValue(quali->defaultValue());
   //connect(m_qualificationSlider, SIGNAL(sliderMoved(int)), this, SLOT(sliderValueChanged(int)));
   sliderWithPercentArea->layout()->addWidget(m_qualificationSlider);

   m_qualificationSliderPercentage = new QLabel(QString::number(m_qualificationSlider->value()).append(" %"), sliderWithPercentArea);
   sliderWithPercentArea->layout()->addWidget(m_qualificationSliderPercentage);

   layout()->addWidget(sliderWithPercentArea);

}

/*
void QualificationSliderWidget::setDependency(QualificationSliderWidget *masterWidget)
{
  connect(masterWidget, SIGNAL(dependencyValueChanged(int)), this, SLOT(setDependentValue(int)));
}


void QualificationSliderWidget::setDependentValue(int value)
{
  if(value < m_qualificationSlider->value())
    {
      m_qualificationSlider->setValue(value);
      m_qualificationSliderPercentage->setText(QString::number(value).append(" %"));
    }
}
*/

void QualificationSliderWidget::sliderValueChanged(int value)
{
  m_qualificationSliderPercentage->setText(QString::number(value).append(" %"));
  //emit dependencyValueChanged(value);
}

QSlider *QualificationSliderWidget::qualificationSlider() const
{
  return m_qualificationSlider;
}

QSharedPointer<Qualification> QualificationSliderWidget::qualification() const
{
  return m_qualification;
}
