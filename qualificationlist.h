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

private:
  QHash <QString, QSharedPointer<Qualification> > m_qualificationHash;

  void getAndSetDependencies();
};

#endif // QUALIFICATIONLIST_H
