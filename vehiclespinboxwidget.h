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

signals:

public slots:
};

#endif // VEHICLESPINBOXWIDGET_H
