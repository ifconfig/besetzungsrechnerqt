#include "vehiclelist.h"

VehicleList::VehicleList(QJsonArray vehiclesArray)
{
    foreach (QJsonValue vehicleValue, vehiclesArray) {
        QSharedPointer<Vehicle> newVehicle = QSharedPointer<Vehicle>(new Vehicle(vehicleValue.toObject()));
        m_vehicles.insert(newVehicle->name(), newVehicle);
    }
}

QHash<QString, QSharedPointer<Vehicle> > VehicleList::vehicles() const
{
    return m_vehicles;
}

QHash<QString, int>* VehicleList::vehicleNumber()
{
  return &m_vehicleNumber;
}
