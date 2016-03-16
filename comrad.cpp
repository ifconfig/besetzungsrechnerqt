#include "comrad.h"

Comrad::Comrad()
{

}

void Comrad::setQualification(QSharedPointer<Qualification> quali)
{
  m_qualifications.insert(quali->qualiShortName(), quali);
}
