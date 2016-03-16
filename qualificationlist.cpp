#include "qualificationlist.h"

QualificationList::QualificationList(QJsonArray qualificationsArray)
{
  foreach(const QJsonValue & qualification, qualificationsArray){
      QJsonObject qualiObj = qualification.toObject();
      QSharedPointer<Qualification> newQuali = QSharedPointer<Qualification>(new Qualification(qualiObj));
      m_qualificationHash.insert(newQuali->qualiShortName(), newQuali);
    }
  getAndSetDependencies();
}

QHash <QString, QSharedPointer<Qualification> >  QualificationList::getHashList()
{
  return m_qualificationHash;
}

void QualificationList::getAndSetDependencies()
{
  foreach (auto quali, m_qualificationHash)
    {
      foreach(auto dependency, quali->dependencies())
        {
          quali->appendDependency(m_qualificationHash[dependency->qualiShortName()]);
        }
    }
}


