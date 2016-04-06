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
  bool hasDependencyShortName(QString shortName);

  int defaultValue() const;

  void setDependency(const QSharedPointer<Qualification> &dependency);

  QString depShortName() const;

  QHash<QString, QSharedPointer<Qualification> > getDependecyFrom() const;
  void addDependencyFrom(QSharedPointer<Qualification> dependentQualification);

private:
  QString m_qualiName;
  QString m_qualiShortName;
  QSharedPointer<Qualification> m_dependency;
  QHash<QString, QSharedPointer<Qualification> > m_dependecyFrom;
  QString m_depShortName;
  int m_qualiID;
  int m_number;
  int m_defaultValue;

};

#endif // POSITION_H
