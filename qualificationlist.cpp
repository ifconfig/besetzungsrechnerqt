#include "qualificationlist.h"

QualificationList::QualificationList(QJsonArray qualificationsArray)
{
  foreach(const QJsonValue & qualification, qualificationsArray){
      QJsonObject qualiObj = qualification.toObject();
      auto newQuali = QSharedPointer<Qualification>(new Qualification(qualiObj));
      m_qualifications.append(newQuali);
    }
  getAndSetDependencies();
}

QList <QSharedPointer<Qualification> >  QualificationList::getList()
{
  return m_qualifications;
}

void QualificationList::getAndSetDependencies()
{
  foreach (auto firstQuali, m_qualifications)
    {
      foreach (auto secondQuali, m_qualifications)
        {
          if(secondQuali->hasDependencyShortName(firstQuali->qualiShortName())){
              secondQuali->appendDependency(firstQuali);
            }
        }
    }
}


