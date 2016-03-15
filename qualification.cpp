#include "qualification.h"

Qualification::Qualification()
{

}

Qualification::Qualification(QJsonObject qualiObj)
{
  m_qualiName = qualiObj["name"].toString();
  m_qualiShortName = qualiObj["short"].toString();
  foreach(const QJsonValue shortName, qualiObj["dependencies"].toArray())
    {
      m_depShortNames.append(shortName.toString());
    }
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

bool Qualification::isDependencyOf(Qualification *other)
{
  if(other->qualiShortName() == m_qualiShortName)
    {
      return true;
    }else
    {
      return false;
    }
}

void Qualification::appendDepShortName(QString depShortName)
{
  m_depShortNames.append(depShortName);
}

bool Qualification::hasDependencyShortName(QString shortName)
{
  // Return false because its, the same Qualification
  if(m_qualiShortName == shortName) return false;

  foreach (const QString depShortName, m_depShortNames) {
      if(depShortName == shortName) return true;
    }
  return false;
}

void Qualification::appendDependency(QSharedPointer<Qualification> dependency)
{
  m_dependencies.append(dependency);
}

QList<QString> Qualification::depShortNames() const
{
  return m_depShortNames;
}

QList <QSharedPointer<Qualification> > Qualification::dependencies() const
{
  return m_dependencies;
}

int Qualification::defaultValue() const
{
  return m_defaultValue;
}


