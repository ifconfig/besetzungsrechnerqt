#ifndef VEHICLE_H
#define VEHICLE_H

#include <QList>
#include "qualification.h"

class Vehicle
{
public:
  Vehicle();
private:
  QList<Qualification> m_positions;
};

#endif // VEHICLE_H
