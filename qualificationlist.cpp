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

QHash<QString, int>* QualificationList::qualificationPercentages()
{
  return &m_qualificationPercentages;
}

void QualificationList::getAndSetDependencies()
{
  foreach (auto quali, m_qualificationHash)
    {
      if(quali->depShortName().size() > 0)
        {
          quali->setDependency(m_qualificationHash[quali->depShortName()]);
          m_qualificationHash[quali->depShortName()]->addDependencyFrom(quali);
        }
    }
}


