#include "vehiclespinboxwidget.h"

VehicleSpinBoxWidget::VehicleSpinBoxWidget(QSharedPointer<Vehicle> vehicle, QWidget *parent) : QWidget(parent)
{
    setLayout(new QHBoxLayout());
    QSpinBox* vehicleSpinBox = new QSpinBox(this);
    vehicleSpinBox->setRange(0,10000);
    layout()->addWidget(vehicleSpinBox);

    QString vehicleName = vehicle->name();
    vehicleName.append(" ("+QString::number(vehicle->numberSeats())+")");
    QLabel* vehicleNameLabel = new QLabel(vehicleName, this);
    layout()->addWidget(vehicleNameLabel);

    QSpacerItem* spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout()->addItem(spacer);
}
