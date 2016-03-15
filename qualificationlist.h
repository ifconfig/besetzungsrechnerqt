#ifndef QUALIFICATIONLIST_H
#define QUALIFICATIONLIST_H

#include <QList>
#include <QJsonArray>
#include <QJsonValue>
#include "qualification.h"


class QualificationList
{
public:
  QualificationList(QJsonArray qualificationsArray);
  QList <QSharedPointer<Qualification> >  getList();

private:
  QList <QSharedPointer<Qualification> > m_qualifications;
  void getAndSetDependencies();
};

#endif // QUALIFICATIONLIST_H
