#ifndef VEHICLESPINBOXWIDGET_H
#define VEHICLESPINBOXWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QLabel>
#include <QSpacerItem>
#include "vehicle.h"

class VehicleSpinBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VehicleSpinBoxWidget(QSharedPointer<Vehicle> vehicle, QWidget *parent = 0);

  QSharedPointer<Vehicle> vehicle() const;

  QSpinBox *vehicleSpinBox() const;

signals:

public slots:
private:
  QSpinBox* m_vehicleSpinBox;
  QSharedPointer<Vehicle> m_vehicle;
};

#endif // VEHICLESPINBOXWIDGET_H
