#include "vehiclelist.h"

VehicleList::VehicleList(QJsonArray vehiclesArray)
{
    foreach (QJsonValue vehicleValue, vehiclesArray) {
        auto newVehicle = QSharedPointer<Vehicle>(new Vehicle(vehicleValue.toObject()));
        m_vehicles.append(newVehicle);
    }
}

QList<QSharedPointer<Vehicle> > VehicleList::vehicles() const
{
    return m_vehicles;
}
