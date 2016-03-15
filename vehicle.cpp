#include "vehicle.h"

Vehicle::Vehicle(QJsonObject vehicleObj)
{
    m_name = vehicleObj["name"].toString();
    m_numberSeats = 0;
    foreach(QJsonValue seat, vehicleObj["seats"].toArray())
    {
        QJsonObject seatObj = seat.toObject();
        m_numberSeats += seatObj["number"].toInt();
    }
}

QString Vehicle::name() const
{
    return m_name;
}

int Vehicle::numberSeats() const
{
    return m_numberSeats;
}
