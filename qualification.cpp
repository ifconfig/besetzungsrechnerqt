#include "qualification.h"

Qualification::Qualification()
{

}

Qualification::Qualification(QJsonObject qualiObj)
{
  m_qualiName = qualiObj["name"].toString();
  m_qualiShortName = qualiObj["short"].toString();
  m_depShortName = qualiObj["dependency"].toString();
  m_qualiID = 0;

  if(qualiObj["default_value"].toInt())
    {
      m_defaultValue = qualiObj["default_value"].toInt();
    }else{
      m_defaultValue = 0;
    }
}

QString Qualification::qualiName() const
{
  return m_qualiName;
}

QString Qualification::qualiShortName() const
{
  return m_qualiShortName;
}

int Qualification::defaultValue() const
{
  return m_defaultValue;
}

void Qualification::setDependency(const QSharedPointer<Qualification> &dependency)
{
  m_dependency = dependency;
}

QString Qualification::depShortName() const
{
  return m_depShortName;
}

QHash<QString, QSharedPointer<Qualification> > Qualification::getDependecyFrom() const
{
  return m_dependecyFrom;
}

void Qualification::addDependencyFrom(QSharedPointer<Qualification> dependentQualification)
{
  m_dependecyFrom.insert(dependentQualification->qualiShortName(), dependentQualification);
}


