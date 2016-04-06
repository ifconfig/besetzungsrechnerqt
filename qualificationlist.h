#ifndef QUALIFICATIONLIST_H
#define QUALIFICATIONLIST_H

#include <QList>
#include <QJsonArray>
#include <QJsonValue>
#include <QHash>
#include "qualification.h"

/**
 * List of all qualifications
 * @brief The QualificationList class
 * @author Georg Heyne
 * @date 06.04.2016
 */
class QualificationList
{
public:
  QualificationList(QJsonArray qualificationsArray);

  /**
   * @brief Return the list of qualifications
   * @return List of the qualifications
   */
  QHash <QString, QSharedPointer<Qualification> >  getHashList();

  /**
   * @brief qualificationPercentages
   * @return
   */
  QHash<QString, int >* qualificationPercentages();

private:
  /**
   * @brief List of all qualifications
   */
  QHash <QString, QSharedPointer<Qualification> > m_qualificationHash;

  /**
   * @brief List of the percentages stored in the
   */
  QHash <QString, int> m_qualificationPercentages;

  /**
   * reads the QString with the dependency short name, writes the dependency pointer to the qualification and writes the qualification pointerto the dependency
   *
   * @brief sets the Pointer of all dependencies (makes the tree)
   */
  void getAndSetDependencies();
};

#endif // QUALIFICATIONLIST_H
