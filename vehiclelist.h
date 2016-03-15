#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include <QList>
#include <QJsonArray>
#include <QJsonValue>
#include "vehicle.h"

class VehicleList
{
public:
    VehicleList(QJsonArray vehiclesArray);

    QList<QSharedPointer<Vehicle> > vehicles() const;

private:
    QList <QSharedPointer<Vehicle> > m_vehicles;
};

#endif // VEHICLELIST_H
