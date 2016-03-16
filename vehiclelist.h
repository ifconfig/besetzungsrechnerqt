#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include <QList>
#include <QJsonArray>
#include <QJsonValue>
#include <QHash>
#include "vehicle.h"

class VehicleList
{
public:
    VehicleList(QJsonArray vehiclesArray);

    QHash<QString, QSharedPointer<Vehicle> > vehicles() const;

    QHash<QString, int>* vehicleNumber();

private:
    QHash<QString, QSharedPointer<Vehicle> > m_vehicles;
    QHash<QString, int> m_vehicleNumber;
};

#endif // VEHICLELIST_H
