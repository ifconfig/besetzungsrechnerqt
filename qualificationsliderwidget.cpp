#include "qualificationsliderwidget.h"

QualificationSliderWidget::QualificationSliderWidget(QWidget *parent) : QWidget(parent)
{

}

QualificationSliderWidget::QualificationSliderWidget(QSharedPointer<Qualification> quali, QWidget *parent) : QWidget(parent)
{
  m_qualification = quali;

  setLayout(new QVBoxLayout());
  QString qualiName = quali->qualiName();
  if(quali->depShortNames().size() > 0)
    {
      qualiName.append(" (");
      foreach(const QString shortname, quali->depShortNames())
        {
          qualiName.append(shortname);
          qualiName.append(",");
        }
      qualiName.remove(qualiName.length()-1,1);
      qualiName.append(")");
    }
  m_qualificationNameLabel = new QLabel(qualiName, this);
  layout()->addWidget(m_qualificationNameLabel);

  QWidget* sliderWithPercentArea = new QWidget(this);
  sliderWithPercentArea->setLayout(new QHBoxLayout);

   m_qualificationSlider = new QSlider(sliderWithPercentArea);
   m_qualificationSlider->setRange(0,100);
   m_qualificationSlider->setOrientation(Qt::Horizontal);
   m_qualificationSlider->setMinimumWidth(250);
   m_qualificationSlider->setValue(quali->defaultValue());
   connect(m_qualificationSlider, SIGNAL(sliderMoved(int)), this, SLOT(sliderValueChanged(int)));
   sliderWithPercentArea->layout()->addWidget(m_qualificationSlider);

   m_qualificationSliderPercentage = new QLabel(QString::number(m_qualificationSlider->value()).append(" %"), sliderWithPercentArea);
   sliderWithPercentArea->layout()->addWidget(m_qualificationSliderPercentage);

   layout()->addWidget(sliderWithPercentArea);
}

QList <QSharedPointer<Qualification> >  QualificationSliderWidget::dependencies()
{
  return m_qualification->dependencies();
}

bool QualificationSliderWidget::isDependentOf(const QualificationSliderWidget *masterWidget)
{
  if(this == masterWidget)
    {
      return false;
    }
  for(int i=0; i<m_qualification->dependencies().size(); ++i)
    {
      QSharedPointer<Qualification> dependency = m_qualification->dependencies().at(i);
      if(dependency == masterWidget->qualification())
        {
          return true;
        }
    }
  return false;
}

void QualificationSliderWidget::setDependency(QualificationSliderWidget *masterWidget)
{
  m_dependencyWidgets.append(masterWidget);
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

void QualificationSliderWidget::sliderValueChanged(int value)
{
  int maxValue = 100;
  foreach(QualificationSliderWidget* dependency, m_dependencyWidgets)
    {
      if(dependency->qualificationSlider()->value() < maxValue)
        {
          maxValue = dependency->qualificationSlider()->value();
        }
    }

  if(value > maxValue)
    {
      m_qualificationSlider->setValue(maxValue);
      value = maxValue;
    }
  m_qualificationSliderPercentage->setText(QString::number(value).append(" %"));
  emit dependencyValueChanged(value);
}

QSlider *QualificationSliderWidget::qualificationSlider() const
{
  return m_qualificationSlider;
}

QSharedPointer<Qualification> QualificationSliderWidget::qualification() const
{
  return m_qualification;
}
