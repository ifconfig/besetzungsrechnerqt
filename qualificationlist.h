#ifndef QUALIFICATIONLIST_H
#define QUALIFICATIONLIST_H

#include <QList>
#include <QJsonArray>
#include <QJsonValue>
#include <QHash>
#include "qualification.h"


class QualificationList
{
public:
  QualificationList(QJsonArray qualificationsArray);
  QHash <QString, QSharedPointer<Qualification> >  getHashList();

  QHash<QString, int >* qualificationPercentages();

private:
  QHash <QString, QSharedPointer<Qualification> > m_qualificationHash;
  QHash <QString, int> m_qualificationPercentages;
  void getAndSetDependencies();
};

#endif // QUALIFICATIONLIST_H
