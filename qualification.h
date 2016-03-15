#ifndef POSITION_H
#define POSITION_H

#include <QString>
#include <QList>
#include <QJsonObject>
#include <QJsonArray>
#include <QSharedPointer>

class Qualification
{
public:
  Qualification();
  Qualification(QJsonObject qualiObj);
  QString qualiName() const;

  QString qualiShortName() const;
  bool isDependencyOf(Qualification* other);
  void appendDepShortName(QString depShortName);
  bool hasDependencyShortName(QString shortName);
  void appendDependency(QSharedPointer<Qualification> dependency);

  QList<QString> depShortNames() const;

  QList <QSharedPointer<Qualification> > dependencies() const;

  int defaultValue() const;

private:
  QString m_qualiName;
  QString m_qualiShortName;
  QList <QSharedPointer<Qualification> > m_dependencies;
  QList <QString> m_depShortNames;
  int m_qualiID;
  int m_number;
  int m_defaultValue;

};

#endif // POSITION_H
