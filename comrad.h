#ifndef COMRAD_H
#define COMRAD_H

#include <QHash>
#include <QSharedPointer>

#include "qualification.h"

class Comrad
{
public:
  Comrad();
  void setQualification(QSharedPointer<Qualification> quali);
private:
  //int m_id;

  // qualifications
  QHash <QString, QSharedPointer<Qualification> > m_qualifications;

  // emergency case attributes
  //int m_arrivalTime;
  //int m_readdiness;

  // setting algorithm neccessary
  //int m_cost;
  //int m_weight;
};

#endif // COMRAD_H
