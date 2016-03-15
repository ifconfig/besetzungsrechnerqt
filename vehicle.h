#ifndef VEHICLE_H
#define VEHICLE_H

#include <QList>
#include <QJsonObject>
#include "qualification.h"

class Vehicle
{
public:
  Vehicle(QJsonObject vehicleObj);
  QString name() const;

  int numberSeats() const;

private:
  QList<QSharedPointer<Qualification> > m_positions;
  QString m_name;
  int m_numberSeats;
};

#endif // VEHICLE_H
