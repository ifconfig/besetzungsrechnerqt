#include "vehiclespinboxwidget.h"

VehicleSpinBoxWidget::VehicleSpinBoxWidget(QSharedPointer<Vehicle> vehicle, QWidget *parent) : QWidget(parent)
{
  m_vehicle = vehicle;

    setLayout(new QHBoxLayout());
    m_vehicleSpinBox = new QSpinBox(this);
    m_vehicleSpinBox->setRange(0,10000);
    layout()->addWidget(m_vehicleSpinBox);

    QString vehicleName = vehicle->name();
    vehicleName.append(" ("+QString::number(vehicle->numberSeats())+")");
    QLabel* vehicleNameLabel = new QLabel(vehicleName, this);
    layout()->addWidget(vehicleNameLabel);

    QSpacerItem* spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout()->addItem(spacer);
}

QSharedPointer<Vehicle> VehicleSpinBoxWidget::vehicle() const
{
    return m_vehicle;
}

QSpinBox *VehicleSpinBoxWidget::vehicleSpinBox() const
{
  return m_vehicleSpinBox;
}
